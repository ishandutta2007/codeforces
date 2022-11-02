#include <bits/stdc++.h>

const int max_N=1e5;

//indexed from 1
template<size_t size>
struct Kmp{
	int fail[size];
	template<typename T>
	inline void get_fail(T S,int len){
		fail[1]=0;
		for(int i=2,j;i<=len;++i){
			for(j=fail[i-1];j&&S[j+1]!=S[i];j=fail[j]);
			fail[i]= S[j+1]==S[i]?++j:0;
		}
	}
	template<typename T>
	inline void matching(T A,int lenA,T B,int lenB,int*right){
		get_fail(B,lenB);
		for(int i=1,j=0;i<=lenA;++i){
			while(j&&A[i]!=B[j+1])j=fail[j];
			if(A[i]==B[j+1])++j;
			if(!right[j])right[j]=lenA-i+j;
			if(j==lenB)return;
		}

	}
};

//indexed from 1
template<size_t size>
struct Manacher{
	//type:ODD 1,EVEN 0
	//define the center of even string as the left one
	int r[2][size];
	template<typename T>
	inline void build(T S,int len,int type){
		register int i,j,k;
		int*R=r[type];
		for(i=1,j=0;i<=len;i+=k,j=std::max(0,j-k)){
			while(i-j>0&&i+j+type<=len&&S[i-j]==S[i+j+type])++j;
			R[i]=j;
			for(k=1;k<j&&R[i-k]!=R[i]-k;++k){
				R[i+k]=R[i-k]<R[i]-k?R[i-k]:R[i]-k;
			}
		}
	}
};

Manacher<max_N+21>manacher;

template<size_t size,size_t size_log>
struct SparseTable{
	int max[size][size_log],bit[size];
	inline int slt(int x,int y){
		return manacher.r[0][x]>manacher.r[0][y]?x:y;
	}
	inline void init(int n){
		for(int i=2;i<=n;++i)bit[i]=bit[i>>1]+1;
		for(int i=1;i<=n;++i)max[i][0]=i;
		for(int j=1;j<=bit[n];++j){
			for(int i=1;i+(1<<j)-1<=n;++i){
				max[i][j]=slt(max[i][j-1],max[i+(1<<(j-1))][j-1]);
			}
		}
	}
	inline int rmq(int l,int r){
		int i=bit[r-l+1];
		return slt(max[l][i],max[r-(1<<i)+1][i]);
	}
};

char str[max_N+21],tmp[max_N+21];

int n,right[max_N+21];

Kmp<max_N+21>kmp;

SparseTable<max_N+21,17>st;

int ans;

std::vector<std::pair<int,int>>vec;

inline int query(int L,int R){
	int l=1,r=R-L+1;
	r=(r&1)?(r+1)/2:r/2;
	int ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		int tmp=st.rmq(L+mid-1,R-mid+1);
		if(manacher.r[0][tmp]>=mid){
			ans=tmp;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}

inline void solve(){
	int x=st.rmq(1,n);
	ans=manacher.r[0][x]*2-1;
	vec.push_back({x-manacher.r[0][x]+1,x+manacher.r[0][x]-1});
	//printf("%d %d\n",x,ans);
	for(int i=1;i<=n;++i){
		if(right[i]<=2*i)continue;	
		int middle=query(i+1,right[i]-i);
		int R=manacher.r[0][middle];
		R=std::min(R,std::min(middle-i,right[i]-i-middle+1));
		int ml=middle-R+1,mr=middle+R-1;
		int len=i*2+(mr-ml+1);
		if(len>ans){
			ans=len;
			vec.clear();	
			vec.push_back({right[i]-i+1,right[i]});
			vec.push_back({ml,mr});
			vec.push_back({1,i});
		}
	}
}

int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	strcpy(tmp+1,str+1);
	std::reverse(str+1,str+1+n);
	kmp.matching(tmp,n,str,n,right);
	for(int i=1;i<=n;++i)if(!right[i])right[i]=i;
	manacher.build(str,n,0);
	manacher.build(str,n,1);
	st.init(n);
	solve();
	printf("%d\n",(int)vec.size());
	for(auto&x:vec)printf("%d %d\n",n-x.second+1,x.second-x.first+1);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
int n,k,a[N];
int b[N];

vector<int> v;
int id(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int bit[N];
void add(int pos,int x){
	while(pos<N){
		bit[pos]=max(bit[pos],x);
		pos+=pos&(-pos);
	}
}
void clear(int pos){
	while(pos<N){
		bit[pos]=0;
		pos+=pos&(-pos);
	}	
}
int query(int pos){
	int ans=0;
	while(pos>0){
		ans=max(ans,bit[pos]);
		pos-=pos&(-pos);
	}
	return ans;
}
int dp[N];
int solve(vector<int> vec) {
	v.clear();
	for(auto x:vec)v.push_back(x);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int ans=0;
	//printf("!! ");
	//for(auto x:vec) printf("%d ", x); printf("\n");
	//memset(bit,0,sizeof(bit));
	for(int i=0;i<vec.size();i++){
		int pos=id(vec[i]);
		//printf("pos=%d, que=%d\n", pos,query(pos));
		dp[i]=query(pos)+1;
		//printf("add %d %d\n", pos,dp[i]);
		add(pos,dp[i]);
		ans=max(ans,dp[i]);
	}
	for(int i=0;i<vec.size();i++){
		int pos=id(vec[i]);
		clear(pos);
	}
	//printf("# ans=%d\n", ans);
	return ans;

}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); a[i]-=i;
	}

	for(int i=1;i<=k;i++)scanf("%d",&b[i]);
	b[0]=0,b[k+1]=n+1;
	a[0]=-1e9,a[n+1]=1e9+1;
	for(int i=1;i<k;i++)
		if(a[b[i]]>a[b[i+1]])return !printf("-1\n");
	int ans=0;
	for(int i=0;i<=k;i++){
		int l=b[i]+1,r=b[i+1]-1;
		int L=a[b[i]], R=a[b[i+1]];
		vector<int> vec;
		//printf("l=%d,r=%d,L=%d,R=%d\n", l,r,L,R);
		//printf("ans=%d\n", ans);
		for(int x=l;x<=r;x++){
			//printf("%d ",a[x]);
			if(a[x]<L || a[x]>R) ans++;
			else vec.push_back(a[x]);
		}
	//	printf("\n");
		//printf("ans=%d\n",ans );
		ans+=vec.size()-solve(vec);
		//printf("ans=%d\n", ans);
	}
	printf("%d\n", ans);
}
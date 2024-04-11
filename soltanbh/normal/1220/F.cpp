#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=8e5+99;

int n,t,a[N],A[N],B[N],h1[N],h2[N],hr[N],hl[N],pos[N],seg[N],lz[N];
vector<int> lb,rb,ls,rs;

int big(int x,int y){
	return x>=y;
}
int small(int x,int y){
	return x<=y;
}
void upd(int id){
	seg[id]=max(seg[id<<1],seg[id<<1|1]);
}
void shift(int id){
	seg[id<<1]+=lz[id];
	seg[id<<1|1]+=lz[id];
	lz[id<<1]+=lz[id];
	lz[id<<1|1]+=lz[id];
	lz[id]=0;
}
void build(int id=1,int l=1,int r=n+1){
	if(l+1==r){
		seg[id]=h1[l]+h2[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid,r);
	upd(id);
}
void add(int L,int R,int val,int id=1,int l=1,int r=n+1){
	if(r<=L || R<=l) return ;
	if(L<=l && r<=R){
		lz[id]+=val;
		seg[id]+=val;
		return ;
	}
	int mid=(l+r)>>1;
	shift(id);
	add(L,R,val,id<<1,l,mid);
	add(L,R,val,id<<1|1,mid,r);
	seg[id]=max(seg[id<<1],seg[id<<1|1]);
}
void change(int x,int val,int id=1,int l=1,int r=n+1){
	if(r<=x || x<l) return ;
	if(l+1==r){
		seg[id]=val;
		return ;
	}
	int mid=(l+r)>>1;
	shift(id);
	change(x,val,id<<1,l,mid);
	change(x,val,id<<1|1,mid,r);
	upd(id);
}
int get(int L,int R,int id=1,int l=1,int r=n+1){
	if(r<=L || R<=l) return 0;
	if(L<=l && r<=R){
		return seg[id];
	}
	int mid=(l+r)>>1;
	shift(id);
	return max(get(L,R,id<<1,l,mid),get(L,R,id<<1|1,mid,r));
}
void Add(int l,int r,int val){
	if(l==r) return ;
	if(l<r) add(l,r,val);
	else{
		add(r,l,-val);
		add(1,n+1,val);
	}
}
vector<int> P(function<int(int, int)> func){
	vector<int> res(n+1);
	f(i,1,2*n+1){
		A[i]=i-1;
		while(A[i]>0 && func(a[A[i]],a[i])==0){
			A[i]=A[A[i]];
		}
	}
	f(i,n+1,n+n+1){
		res[i-n]=(A[i]-1)%n+1;
	}
	return res;
}
vector<int> T(function<int(int, int)> func){
	vector<int> res(n+1);
	f_(i,2*n,1){
		A[i]=i+1;
		while(A[i]<=2*n && func(a[A[i]],a[i])==0){
			A[i]=A[A[i]];
		}
	}
	f(i,1,n+1){
		res[i]=(A[i]-1)%n+1;
	}
	return res;
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1) cin>>a[i],a[i+n]=a[i],pos[a[i]]=i;
	lb=P(big);
	ls=P(small);
	rb=T(big);
	rs=T(small);
	f(i,1,n+1){
		h1[i]=0;
		if(ls[i]<i) h1[i]=h1[ls[i]]+1;
	}
	f_(i,n,1){
		h2[i]=0;
		if(i<rs[i]) h2[i]=h2[rs[i]]+1;
	}
	f(id,2,n+1){
		int i=pos[id];
		hl[i]=hl[ls[i]]+1;
		hr[i]=hr[rs[i]]+1;
	}
	build();
	//f(i,1,n+1) cout<<get(i,i+1)<<" "; cout<<endl;
	int shift=0,ans=seg[1];
	f(i,1,n+1){
		change(i,hl[i]);
		Add(i+1,rs[i],-1);
		Add(ls[i]+1,i,+1);
		if(seg[1]<ans){
			shift=i;
			ans=seg[1];
		}
		//f(i,1,n+1) cout<<get(i,i+1)<<" "; cout<<endl;
	}
	cout<<ans+1<<" "<<shift;
}
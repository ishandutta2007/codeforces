#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=3e6+99,inf=1e15;

int n,t,prt,a[N],sum[N],seg[2][N],lazy[N];
ll ans;
vector<pair<int,int> > v[N];
map<int,int> mark;

void shift(int id,int l,int r);

int merge(int u,int v,int s){
	if(s==0) return max(u,v);
	return min(u,v);
}
void build(int id=1,int l=0,int r=n){
	lazy[id]=0;
	if(l+1==r){
		if(l&1){
			seg[0][id]=-inf;
			seg[1][id]=0;
		}
		else{
			seg[0][id]=0;
			seg[1][id]=inf;
		}
		return ;
	}
	int mid=(l+r)/2;
	build(id*2+0,l,mid);
	build(id*2+1,mid,r);
	f(i,0,2){
		seg[i][id]=merge(seg[i][id*2+0],seg[i][id*2+1],i);
	}
}
void add(int L,int R,int val,int id=1,int l=0,int r=n){
	prt++;
   if(r<=L || R<=l) return ;
   if(L<=l && r<=R){
      lazy[id]+=val;
      f(i,0,2){
      	if(l+1!=r || (l&1)==(i&1)){
      		seg[i][id]+=val;
			}
   	}
      return ;   
   }
   int mid=(l+r)/2;
   shift(id,l,r);
   add(L,R,val,id*2+0,l,mid);
   add(L,R,val,id*2+1,mid,r);
   f(i,0,2){
   	seg[i][id]=merge(seg[i][id*2+0],seg[i][id*2+1],i);
	}
}
int Get(int L,int R,int s,int id=1,int l=0,int r=n){
	//cout<<id<<" "<<l<<" "<<r<<endl;
   if(r<=L || R<=l){
		return n;
	}
   if(L<=l && r<=R){
      if(s==0){
   		if(seg[0][id]<=0) return n;
		}
   	else{
			if(seg[1][id]>=0) return n;
		}
		if(l+1==r){
			return r;
		}
   }
   shift(id,l,r);
   int mid=(l+r)>>1;
   int res=Get(L,R,s,id*2+0,l,mid);
   if(res<n) return res;
	return Get(L,R,s,id*2+1,mid,r);
}
void shift(int id,int l,int r){
	int mid=(l+r)/2;
	add(l,mid,lazy[id],id*2+0,l,mid);
	add(mid,r,lazy[id],id*2+1,mid,r);
   lazy[id]=0;
}
void Add(int l,int r,int x){
	if(l>0) v[l-1].pb(mp(x,-1));
	v[r].pb(mp(x,1));
}
void Main(){
	ans=0;
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		if(i&1) sum[i]=a[i];
		else sum[i]=-a[i];
		if(i) sum[i]+=sum[i-1];
	}
	build();
	f_(i,n-1,0){
		if(i&1){
			add(i,n,a[i]);
		}
		else{
			add(i,n,-a[i]);
		}
		int mv=0;
		int l=min(Get(i,n,0),Get(i,n,1));
		if(i>0) mv=sum[i-1];
		Add(i,l-1,mv);
	}
	mark.clear();
	f(i,0,n){
		mark[sum[i]]++;
		f(j,0,v[i].size()){
			ans+=mark[v[i][j].F]*v[i][j].S;
		}
	}
	cout<<ans<<'\n';
	f(i,0,n+9) v[i].clear();	
}

main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}
/*
1
8
1 2 1 2 1 2 1 2
*/
#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99,mod=1e9+7;

int n,t,q,a[N],ps[N],vis[N],mark[N],Ft[N];
pair<pair<int,int> ,int> b[N];

int Fen[N];
void update(int x,int val) { x++; while(x<N)  {  Add(Fen[x],val);  x+=(x&-x);  } }
int query(int x) { x++;  int res=0;  while(x>0)  {  Add(res,Fen[x]);  x-=(x&-x);  } return res; } 

void read(){
	cin>>n;
	f(i,1,n+1){
		int u,v;
		cin>>u>>v;
		b[i]=mp(mp(u,v),i);
		vis[v]=1;
	}
	f(i,1,2*n+1) vis[i]+=vis[i-1];
	sort(b+1,b+1+n);
	f(i,1,n+1){
		Ft[b[i].S]=i;
		a[i]=vis[b[i].F.S];
	}
	cin>>q;
	f(i,0,q){
		int u;
		cin>>u;
		u=Ft[u];
		mark[u]=1;
	}
	int mx=0;
	f_(i,n,1){
		if(mark[i]) maxm(mx,a[i]);
		if(a[i]<mx) mark[i]=1;
	}
}
void solve(){
	int ans=0,mn=n;
	fill(ps,ps+N,-1);
	f(i,1,n+1){
		if(mark[i]){
			int copy=mn;
			minm(mn,a[i]);
			ps[i+1]=mn-1;
			mn=copy;
		}
		else{
			minm(mn,a[i]);
		}
	}
	update(0,1);
	f_(i,n,1){
		update(a[i],query(a[i]));
		if(ps[i]!=-1) Add(ans,query(ps[i]));
	}
	cout<<ans+mark[n];
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	read();
	solve();
}
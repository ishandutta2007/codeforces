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
#define Add(x,y) x=(x+y)%mod
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

const int N=4020,mod=998244353;

int n,m,ans0=1,ans1=1,node,edge,cnt0,cnt1,cnt2,a[N][N],deg[N],vis[N];
vector<int> g[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

void dfs(int u){
	edge+=g[u].size();
	node++;
	vis[u]=1;
	if(deg[u]==0) cnt0++;
	for(auto v : g[u]){
		if(vis[v]) continue ;
		dfs(v);
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,1,n+1){
		f(j,1,m+1){
			char c;
			cin>>c;
			if(c=='0') a[i][j]=0;
			if(c=='1') a[i][j]=1,deg[i]^=1,deg[j+n]^=1;
			if(c=='?'){
				g[i].pb(n+j);
				g[n+j].pb(i);
				a[i][j]=2;
				edge++;
			}
			cnt2+=a[i][j]==2;
		}
	}
	if(n%2==0 && m%2==0){
		cout<<pow(2,cnt2,mod);
	}
	if(n%2==0 && m%2==1){	
		f(i,1,n+1){
			if(deg[i]==0 && g[i].size()==0) ans1=0;
			if(deg[i]==1 && g[i].size()==0) ans0=0;
			if(g[i].size()) edge--;
		}
		ans0=1ll*ans0*pow(2,edge,mod)%mod;
		ans1=1ll*ans1*pow(2,edge,mod)%mod;
		cout<<(ans0+ans1)%mod;
	}
	if(n%2==1 && m%2==0){
		f(i,n+1,n+m+1){
			if(deg[i]==0 && g[i].size()==0) ans1=0;
			if(deg[i]==1 && g[i].size()==0) ans0=0;
			if(g[i].size()) edge--;
		}
		ans0=1ll*ans0*pow(2,edge,mod)%mod;
		ans1=1ll*ans1*pow(2,edge,mod)%mod;
		cout<<(ans0+ans1)%mod;
	}
	if(n%2==1 && m%2==1){
		f(i,1,n+m+1){
			if(vis[i]==0){
				cnt0=node=0;
				edge=0;
				dfs(i);
				cnt1=node-cnt0;
				if(cnt0%2==1) ans0=0;
				if(cnt1%2==1) ans1=0;
				edge/=2;
				edge=edge-(node-1);
				ans0=1ll*ans0*pow(2,edge,mod)%mod;
				ans1=1ll*ans1*pow(2,edge,mod)%mod;
			}
		}	
		cout<<(ans0+ans1)%mod;
	}
}
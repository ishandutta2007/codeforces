#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
//#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N = 2e5+5;

vector<int>g[N];
int mn[N],d[N],vis[N];
int ans = 0;

void dfs(int u,int v){
	d[u]=d[v]+1;
	mn[u]=N;
	if(sz(g[u])==1 && u!=v){
		mn[u]=d[u];return;
	}
	for(auto i:g[u]){
		if(i!=v){
			dfs(i,u);
			mins(mn[u],mn[i]);
		}
	}
}

void dfs2(int u,int v){
	if(vis[u])return;
	vis[u]=1;
	for(auto i:g[u]){
		if(i!=v){
			assert(!vis[i]);
			maxs(ans,mn[i]-d[i]+2);
			dfs2(i,u);
		}
	}
}
int solve(){
	ans=1;
 	int n;cin>>n;d[1]=-1;
 	rep(i,1,n+1){
 		g[i].clear();vis[i]=0;
 	}
 	rep(i,0,n-1){
 		int a,b;cin>>a>>b;
 		g[a].pb(b);
 		g[b].pb(a);
 	}
 	dfs(1,1);
 	int c = 1;
 	vector<int>t;
 	for(auto i:g[1]){
 			dfs2(i,1);
 			t.pb(mn[i]);
 	}
 	sort(all(t));reverse(all(t));
 	maxs(ans,t[0]);
 	if(sz(t)>1){
 		if(t[0]==t[1])maxs(ans,t[0]+1);
 	}
 	cout<<ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
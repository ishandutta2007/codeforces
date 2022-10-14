#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


const int N = 2e5+5;


vector<int>g[N];


int solve(){
	int n,m;cin>>n>>m;
	rep(i,1,n+1){
		g[i].clear();
	} 
	rep(i,1,m+1){
		int a,b;cin>>a>>b;
		g[a].pb(b);
	}
	queue<int>q;vector<int>dis(n+1);
	q.push(1);vector<int>vis(n+1);
	while(!q.empty()){
		int v=q.front();q.pop();
		vis[v]=1;
		for(auto j:g[v]){
			if(!vis[j]){
				q.push(j);
				vis[j]=1;
				dis[j]=dis[v]+1;
			}
		}
	}

	vector<int>dp(n+1);
	rep(i,1,n+1)dp[i]=dis[i],vis[i]=0;
	function<void(int)>dfs=[&](int u){
		vis[u]=1;
		for(auto j:g[u]){
			if(!vis[j] && dis[j]>dis[u]){
				dfs(j);
			}
			if(dis[j]>dis[u])mins(dp[u],dp[j]);
			mins(dp[u],dis[j]);
		}
	};
	rep(i,1,n+1){
		if(!vis[i])dfs(i);
	}
	rep(i,1,n+1)cout<<dp[i]<<" ";cout<<endl;
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
// Jai Shree Ram  
  
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


int solve(){
 		int n,m; cin >> n >> m;
 		vector<vector<int>>g(n + 1),gt(n + 1);
 		rep(i,0,m){
 			int a,b; cin >> a >> b;
 			g[a].push_back(b);
 			g[b].push_back(a);
 		}
 		auto addEdge =  [&](int u,int v){
 			gt[u].push_back(v);
 			gt[v].push_back(u);
 		};
 		vector<int> vis(n + 1);
 		function<void(int)> dfs = [&](int u){
 			vis[u] = 1;
 			for(auto i:g[u]){
 				if(!vis[i]){
 					addEdge(i,u);
 					dfs(i);
 				}
 			}
 		};
 		dfs(1);
 		int v;
 		vector<int> temp;
 		function<int(int,int)> dfs2 = [&](int u,int p){
 			temp.push_back(u);
 			if(u == v){
 				return 1;
 			}
 			for(auto i:gt[u]){
 				if(i != p){
 					bool f = dfs2(i,u);
 					if(f == 1)return 1;
 				}
 			}
 			temp.pop_back();
 			return 0;
 		};

 		vector<pii> queries;
 		int q; cin >> q;
 		vector<int> deg(n + 1);
 		for(int i = 0; i < q; i++){
 			int u,v; cin >> u >> v;
 			deg[u] ^= 1;
 			deg[v] ^= 1;
 			queries.push_back({u,v});
 		}
 		int sum = 0;
 		for(auto i:deg){
 			sum += i;
 		}
 		if(sum){
 			cout << "NO" << endl;
 			cout << sum/2 << endl;
 			return 0;
 		}
 		cout << "YES" << endl;
 		for(auto i:queries){
 			v = i.y;
 			temp.clear();
 			dfs2(i.x,i.x);
 			cout << sz(temp) << endl;
 			for(auto i:temp)cout << i << " ";
 				cout << endl;
 		}

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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
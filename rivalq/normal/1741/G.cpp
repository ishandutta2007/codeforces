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

 		vector<vector<int>> g(n + 1);

 		for(int i = 0; i < m; i++){
 			int a,b; cin >> a >> b;
 			g[a].push_back(b);
 			g[b].push_back(a);
 		}

 		auto bfs = [&](int s){
 			vector<int> dis(n + 1);
 			vector<int> vis(n + 1);
 			queue<int> q;
 			q.push(s);
 			vis[s] = 1;
 			while(!q.empty()){
 				auto u = q.front();q.pop();
 				for(auto j:g[u]){
 					if(!vis[j]){
 						vis[j] = 1;
 						q.push(j);
 						dis[j] = dis[u] + 1;
 					}
 				}
 			}
 			return dis;
 		};
 		map<int,vector<int>> dis;
 		dis[1] = bfs(1);
 		int f; cin >> f;
 		vector<int> friends(f);
 		for(auto &i:friends) cin >> i;
 		int k; cin >> k;
 		vector<int> bad,isbad(f);
 		for(int i = 0; i < k; i++){
 			int j; cin >> j;
 			isbad[j - 1] = true;
 			bad.push_back(friends[j - 1]);
 			dis[friends[j - 1]] = bfs(friends[j - 1]);
 		}	
 		vector<int> dp(1 << k);
 		dp[0] = 1;

 		
 		auto check = [&](int u,int mask){
 			vector<pii> vec;
 			vec.push_back({dis[1][u],u});
 			for(int j = 0; j < k; j++){
 				if((1 << j) & mask){
 					int v = bad[j];
 					vec.push_back({dis[1][v],v});
 				}
 			}
 			sort(all(vec));

 			if(vec.back().y != u)return false;

 			for(int i = 1; i < vec.size(); i++){
 				int u = vec[i].y;
 				int v = vec[i - 1].y;
 				if(dis[1][u] != dis[1][v] + dis[v][u])return false;
 			}
 			return true;

 		};

 		for(int i = 0; i < f; i++){
 			if(isbad[i])continue;
 			vector<int> ndp(1 << k);
 			for(int mask = 0; mask < (1 << k); mask++){
 				ndp[mask] = dp[mask];
 				for(int s = mask; s ; s = (s - 1)&mask){
 					if(check(friends[i],s)){
 						ndp[mask] |= dp[mask ^ s];
 					}
 				}
 			}
 			swap(dp,ndp);
 		}
 		int ans = k;
 		for(int i = 0; i < (1 << k); i++){
 			if(dp[i]){
 				int p = __builtin_popcount(i);
 				mins(ans,k - p);
 			}
 		}
 		cout << ans << endl;

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
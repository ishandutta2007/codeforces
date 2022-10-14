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
 		vector<vector<pii>> g(n + 1);
 		map<pii,int> mp;
 		vector<vector<pii>>gt(n + 1);
 		for(int i = 2; i <= n; i++){
 			int u,v,d; cin >> u >> v >> d;
 			mp[{min(u,v),max(u,v)}] = d;
 			if(d != -1){
 				d = __builtin_popcount(d);
 				d %= 2;
 				gt[u].push_back({v,d});
 				gt[v].push_back({u,d});
 			}
 			g[u].push_back({v,d});
 			g[v].push_back({u,d});

 		}
 		vector<int> pre(n + 1);
 		vector<int> cnt(n + 1);
 		function<void(int,int)> dfs = [&](int u,int p){
 			for(auto i:g[u]){
 				if(i.x != p){
 					int w = i.y;
 					if(w >= 0)pre[i.x] ^= w;
 					if(w == -1)cnt[i.x]++;
 					cnt[i.x] += cnt[u];
 					pre[i.x] ^= pre[u];
 					dfs(i.x,u);
 				}
 			}
 		};
 		dfs(1,1);
 		for(int i = 1; i <= n; i++){
 			//cout << cnt[i] << " " << pre[i] << endl;
 		}

 		rep(i,0,m){
 			int u,v,d;cin >> u >> v >> d;
 			gt[u].push_back({v,d});
 			gt[v].push_back({u,d});
 		}

 		vector<int> vis(n + 1,-1);
 		vector<int> col(n + 1);
 		for(int i = 1; i <= n; i++){
 			if(vis[i] == -1){
 				vis[i] = 0;
 				queue<int> q;
 				q.push(i);
 				vector<vector<int>>comp(2);
 				while(!q.empty()){
 					auto u = q.front();q.pop();
 					comp[vis[u]].push_back(u);
 					for(auto j:gt[u]){
 						int v = j.x;
 						int w = j.y;
 						if(vis[v] != -1){
 							if(vis[v] != (w^vis[u])){
 								cout << "NO" << endl;
 								return 0;
 							}
 						}else{
 							vis[v] = (w^vis[u]);
 							q.push(v);
 						}
 					}
 				}
 				int cnt1 = 0,cnt2 = 0;
 				for(auto i:comp[0]){
 					if(cnt[i] == 0 and pre[i] != 0)cnt1++;
 				}
 				for(auto i:comp[1]){
 					if(cnt[i] == 0 and pre[i] == 0)cnt2++;
 				}
 				if(cnt1 > 0 and cnt2 > 0){
 					cout << "NO" << endl;
 					return 0;
 				}
 				if(cnt2 > 0)swap(comp[0],comp[1]);
 				//for(auto i:comp[0])cout << i << " ";cout << endl;
 				for(auto i:comp[0])col[i] = 0;
 				for(auto i:comp[1])col[i] = 1;
 			}
 		}
 		function<void(int,int)> dfs2 = [&](int u,int p){
 			for(auto i:g[u]){
 				if(i.x == p)continue;
 				int v = i.x;
 				int w = i.y;
 				pii p = {min(u,v),max(u,v)};
 				if(w == -1){
 					if(col[v] != pre[u]){
 						mp[p] = 1;
 					}else{
 						mp[p] = 0;
 					}
 				}
 				pre[v] = col[v];
 				dfs2(v,u);
 			}
 		};
 		pre[1] = col[1];
 		dfs2(1,1);
 		cout << "YES" << endl;
 		for(auto i:mp)cout << i << endl;

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
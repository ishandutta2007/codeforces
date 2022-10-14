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

const int MAX = 1e6 + 5;

vector<pair<int, int>> g[MAX];
int vis[MAX], c[MAX];
int tot = 0;
int ans[MAX];
int up_bom[MAX], down_bom[MAX];
int up_ruim[MAX], down_ruim[MAX];
 
void dfs(int i, int last=-1, int cc=0) {
	vis[i] = 2;
	c[i] = cc;
	for (auto [j, __] : g[i]) if (j != last) {
		if (!vis[j]) {
			dfs(j, i, !cc);
			up_ruim[i] += up_ruim[j];
			up_bom[i] += up_bom[j];
		} else if (vis[j] == 2) {
			if (c[i] == c[j]) {
				up_ruim[i]++, down_ruim[j]++;
				tot++;
			} else up_bom[i]++, down_bom[j]++;
		}
	}
	up_ruim[i] -= down_ruim[i];
	up_bom[i] -= down_bom[i];
	vis[i] = 1;
}
 
void dfs2(int i) {
	vis[i] = 1;
	for (auto [j, id] : g[i]) if (!vis[j]) {
		dfs2(j);
		if (!up_bom[j] and up_ruim[j] == tot) ans[id] = 1;
	}
}

string solve(int n,vector<pii> edges, int rem = -1){
	vector<vector<int>>g(n);
	for(int i = 0; i < edges.size(); i++){
		if(i == rem)continue;
		auto [a,b] = edges[i];
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> vis(n,-1);
	string ans(n,'0');
	for(int i = 0; i < n; i++){
		if(vis[i] == -1){
			vector<int> q = {i};
			vis[i] = 0;
			vector<vector<int>>comp(2);
			for(int j = 0; j < q.size(); j++){
				auto u = q[j];
				comp[vis[u]].push_back(u);
				for(auto j:g[u]){
					if(vis[j] == -1){
						vis[j] = 1 - vis[u];
						q.push_back(j); 
					}else{
						if(vis[j] == vis[u]){
							assert(0);
						}
					}
				}
			}
			if(rem >= 0){
				int cnt = 0;
				auto [a,b] = edges[rem];
				for(auto j:comp[0]){
					if(j == a)cnt++;
					if(j == b)cnt++;
				}
				if(cnt == 1){
					assert(0);
				}
				if(cnt == 2){
					for(auto j:comp[0])ans[j] = '1';
				}else{
					for(auto j:comp[1])ans[j] = '1';
				}
			}else{
				for(auto j:comp[0])ans[j] = '1';
			}
		}
	}
	return ans;
}

int solve(){
 		int n,m; cin >> n >> m;
 		tot = 0;
 		for(int i = 0; i <= m; i++){
 			g[i].clear();
 			vis[i] = 0;
 			c[i] = 0;
 			ans[i] = 0;
 			up_bom[i] = 0;
 			down_bom[i] = 0;
 			up_ruim[i] = 0;
 			down_ruim[i] = 0;
 		}

 		vector<pii> edges;
 		for(int i = 0; i < m; i++){
 			int a,b; cin >> a >> b;
 			a--;
 			b--;
 			g[a].push_back({b,i});
 			g[b].push_back({a,i});
 			edges.push_back({a,b});
 		}

 		for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
		if (tot == 0) {
			cout << "YES" << endl;
			cout << solve(n,edges) << endl;
			return 0;
		}
		if (tot == 1) {
			for (int i = 0; i < m; i++) {
				auto [a, b] = edges[i];
				if (c[a] == c[b]) {
					cout << "YES" << endl;
					cout << solve(n,edges,i) << endl;
					return 0;
				}
			}
		}
		for(int i = 0; i <= n; i++)vis[i] = 0;
		for (int i = 0; i < n; i++) if (!vis[i]) dfs2(i);
	 

		for (int i = 0; i < m; i++) {
			if(ans[i] == 1){
				cout << "YES" << endl;
				cout << solve(n,edges,i) << endl;
				return 0;
			}
		}
		cout << "NO" << endl;



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
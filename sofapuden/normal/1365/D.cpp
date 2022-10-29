#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 
 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd;
typedef vector<vi> vvi; 

typedef set<int> si;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound
#define ts to_string 

int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); }
str tb(int x) {str ans; int c = x; for(int i = log2(x); i >= 0; --i){if(pow(2,i) <= c){ ans += "1"; c-=pow(2,i); } else { ans += "0"; } } return ans;}
bool ispr(int x){if(x <= 1){return false;} for(int i = 2; i <= sqrt(x); ++i){ if(x%i == 0){ return false; } }return true; } 

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18;

void dfs(int x, int y, int &cn, vvi &vis, const vector<vector<char>> &grid, int n, int m){
	if(vis[x][y] == 1){
		return;
	}
	vis[x][y] = 1;
	if(x != 0){
		if(grid[x-1][y] == 'B'){
			return;
		}
	}
	if(x != n-1){
		if(grid[x+1][y] == 'B'){
			return;
		}
	}
	if(y != 0){
		if(grid[x][y-1] == 'B'){
			return;
		}
	}
	if(y != m-1){
		if(grid[x][y+1] == 'B'){
			return;
		}
	}
	if(grid[x][y] == 'G'){
		cn++;
	}
	if(x != 0){
		if(grid[x-1][y] != '#' && vis[x-1][y] != 1){
			dfs(x-1,y,cn,vis,grid,n,m);
		}
	}
	if(x != n-1){
		if(grid[x+1][y] != '#' && vis[x+1][y] != 1){
			dfs(x+1,y,cn,vis,grid,n,m);
		}
	}
	if(y != 0){
		if(grid[x][y-1] != '#' && vis[x][y-1] != 1){
			dfs(x,y-1,cn,vis,grid,n,m);
		}
	}
	if(y != m-1){
		if(grid[x][y+1] != '#' && vis[x][y+1] != 1){
			dfs(x,y+1,cn,vis,grid,n,m);
		}
	}
}
	


void solve(){
	int n, m; cin >> n >> m;
	vector<vector<char>> grid(n);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		str s; cin >> s;
		for(char c : s){
			grid[i].eb(c);
			if(c == 'G'){
				ans++;
			}
		}
	}
	int ans2 = 0;
	vvi vis(n,vi(m));
	dfs(n-1,m-1,ans2,vis, grid,n,m);
	if(ans > 0){
		if(grid[n-1][m-1] == '#'){
			cout << "No";
			return;
		}
	}
	if(grid[n-1][m-1] == 'B'){
		cout << "No";
		return;
	}
	cout << (ans == ans2 ? "Yes" : "No"); 
	

}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 1;
	if(isT){
		int t; cin >> t; while(t--){
			solve();
			cout << "\n";
		}
		return 0;
	}
	solve();
	cout << "\n";		
	return 0;
}
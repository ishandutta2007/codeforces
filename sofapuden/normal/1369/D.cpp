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
			
template <typename T = int>
class graph {
 public:
  struct edge {
    int from;
    int to;
    T cost;
  };
 
  vector<edge> edges;
  vector<vector<int>> g;
  int n;
 
  graph(int _n) : n(_n) {
    g.resize(n);
  }
 
  virtual int add(int from, int to, T cost) = 0;
};

template <typename T = int>
class forest : public graph<T> {
 public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
 
  forest(int _n) : graph<T>(_n) {
  }
 
  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }
};
 
template <typename T = int>
class dfs_forest : public forest<T> {
 public:
  using forest<T>::edges;
  using forest<T>::g;
  using forest<T>::n;
 
  vector<int> pv;
  vector<int> pe;
  vector<int> order;
  vector<int> pos;
  vector<int> end;
  vector<int> sz;
  vector<int> root;
  vector<int> depth;
  vector<T> dist;
 
  dfs_forest(int _n) : forest<T>(_n) {
  }
 
  void init() {
    pv = vector<int>(n, -1);
    pe = vector<int>(n, -1);
    order.clear();
    pos = vector<int>(n, -1);
    end = vector<int>(n, -1);
    sz = vector<int>(n, 0);
    root = vector<int>(n, -1);
    depth = vector<int>(n, -1);
    dist = vector<T>(n);
  }
 
  void clear() {
    pv.clear();
    pe.clear();
    order.clear();
    pos.clear();
    end.clear();
    sz.clear();
    root.clear();
    depth.clear();
    dist.clear();
  }
 
 private:
  void do_dfs(int v) {
    pos[v] = (int) order.size();
    order.push_back(v);
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v]) {
        continue;
      }
      auto &e = edges[id];
      int to = e.from ^ e.to ^ v;
      depth[to] = depth[v] + 1;
      dist[to] = dist[v] + e.cost;
      pv[to] = v;
      pe[to] = id;
      root[to] = (root[v] != -1 ? root[v] : to);
      do_dfs(to);
      sz[v] += sz[to];
    }
    end[v] = (int) order.size() - 1;
  }
 
  void do_dfs_from(int v) {
    depth[v] = 0;
    dist[v] = T{};
    root[v] = v;
    pv[v] = pe[v] = -1;
    do_dfs(v);
  }
 
 public:
  void dfs(int v, bool clear_order = true) {
    if (pv.empty()) {
      init();
    } else {
      if (clear_order) {
        order.clear();
      }
    }
    do_dfs_from(v);
  }
 
  void dfs_all() {
    init();
    for (int v = 0; v < n; v++) {
      if (depth[v] == -1) {
        do_dfs_from(v);
      }
    }
    assert((int) order.size() == n);
  }
};	

template <typename T = int>
class board {
 public:
  struct tile {
    int x;
    int y;
    T cost;
  };
  
  vector<vector<tile>> g;
  vector<tile> order; 
  int n;
  int m;

  
  board(int _n,int  _m) : n(_n), m(_m) {
    g.resize(n,vector<tile>(m));
  }
   
  void validate(int x, int y, T cost = 1) {
    if(0 > x && x >= n && 0 > y && y >= n)return;
    g[x][y].x = x;
    g[x][y].y = y;
    g[x][y].cost = cost;
  }
  
  void invalidate(int x, int y){
	if(0 > x && x >= n && 0 > y && y >= n)return;
	g[x][y].x = -1;
	g[x][y].y = -1;
    g[x][y].cost = -1;
  }
  
};

template <typename T = int>
class all_dir_dfs_board : public board<T> {
 public:
  using board<T>::g; 
  using board<T>::order;
  using board<T>::n;
  using board<T>::m;

  vector<vector<int>> pos;
  int rooms = 0;
  
  all_dir_dfs_board(int _n, int _m) : board<T>(_n, _m) {
  }
  
  void init() {
    order.clear();
    pos = vector<vector<int>>(n, vector<int>(m,-1));
  }
  
  void clear() {
    order.clear();
    pos.clear();
    rooms = 0;
  }
 private:
  void do_dfs(int x, int y){
	if(x < 0 || y < 0 || x>= n || y >= m)return;
	if(g[x][y].x == -1 && g[x][y].y == -1)return;
	if(pos[x][y] != -1)return;
	int id = (int)order.size();
	order.emplace_back(board<int>::tile({x,y,1}));
	pos[x][y] = id;
	for(int d = -1; d < 2; d += 2) {
	  do_dfs(x+d,y);
	  do_dfs(x,y+d);
	}	    
  }
  void do_dfs_from(int x, int y){
	if(x < 0 || y < 0 || x>= n || y >= m)return;
	if(g[x][y].x == -1 && g[x][y].y == -1)return;
	if(pos[x][y] != -1)return;	  
	rooms++;
	int id = (int)order.size();
	order.emplace_back(board<int>::tile({x,y,1}));
	pos[x][y] = id;
	for(int d = -1; d < 2; d += 2) {
	  do_dfs(x+d,y);
	  do_dfs(x,y+d);
	}
  }
  public:
   void dfs(int x, int y, bool clear_order = true) {
    init();
    if (clear_order) {
	  order.clear();
    }
    do_dfs_from(x,y);
  }
  void dfs_all() {
    init();
    for (int d = 0; d < n; ++d) {
	  for(int h = 0; h < m; ++h) {  
		  if (pos[d][h] == -1) {
			do_dfs_from(d,h);
		  }
	  }
    }
  }
  
};
  
  

const int MOD = 1e9+7; // 998244353;
const int MX = 2e6+5; 
const ll INF = 1e18;

vl dp(MX,0);


void solve(){
	ll n; cin >> n;
	if(dp[3] != 4){
		dp[1] = 0;
		dp[2] = 0;
		dp[3] = 4;
		for(ll i = 4; i <= MX-2; ++i){
			dp[i] = dp[i-1]+2*dp[i-2];
			dp[i] %= MOD;
		}
		for(int i = 4; i <= MX-2; ++i){
			dp[i]+=dp[i-3];
			dp[i]%=MOD;
		}
	}
	cout << dp[n];
			
			
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
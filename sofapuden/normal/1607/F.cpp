#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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

#define vt vector
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
#define EACH(x, a) for (auto& x: a)

template<class T> void read(T &x){ cin >> x; }
template<class A> void read(vt<A> &v){ EACH(x, v) read(x); }
template<class H, class... T> void read(H& h, T& ...t){ read(h); read(t...); }

str to_string(const char* c){ return (str)c; }
str to_string(char c){ return (str)""+c; }
str to_string(str s){ return s; }
str to_string(bool b){ return b?"True" : "False"; }
template<class A> str to_string(vt<A> v){ str s; EACH(x, v) s+= to_string(x) + " "; return s; }
template<class H, class... T> str to_string(H& h, T& ...t){ str s; s+=to_string(h); s+=" "; s+=to_string(t...); return s; }
void print(str s){ cout << s << "\n"; }
template<class... A> void print(A ...a){ print(to_string(a...)); }


int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); }
str tb(int x) {str ans; int c = x; for(int i = log2(x); i >= 0; --i){if(pow(2,i) <= c){ ans += "1"; c-=pow(2,i); } else { ans += "0"; } } return ans;}
bool ispr(int x){if(x <= 1){return false;} for(int i = 2; i <= sqrt(x); ++i){ if(x%i == 0){ return false; } }return true; } 
			
const int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
const char dz[4] = {'R','L','D','U'};
// const int dx[8] = {0,1,1,1,0,-1,-1,-1}, dy[8] = {1,1,0,-1,-1,-1,0,1};
const int MOD = 998244353;
const int MX = 2e3+5; 
const ll INF = 1e18;

//tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> T;


vector<vector<int>> vis(MX, vector<int> (MX));
vector<vector<int>> mem(MX, vector<int> (MX));
vector<string> gr(MX);
int n, m;

int dfs(int x, int y, int cn){
	if(x < 0 || y < 0 || x >= n || y >= m)return 0;
	if(mem[x][y])return mem[x][y];
	if(vis[x][y]){
		mem[x][y] = cn-vis[x][y];
		return mem[x][y]-1;
	}
	vis[x][y] = cn;
	int z;
	for(int i = 0; i < 4; ++i){
		if(dz[i] == gr[x][y]){
			z = dfs(x+dx[i],y+dy[i],cn+1)+1;
			if(mem[x][y])return mem[x][y];
			mem[x][y] = z;
			if(x+dx[i] < 0 || y+dy[i] < 0 || x+dx[i] >= n || y+dy[i] >= m)return z;
			if(z == mem[x+dx[i]][y+dy[i]])return z-1;
			return z;
		}
	}
	assert(false);
	return -1;
}

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; ++i)for(int j = 0; j < m; ++j)vis[i][j] = 0;
	for(int i = 0; i < n; ++i)for(int j = 0; j < m; ++j)mem[i][j] = 0;
	for(int i = 0; i < n; ++i)cin >> gr[i];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(!vis[i][j])dfs(i,j,1);
		}
	}
	int mx = 0;
	int inx = 0, iny = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(mem[i][j] > mx){
				mx = mem[i][j];
				inx = i;
				iny = j;
			}
		}
	}
	cout << inx + 1 << ' ' << iny + 1 << ' ' << mx << '\n';

}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 1;
	if(isT){
		int t; cin >> t; while(t--){
			solve();
		}
		return 0;
	}
	solve();		
	return 0;
}
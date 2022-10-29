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
			
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18;

//tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

vector<map<int,int>> sub;
vector<int> vis;

void fil(int x, int p, vector<vector<int>> &gr, vector<int> &good){
	if(vis[x])return;
	vis[x] = 1;
	good[x] = 0;
	for(auto y : gr[x]){
		if(y == p)continue;
		fil(y,x,gr,good);
	}
}


int dfs(int x, int p, map<int,int> &M, vector<int> &v, vector<vector<int>> &gr, vector<int> &good){
	if(M[v[x]]>=2)good[x]=0;
	int cn = 0, ind = -1;
	for(auto y : gr[x]){
		if(y == p)continue;
		if(!dfs(y,x,M,v,gr,good) || sub[y][v[x]]){
			cn++;
			ind = y;
		}
		if(sub[x].size()<sub[y].size())swap(sub[x],sub[y]);
	}
	if(cn >= 2){cout << 0 << "\n";exit(0);}
	if(cn == 1){
		good[x]=0;
		for(auto y : gr[x]){
			if(y == p || y == ind)continue;
			fil(y,x,gr,good);
		}
		for(auto y : gr[x]){
			if(y == p)continue;
			for(auto z : sub[y]){
				sub[x][z.first]+=z.second;
			}
		}
		if(!sub[x][v[x]] && M[v[x]]>=2){cout << 0 << "\n";exit(0);}
		if(sub[x][v[x]] && sub[x][v[x]]+1 != M[v[x]]){cout << 0 << "\n";exit(0);}
		return 0;
	}
	if(M[v[x]]>=2){
		for(auto y : gr[x]){
			if(y == p)continue;
			fil(y,x,gr,good);
		}
	}
	for(auto y : gr[x]){
		if(y == p)continue;
		for(auto z : sub[y]){
			sub[x][z.first]+=z.second;
		}
	}
	if(sub[x][v[x]] && sub[x][v[x]]+1 != M[v[x]]){cout << 0 << "\n";exit(0);}
	if(sub[x][v[x]]){
		return 0;
	}
	sub[x][v[x]]++;
	return 1;

}

void solve(){
	int n; cin >> n;
	vi v(n);read(v);
	vvi gr(n);
	for(int i = 0; i < n-1; ++i){
		int a, b; cin >> a >> b;a--, b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	vi good(n,1);
	map<int,int> M;
	for(int i = 0; i < n; ++i){
		M[v[i]]++;
	}
	sub.resize(n);
	vis.resize(n,0);
	dfs(0,0,M,v,gr,good);
	int ans = accumulate(all(good),0);
	cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 0;
	if(isT){
		int t; cin >> t; while(t--){
			solve();
		}
		return 0;
	}
	solve();		
	return 0;
}
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
const int MX = 2e6+5; 
const ll INF = 1e18;

//tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

vector<vector<int>> tr, par;
vector<int> dis, add, st, ord;
int n, m;

void fin(int x, int p, int cn = 0){
	par[x][0] = p;
	ord[x] = cn;
	for(auto y : tr[x]){
		if(y == p)continue;
		fin(y,x,cn+1);
	}
}

void build(){
	dis.clear();
	dis.resize(n,-1);
	add.clear();
	queue<pair<int,int>> Q;
	for(int i = 0; i < n; ++i)
		if(st[i])Q.push({i,0});
	while(Q.size()){
		auto x = Q.front();
		Q.pop();
		if(dis[x.f] != -1)continue;
		dis[x.f] = x.s;
		for(auto y : tr[x.f])
			Q.push({y,x.s+1});
	}
}

int dist(int a, int b){
	if(ord[a] < ord[b])swap(a,b);
	int dif = ord[a]-ord[b];
	int ret = ord[a]+ord[b];
	for(int i = 0; i < 30; ++i){
		if(dif&1){
			a=par[a][i];
		}
		dif>>=1;
	}
	for(int i = 29; i >= 0; --i){
		if(par[a][i] != par[b][i]){
			a = par[a][i];
			b = par[b][i];
		}
	}
	if(a != b){
		a = par[a][0];
		b = par[b][0];
	}
	ret-=2*ord[a];
	return ret;
}

void solve(){
	cin >> n >> m;
	tr.resize(n);
	st.resize(n,0);
	ord.resize(n,0);
	st[0] = 1;
	par.resize(n,vector<int>(30));
	for(int i = 0, a, b; i < n-1; ++i){
		cin >> a >> b, a--, b--;
		tr[a].push_back(b);
		tr[b].push_back(a);
	}
	fin(0,0);	
	for(int i = 1; i < 30; ++i){
		for(int j = 0; j < n; ++j){
			par[j][i] = par[ par[j][i-1] ][i-1];
		}
	}
	int k = sqrt(m);
	for(int i = 0; i < m; ++i){
		if(!(i%k)){
			build();
		}
		int a, b; cin >> a >> b;
		b--;
		if(a == 1){
			add.push_back(b);
			st[b]=1;
		}
		else{
			int mn = dis[b];
			for(auto x : add){
				mn = min(mn, dist(x,b));
			}
			cout << mn << '\n';
		}
	}
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
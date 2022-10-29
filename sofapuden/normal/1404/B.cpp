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

int ans = 0;
vvi tree;

int dfs(int x, int p, int d){
	int best = 0;
	int best2 = 0;
	for(int i = 0; i < sz(tree[x]); ++i){
		if(tree[x][i] == p)continue;
		int cur = dfs(tree[x][i], x, d+1);
		if(best < cur)swap(cur, best);
		if(best2 < cur)swap(cur, best2);
	}
	ans = max({ans, best+best2-2*d, d});
	return max(d, best);
}
int dfs2(int a, int b, int p, int cn){
	if(a == b)return cn;
	int x;
	for(int i = 0; i < sz(tree[a]); ++i){
		if(tree[a][i] != p){
			x = dfs2(tree[a][i],b,a,cn+1);
			if(x)return x;
		}
	}
	return 0;
}
 
 
void solve(){
	int n, a, b, da, dbb; read(n,a,b,da,dbb);
	a--;b--;
	tree.resize(n);
	for(int i = 1; i < n; ++i){
		int tm1, tm2; cin >> tm1 >> tm2; tm1--; tm2--;
		tree[tm1].pb(tm2);
		tree[tm2].pb(tm1);
	}
	if(dfs2(a,b,-1,0) <= da){print("Alice");return;}
	if(da*2 >= dbb){print("Alice");return;}
	dfs(0, 0, 0);
	if((ans+1)/2 <= da){print("Alice");return;}
	print("Bob");

}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 1;
	if(isT){
		int t; cin >> t; while(t--){
			ans = 0;
			tree.clear();
			solve();
		}
		return 0;
	}
	solve();		
	return 0;
}
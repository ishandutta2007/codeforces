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

void solve(){
	int n, m, k, q; cin >> n >> m >> k >> q;
	vector<vector<ll>> tre(n);
	ll lastre = 0;
	for(int i = 0; i < k; ++i){
		ll a, b; cin >> a >> b;
		lastre = max(lastre,a);
		tre[a-1].pb(b);
	}
	vector<int> go(q); read(go);
	sort(all(go));
	queue<array<ll,2>> Q;
	if(sz(tre[0]))Q.push({1,0});
	else Q.push({go[0],go[0]-1});
	for(int i = 0; i < lastre; ++i){
		if(tre[i].empty()){
			for(int j = 0; j < sz(Q); ++j){
				auto x = Q.front();
				Q.pop();
				Q.push({x[0],x[1]+1});
			}
			continue;
		}
		sort(all(tre[i]));
		pl fi = {-1,LONG_LONG_MAX}, se = {-1,LONG_LONG_MAX}, th = {-1,LONG_LONG_MAX}, fo = {-1,LONG_LONG_MAX};
		
		if(prev(upper_bound(all(go),tre[i][0])) != prev(go.begin()))
			fi.f = *prev(upper_bound(all(go),tre[i][0]));
		if(upper_bound(all(go),tre[i][0]) != go.end())
			se.f = *upper_bound(all(go),tre[i][0]);
		if(prev(upper_bound(all(go),tre[i][sz(tre[i])-1])) != prev(go.begin()))
			th.f = *prev(upper_bound(all(go),tre[i][sz(tre[i])-1]));
		if(upper_bound(all(go),tre[i][sz(tre[i])-1]) != go.end())
			fo.f = *upper_bound(all(go),tre[i][sz(tre[i])-1]);
		
		if(fi.f != -1){
			for(int j = 0; j < sz(Q); ++j){
				auto x = Q.front();
				Q.pop();
				ll dis = x[1]+1;
				dis+=abs(x[0]-tre[i][sz(tre[i])-1]);
				dis+=abs(tre[i][sz(tre[i])-1]-tre[i][0]);
				if(i+1 != lastre)dis+=abs(tre[i][0]-fi.f);
				fi.s = min(fi.s,dis);
				Q.push(x);
			}
		}
		if(se.f != -1){
			for(int j = 0; j < sz(Q); ++j){
				auto x = Q.front();
				Q.pop();
				ll dis = x[1]+1;
				dis+=abs(x[0]-tre[i][sz(tre[i])-1]);
				dis+=abs(tre[i][sz(tre[i])-1]-tre[i][0]);
				if(i+1 != lastre)dis+=abs(tre[i][0]-se.f);
				se.s = min(se.s,dis);
				Q.push(x);
			}
		}
		if(th.f != -1){
			for(int j = 0; j < sz(Q); ++j){
				auto x = Q.front();
				Q.pop();
				ll dis = x[1]+1;
				dis+=abs(x[0]-tre[i][0]);
				dis+=abs(tre[i][sz(tre[i])-1]-tre[i][0]);				
				if(i+1 != lastre)dis+=abs(tre[i][sz(tre[i])-1]-th.f);
				th.s = min(th.s,dis);
				Q.push(x);
			}
		}
		if(fo.f != -1){
			for(int j = 0; j < sz(Q); ++j){
				auto x = Q.front();
				Q.pop();
				ll dis = x[1]+1;
				dis+=abs(x[0]-tre[i][0]);
				dis+=abs(tre[i][sz(tre[i])-1]-tre[i][0]);
				if(i+1 != lastre)dis+=abs(tre[i][sz(tre[i])-1]-fo.f);
				fo.s = min(fo.s,dis);
				Q.push(x);
			}
		}
		while(sz(Q)){
			Q.pop();
		}
		if(fi.f!=-1){
			Q.push({fi.f,fi.s});
		}
		if(se.f!=-1){
			Q.push({se.f,se.s});
		}
		if(th.f!=-1){
			Q.push({th.f,th.s});
		}
		if(fo.f!=-1){
			Q.push({fo.f,fo.s});
		}
		
	}
	ll bes = LONG_LONG_MAX;
	while(sz(Q)){
		auto x = Q.front();
		bes = min(bes,x[1]-1);
		Q.pop();
	}
	cout << bes << "\n";	
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
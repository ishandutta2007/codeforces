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


vl a, b;
vpi state;

int assi(int ind){
	if(state[ind].f != -1){
		return state[ind].f;
	}
	if(b[ind] == -1){
		state[ind] = {1, ind};
		return 1;
	}
	state[ind].s = ind;
	state[ind].f = assi(b[ind]) + 1;
	return state[ind].f;
} 
	

void solve(){
	int n; cin >> n;
	a.resize(n);
	b.resize(n);
	state.resize(n, {-1, -1});
	ll ans = 0;
	vl ans2;
	vl neg; 
	for(ll &i : a)cin >> i;
	for(ll &i : b){ cin >> i; i--; }
	for(int i = 0; i < n; ++i){
		assi(i);
	}
	sort(rall(state));
	for(int i = 0; i < n; ++i){
		if(a[state[i].s] > 0){
			ans2.pb(state[i].s);
			a[b[state[i].s]] += a[state[i].s];
			ans+=a[state[i].s];
		}
		else{
			neg.pb(state[i].s);
		}
	}
	reverse(all(neg));
	for(int i = 0; i < sz(neg); ++i){
		ans+=a[neg[i]];
		ans2.pb(neg[i]);
	}
	cout << ans << "\n";
	for(int i : ans2)cout << i+1 << " ";		
	
		

}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 0;
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
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
bool ispr(int x){ for(int i = 2; i <= x/2; ++i){ if(x%i == 0){ return false; } }return true; } 

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 

void solve(){
	int n; cin >> n;
	vi v(n); 
	for(int &i : v){
		cin >> i;
	}
	if(n == 1){
		cout << 0;
		return;
	}
	vi cop = v;
	sort(all(cop));
	int ma = cop[n-1];
	int lo = 0;
	int co = 0;
	vi ar(n);
	int S[16005] = {0};
	for(int i = 0; i < n; ++i){
		for(int j = lo; j <= i; ++j){
			ar[j]+=v[i];
			if(ar[j] >= ma){
				co = j+1;
			}
		}
		for(int j = lo; j < i; ++j){
			S[ar[j]] = 1;
		}
		lo = co;
	}
	int ans = 0;
	for(int i : v){
		if(S[i] == 1){
			ans++;
		}
	}
	cout << ans;
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
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
			
const int M = 51123987; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18;

//tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

void solve(){
	vector<int> pal;
	int n; cin >> n;
	string s; cin >> s;
	int pall = 0;
	int i = 0;
	while(i < n){
		if(i > pall && s[i-pall-1] == s[i]){
			pall+=2;
			i++;
			continue;
		}
		pal.pb(pall);
		bool ok = 1;
		int m = pal.size()-2;
		int z = m-pall;
		for(int j = m; j > z; --j){
			int d = j-z-1;
			if(pal[j] == d){
				pall = d;
				ok = 0;
				break;
			}
			pal.pb(min(d,pal[j]));
		}
		if(ok){
			pall = 1;
			i++;
		}
	}
	pal.pb(pall);
	int m = pal.size()-2;
	int z = m-(2*n+1-(m+2));
	for(int i = m; i > z; --i){
		int d = i-z-1;
		pal.pb(min(d,pal[i]));
	}
	vector<ll> st(n+5,0), en(n+5,0);
	for(int i = 1; i < (int)pal.size(); i+=2){
		int j = i/2;
		int x = pal[i]/2;
		st[j-x]++;
		st[j+1]--;
		en[j]--;
		en[j+x+1]++;
	}
	for(int i = 0; i < (int)pal.size(); i+=2){
		int j = i/2;
		if(pal[i] == 0)continue;
		int x = pal[i]/2;
		st[j-x]++;
		st[j]--;
		en[j]--;
		en[j+x]++;
	}

	ll cu = 0;
	ll cuadd = 0;
	ll curem = 0;
	ll an = 0;
	for(int i = 0; i < n; ++i){
		ll x = st[i], y = en[i];
		cuadd += x;
		curem += y;
		an+=cu*cuadd;
		an+=(cuadd*(cuadd-1))/2;
		cu+=cuadd+curem;
		an%=M;
	}
	cout << an << '\n';
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
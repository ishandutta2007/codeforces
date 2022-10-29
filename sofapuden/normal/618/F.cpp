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
	int n; cin >> n;
	vl v1(n), v2(n); read(v1,v2);
	bool ok = 0;
	ll asu = accumulate(all(v1),0ll); 
	ll bsu = accumulate(all(v2),0ll); 
	if(asu > bsu){
		swap(v1,v2);
		ok = 1;
	}
	vector<pair<ll,ll>> v;
	set<int> S;
	int ena = 0, enb = 0;
	int j = 0;
	ll sua = 0, sub = 0;
	for(int i = 0; i < n; ++i){
		sua+=v1[i];
		while(j < n && sub+v2[j] <= sua){
			sub+=v2[j++];
		}
		if(sua-sub == 0){
			if(ok){
				cout << j << '\n';
				for(int z = 0; z < j; ++z){
					cout << z+1 << ' ';
				}
				cout << '\n';
				cout << i+1 << '\n';
				for(int z = 0; z < i+1; ++z){
					cout << z+1 << ' ';
				}
				cout << '\n';
				return;
			}
			else{
				cout << i+1 << '\n';
				for(int z = 0; z < i+1; ++z){
					cout << z+1 << ' ';
				}
				cout << '\n';
				cout << j << '\n';
				for(int z = 0; z < j; ++z){
					cout << z+1 << ' ';
				}
				cout << '\n';
				return;
			}
		}
		if(S.count(sua-sub)){
			ena = i+1;
			enb = j;
			break;
		}
		v.pb({j,sua-sub});
		S.insert(sua-sub);
	}
	for(int i = 0; i < n; ++i){
		if(v[i].s == sua-sub){
			if(ok){
				cout << enb - v[i].f << '\n';
				for(int z = v[i].f; z < enb; ++z){
					cout << z+1 << ' ';
				}
				cout << '\n';
				cout << ena-i-1 << '\n';
				for(int z = i+1; z < ena; ++z){
					cout << z+1 << ' ';
				}
				cout << '\n';

			}
			else{
				cout << ena-i-1 << '\n';
				for(int z = i+1; z < ena; ++z){
					cout << z+1 << ' ';
				}
				cout << '\n';
				cout << enb - v[i].f << '\n';
				for(int z = v[i].f; z < enb; ++z){
					cout << z+1 << ' ';
				}
				cout << '\n';
			}
			return;

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
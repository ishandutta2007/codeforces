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
template<class A, class T> str to_string(pair<A,T> v){ str s = to_string(v.f)+ " " + to_string(v.s); return s;}
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

void solve(){
	ll m, n; cin >> m >> n;
	vector<pair<ll,ll>> v1(n);
	vector<pair<pair<ll,ll>,ll>> v2(2*n);
	for(int i = 0; i < n; ++i){
		read(v1[i].f,v1[i].s);
		v2[i*2]={{v1[i].f,0ll},i};
		v2[i*2+1]={{v1[i].s,1ll},i};
	}
	ll ans = 0;
	ll best = 0;
	ll cn = 0;
	vector<bool> ta(n,0);
	sort(rall(v2));
	for(int i = 0; i < n*2; ++i){
		if(!v2[i].f.s){
			ta[v2[i].s]=1;
			ans+=v2[i].f.f;
			cn++;
		}
		else{
			if(ta[v2[i].s]){
				best = max(best,ans+(m-cn)*v2[i].f.f);
			}
			else{
				best = max(best,ans+v1[v2[i].s].f+((m-cn-1)*v2[i].f.f));
			}
		}
		best = max(best,ans);
		if(cn == m)break;
	}
	print(best);
				
	
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
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

struct point{ int x; int y; };

template<class T> void read(T &x){ cin >> x; }
template<class A> void read(vt<A> &v){ EACH(x, v) read(x); }
template<class H, class... T> void read(H& h, T& ...t){ read(h); read(t...); }
template<>void read(point &x){ read(x.x,x.y); }

str to_string(const char* c){ return (str)c; }
str to_string(char c){ return (str)""+c; }
str to_string(str s){ return s; }
str to_string(bool b){ return b?"True" : "False"; }
str to_string(point p){ return to_string(p.x)+" "+to_string(p.y); }
template<class A> str to_string(vt<A> v){ str s; EACH(x, v) s+= to_string(x) + " "; return s; }
template<class H, class... T> str to_string(H& h, T& ...t){ str s; s+=to_string(h); s+=" "; s+=to_string(t...); return s; }
void print(str s){ cout << s << "\n"; }
template<class... A> void print(A ...a){ print(to_string(a...)); }

int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); }
str tb(int x) {str ans; int c = x; for(int i = log2(x); i >= 0; --i){if(pow(2,i) <= c){ ans += "1"; c-=pow(2,i); } else { ans += "0"; } } return ans;}
bool ispr(int x){if(x <= 1){return false;} for(int i = 2; i <= sqrt(x); ++i){ if(x%i == 0){ return false; } }return true; } 
			
const int MOD = 1e9+7; // 998244353;
const int MX = 4e4+5; 
const ll INF = 1e18;

bool ok = 1;

vi cj(MX,1);
vi pri;

void solve(){
	if(ok){
		for(ll i = 2; i < MX; ++i){
			if(cj[i]){
				pri.pb(i);
				for(ll j = i*i; j < MX; j+=i){
					cj[j] = 0;
				}
			}
		}
		ok = 0;
	}
	int n; cin >> n;
	vi fac;
	vi out;
	int x = n;
	for(int i = 0; i < sz(pri); ++i){
		while(!(x%pri[i])){
			x/=pri[i];
			fac.pb(pri[i]);
		}
		if(x == 1)break;
	}
	if(x != 1)fac.pb(x);
	if(ispr(n)){
		print(n);
		print(0);
		return;
	}
	if(sz(fac) == 2){
		if(fac[0] == fac[1]){
			print(fac[0],fac[0]*fac[0]);
			print(0);
		}
		else{
			print(fac[0],fac[0]*fac[1],fac[1]);
			print(1);
		}
		return;
	}
	si S;
	for(int i = 0; i < sz(fac); ++i){
		if(i && fac[i] == fac[i-1])continue;
		if(!S.count(fac[i])){out.pb(fac[i]);S.ins(fac[i]);}
		int start = sz(out);
		for(int j = sz(fac)-1; j > i; --j){
			int lll = sz(out);
			for(int k = start-1; k < lll; ++k){
				//if(i == 0 && j == sz(fac)-1 && start == lll)continue;
				if(!S.count(out[k]*fac[j])){out.pb(out[k]*fac[j]);S.ins(out[k]*fac[j]);}
			}
		}
	}
	out.pb(fac[0]*fac[sz(fac)-1]);
	for(int i = 0; i < sz(out); ++i){
		if(out[i] != out[sz(out)-1])cout << out[i] << " ";
	}
	cout << out[sz(out)-1] << "\n";
	print(0);
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
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
	vector<pl> p(4);
	vector<ll> X, Y;
	for(auto &x : p){cin >> x.f >> x.s;X.pb(x.f);Y.pb(x.s);}
	ll ans = 0;
	ll mnx = INF, mny = INF, mxx = -INF, mxy = -INF;
	for(int i = 0; i < 4; ++i){
		mnx = min(mnx, p[i].f);
		mny = min(mny, p[i].s);
		mxx = max(mxx, p[i].f);
		mxy = max(mxy, p[i].s);
	}
	ll h = mxx-mnx, w = mxy-mny;
	if(h < w){
		ll dif = w-h;
		sort(all(Y));
		if(Y[1]-Y[0] < dif){
			mny = Y[1];
			ans+=(Y[1]-Y[0]);
			dif-=(Y[1]-Y[0]);
		}
		else{
			mny = Y[0] + dif;
			ans+=dif;
			dif = 0;
		}
		if(Y[3]-Y[2] < dif){
			mxy = Y[2];
			ans+=(Y[3]-Y[2]);
			dif-=(Y[3]-Y[2]);
		}
		else{
			mxy = Y[3] - dif;
			ans+=dif;
			dif = 0;
		}
		if(dif){
			mny+=dif;
			ans+=2*dif;
			dif = 0;
		}
		for(int i = 0; i < 4; ++i){
			p[i].s = max(p[i].s, mny); 
			p[i].s = min(p[i].s, mxy); 
		}
	}
	else{
		ll dif = h-w;
		sort(all(X));
		if(X[1]-X[0] < dif){
			mnx = X[1];
			ans+=(X[1]-X[0]);
			dif-=(X[1]-X[0]);
		}
		else{
			mnx = X[0] + dif;
			ans+=dif;
			dif = 0;
		}
		if(X[3]-X[2] < dif){
			mxx = X[2];
			ans+=(X[3]-X[2]);
			dif-=(X[3]-X[2]);
		}
		else{
			mxx = X[3] - dif;
			ans+=dif;
			dif = 0;
		}
		if(dif){
			mnx+=dif;
			ans+=2*dif;
			dif = 0;
		}
		for(int i = 0; i < 4; ++i){
			p[i].f = max(p[i].f, mnx); 
			p[i].f = min(p[i].f, mxx); 
		}
	}
	str s = "1234";
	ll bes = INF;
	while(1){
		ll cur = 0;
		for(int i = 0; i < 4; ++i){
			if(s[i] == '1'){
				cur+= p[i].f-mnx;
				cur+= p[i].s-mny;
			}
			else if(s[i] == '2'){
				cur+=  mxx - p[i].f;
				cur+= p[i].s-mny;	
				}
			else if(s[i] == '3'){
				cur += p[i].f - mnx;
				cur += mxy - p[i].s;
			}
			else {
				cur += mxx - p[i].f;
				cur += mxy - p[i].s;
			}
		}
		bes = min(bes,cur);
		next_permutation(all(s));
		if(s == "1234")break;
	}
	cout << bes + ans << "\n";
			
				
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
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
const int MX = 2e5+5; 
const ll INF = 1e18;

vl v;
vpl Q;
ll n, q;

bool peak(ll ind){
	if(ind < 0 || ind >= n){
		return 0;
	}
	if(ind == 0){
		return v[ind] > v[ind+1];
	}
	if(ind == n-1){
		return v[ind] >= v[ind-1];
	}
	return v[ind] > v[ind+1] && v[ind] >= v[ind-1];
}
bool dep(ll ind){
	if(ind <= 0){
		return 0;
	}
	if(ind >= n-1){
		return 0;
	}
	return v[ind] < v[ind+1] && v[ind] <= v[ind-1];
}

void solve(){
	read(n,q);
	v.resize(n);read(v);
	Q.resize(q);
	for(auto &i : Q){
		cin >> i.f >> i.s;
	}
	if(n == 1){
		for(int i = 0; i < q+1; ++i){
			print(v[0]);
		}
		return;
	}
	ll ans = 0;
	bool ok = 0;
	ll last = 0;
	for(int i = 0; i < n; ++i){
		if(peak(i) && !ok){
			ans+=v[i];
			ok = 1;
		}
		else if(dep(i) && ok){
			ans-=v[i];
			last = v[i];
			ok = 0;
		}
	}
	if(!ok){
		ans+=last;
	}
	print(ans);
	for(int j = 0; j < q; ++j){
		ll a = Q[j].f, b = Q[j].s;a--;b--;
		if(a > b)swap(a,b);
		if(a == b){
		}
		else if(b-a <= 2){
			for(int i = a-1; i <= b+1; ++i){
				if(peak(i)){
					ans-=v[i];
				}
				if(dep(i)){
					ans+=v[i];
				}
			}
			swap(v[a],v[b]);
			for(int i = a-1; i <= b+1; ++i){
				if(peak(i)){
					ans+=v[i];
				}
				if(dep(i)){
					ans-=v[i];
				}
			}
		}
		else{
			for(int i = a-1; i <= a+1; ++i){
				if(peak(i)){
					ans-=v[i];
				}
				if(dep(i)){
					ans+=v[i];
				}
			}
			for(int i = b-1; i <= b+1; ++i){
				if(peak(i)){
					ans-=v[i];
				}
				if(dep(i)){
					ans+=v[i];
				}
			}
			swap(v[a],v[b]);
			for(int i = a-1; i <= a+1; ++i){
				if(peak(i)){
					ans+=v[i];
				}
				if(dep(i)){
					ans-=v[i];
				}
			}
			for(int i = b-1; i <= b+1; ++i){
				if(peak(i)){
					ans+=v[i];
				}
				if(dep(i)){
					ans-=v[i];
				}
			}
			
		}
		print(ans);
	}	
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
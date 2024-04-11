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

int comp(db x1, db y1, db x2, db y2){
	if(x1*y2 == y1*x2)return 2;
	if(x1*y2 < y1*x2)return 0;
	return 1;
}
	

void solve(){
	db n, l; cin >> n >> l;
	vd v(n); read(v);
	db lo = 0, hi = l, los = 1, his = 1;
	db ans = 0;
	int p1 = 0, p2 = n-1;
	while(p1 <= p2){
		db dis1 = (v[p1]-lo)/los;
		db dis2 = (hi-v[p2])/his;
		if(comp(los,v[p1]-lo,his,hi-v[p2]) == 2){
			ans+=dis1;
			los++;
			his++;
			hi = v[p2--];
			lo = v[p1++];
		}
		else if(comp(los,v[p1]-lo,his,hi-v[p2])){
			ans+=dis1;
			los++;
			hi -= dis1*his;
			lo = v[p1++];
		}
		else{
			ans+=dis2;
			his++;
			lo += dis2*los;
			hi = v[p2--];
		}
	}
	printf("%.9f\n", ans+(hi-lo)/(los+his));
	
	
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
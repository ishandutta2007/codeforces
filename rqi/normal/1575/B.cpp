#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for(auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
	return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
	return a < b ? a = b, 1 : 0;
}

tcT, class U> T fstTrue(T lo, T hi, U f){
	++hi; assert(lo <= hi);
	while(lo < hi){
		T mid = lo+(hi-lo)/2;
		f(mid) ? hi = mid : lo = mid+1;
	}
	return lo;
}

using T = db;
const T EPS = 1e-9;
using P = pair<T, T>; using vP = V<P>; using Line = pair<P, P>;
int sgn(T a){return (a > EPS)-(a<-EPS);}
T sq(T a){return a*a;}

T norm(P p){return sq(p.f)+sq(p.s);}
T abs(P p){ return sqrt(norm(p));}
T arg(P p){return atan2(p.s, p.f);}
P conj(P p){return P(p.f, -p.s);}
P perp(P p){return P(-p.s, p.f);}
P dir(T ang){return P(cos(ang), sin(ang));}


const int mx = 100005;

struct Eff{

int n, k;
P hab[mx];

bool works(db r){
	V<pair<db, int>> ch;
	for(int i = 1; i <= n; i++){
		if(abs(hab[i]) <= 2.0*r-EPS){
			db theta_diff = PI/2.0-asin(abs(hab[i])/2.0/r);
			db theta = arg(hab[i]);
			assert(theta_diff <= PI/2.0);

			ch.pb(mp(theta-theta_diff, +1));
			ch.pb(mp(theta+theta_diff, -1));

			ch.pb(mp(theta-theta_diff+2*PI, +1));
			ch.pb(mp(theta+theta_diff+2*PI, -1));
		}
	}

	sort(all(ch));

	int running_sum = 0;
	for(auto u: ch){
		running_sum+=u.s;
		if(0 <= u.f && u.f <= 2*PI){
			if(running_sum >= k) return true;
		}
	}

	return false;
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> hab[i].f >> hab[i].s;
	}

	db lo = EPS;
	db hi = 200005.0;
	for(int i = 0; i < 50; i++){
		db mid = (lo+hi)/2;
		if(works(mid)){
			hi = mid;
		}
		else{
			lo = mid;
		}
	}
	cout << lo << "\n";
}


};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout << fixed << setprecision(10);
	Eff e; e.solve();
}
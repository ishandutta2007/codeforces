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
#define eb emplace_back

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

const int mx = 505;
struct ACFixed{
	static const int ASZ = 2;
	struct node{AR<int, ASZ> to; int link;};
	V<node> d = {{}};
	int add(str s){
		int v = 0;
		each(C, s){
			int c = C-'0';
			if(!d[v].to[c]) d[v].to[c] = sz(d), d.eb();
			v = d[v].to[c];
		}
		return v;
	}
	void init(){
		d[0].link = -1;
		queue<int> q; q.push(0);
		while(sz(q)){
			int v = q.ft; q.pop();
			F0R(c, ASZ){
				int u = d[v].to[c]; if(!u) continue;
				d[u].link = d[v].link == -1 ? 0 : d[d[v].link].to[c];
				q.push(u);
			}
			if(v) F0R(c, ASZ) if(!d[v].to[c])
				d[v].to[c] = d[d[v].link].to[c];
		}
	}
};


const db EPS = 1e-9;

int choose(int n, int b){
	int res = 1;
	for(int i = 0; i < b; i++){
		res*=(n-i);
	}
	for(int i = 1; i <= b; i++){
		res/=i;
	}
	return res;
}

struct Eff{

int N;
db P;
void solve(){
	cin >> N >> P;
	for(int i = 0; i <= N; i++){
		db study_three = db(choose(i, 3)*choose(N-i, 0))/db(choose(N, 3));
		db study_two = db(choose(i, 2)*choose(N-i, 1))/db(choose(N, 3));
		db study_one = db(choose(i, 1)*choose(N-i, 2))/db(choose(N, 3));

		// cout << study_two << " " << study_one << "\n";
		db prob = study_one*1.0/2.0+study_two+study_three;

		if(prob >= P-EPS){
			cout << i << "\n";
			return;
		}
	}
}


};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout << fixed << setprecision(10);
	Eff e; e.solve();
}
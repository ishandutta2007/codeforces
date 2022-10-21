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



struct Eff{

ACFixed acf;
int m, n;
void solve(){
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	int bot_node = acf.add(b);
	acf.init();

	array<array<int, mx>, mx> dp, ndp;

	for(int i = 0; i < mx; i++){
		for(int j = 0; j < mx; j++){
			dp[i][j] = MOD;
		}
	}
	dp[0][0] = 0;

	for(auto u: a){
		for(int i = 0; i < mx; i++){
			for(int j = 0; j < mx; j++){
				ndp[i][j] = MOD;
			}
		}

		for(int i = 0; i < sz(acf.d); i++){
			for(int j = 0; j <= n-m+1; j++){
				for(int k = 0; k < 2; k++){
					int add_val = (k != (u-'0'));
					int new_node = acf.d[i].to[k];
					int add_occ = (new_node == bot_node);
					ckmin(ndp[new_node][j+add_occ], dp[i][j]+add_val);
				}
				
			}
		}
		

		swap(dp, ndp);
	}

	for(int j = 0; j <= n-m+1; j++){
		int ans = MOD;
		for(int i = 0; i < sz(acf.d); i++){
			ckmin(ans, dp[i][j]);
		}
		if(ans == MOD) ans = -1;
		cout << ans << " ";
	}
	cout << "\n";

	
}


};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout << fixed << setprecision(10);
	Eff e; e.solve();
}
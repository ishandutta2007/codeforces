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

struct mi{
	int v; explicit operator int() const {return v;}
	mi():v(0){}
	mi(ll _v):v(int(_v%MOD)){v+=(v<0)*MOD; }
};

mi& operator+=(mi& a, mi b){
	if((a.v+=b.v) >= MOD) a.v-=MOD;
	return a;
}

mi& operator-=(mi& a, mi b){
	if((a.v-=b.v) < 0) a.v+=MOD;
	return a;
}

mi operator+(mi a, mi b){
	return a+=b;
}
mi operator-(mi a, mi b){
	return a-=b;
}

mi operator*(mi a, mi b){
	return mi((ll)a.v*b.v);
}

mi& operator*=(mi& a, mi b){
	return a = a*b;
}

mi pow(mi a, ll p){
	assert(p >= 0);
	return p==0?1:pow(a*a,p/2)*(p&1?a:1);
}

mi inv(mi a){
	assert(a.v!=0); return pow(a, MOD-2);
}

mi operator/(mi a, mi b){
	return a*inv(b);
}

bool operator==(mi a, mi b){
	return a.v-=b.v;
}

typedef vector<mi> vmi;

const int mx = 200005;

// void ad(vi& a, int b){ckmin(b, sz(a)-1); if(b >= 0) a[b]++;}
// void prop(vi& a){R0F(i,sz(a)-1) a[i]+=a[i+1];}

template<int SZ> struct Centroid{
	vector<pair<int, bool>> adj_col[SZ];
	void ae(int A, int B, bool t){adj_col[A].pb(mp(B, t)), adj_col[B].pb(mp(A, t));}
	bool done[SZ];
	int N, sub[SZ];
	void dfs(int x, int p){
		sub[x] = 1;
		each(y, adj_col[x]) if(!done[y.f] && y.f != p)
			dfs(y.f,x), sub[x]+=sub[y.f];
	}
	int centroid(int x){
		dfs(x, -1);
		for(int sz = sub[x];;){
			pi mx2 = {0, 0};
			each(y, adj_col[x]) if(!done[y.f] && sub[y.f] < sub[x])
				ckmax(mx2, {sub[y.f], y.f});
			if(mx2.f*2 <= sz) return x;
			x = mx2.s;
		}
	}

	
	int K;
	mi a[mx];
	
	mi ans = mi(0);
	array<V<pair<mi, int>>, 2> cnt;

	void addCnt(int mult){
		mi res = 0;

		//res = cnt^2

		array<V<pair<mi, int>>, 2> cnt_csum;
		for(int j = 0; j < 2; j++){
			cnt_csum[j] = cnt[j];
			for(int i = 1; i < sz(cnt_csum[j]); i++){
				cnt_csum[j][i].f+=cnt_csum[j][i-1].f;
				cnt_csum[j][i].s+=cnt_csum[j][i-1].s;
			}
		}

		auto addUpto = [&](V<pair<mi, int>>& v, int d){
			if(sz(v) == 0) return mp(mi(0), 0);
			if(d < 0) return mp(mi(0), 0);
			if(d >= sz(v)){
				return v.bk;
			}
			return v[d];
		};

		for(int j = 0; j < 2; j++){
			for(int i = 0; i < sz(cnt_csum[j]); i++){
				for(int k = 0; k < 2; k++){
					int NEED = K-i;
					if(j != k){
						NEED--;
					}
					res+=cnt[j][i].f*mi(addUpto(cnt_csum[k], NEED).s);
					res+=cnt[j][i].s*mi(addUpto(cnt_csum[k], NEED).f);
				}
			}
		}
		ans+=res*mi(mult);
	}

	void genCnt(int node, int p, int cur_diffs, bool init_color, bool last_color, mi attract_sum){
		while(sz(cnt[init_color]) <= cur_diffs){
			cnt[init_color].pb(mp(mi(0), 0));
		}

		// cout << node << " " << cur_diffs << " " << (mi(2)*attract_sum).v << "\n";
		cnt[init_color][cur_diffs].f+=attract_sum;
		// cout << cnt[init_color][cur_diffs].f.v << "\n";
		cnt[init_color][cur_diffs].s++;

		each(u, adj_col[node]){
			if(!done[u.f] && u.f != p){
				if(u.s != last_color){
					genCnt(u.f, node, cur_diffs+1, init_color, u.s, attract_sum+a[u.f]);
				}
				else{
					genCnt(u.f, node, cur_diffs, init_color, u.s, attract_sum+a[u.f]);
				}
			}
		}
	}

	// void genDist(int x, int p, int lev){
	// 	dist[lev][x] = dist[lev][p]+1;
	// 	each(y, adj[x]) if(!done[y] && y!=p) genDist(y,x,lev);
	// }
	void gen(int CEN, int _x){
		int x = centroid(_x); done[x] = 1; //cen[x] = CEN;
		sub[x] = sub[_x]; //lev[x] = (CEN == -1 ? 0 : lev[CEN]+1);
		// dist[lev[x]][x] = 0;
		// stor[x].rsz(sub[x]), STOR[x].rsz(sub[x]+1);
		// each(y, adj[x]) if(!done[y]) genDist(y,x,lev[x]);
		
		// cout << "CENTROID: " << x << ", " << CEN << "\n";
		array<V<pair<mi, int>>, 2> tot_cnt;
		each(y, adj_col[x]){
			if(!done[y.f]){
				// cout << "y.f: " <<  y.f << "\n";
				cnt[0].clear();
				cnt[1].clear();
				genCnt(y.f, x, 0, y.s, y.s, a[x]*inv(mi(2))+a[y.f]);
				addCnt(-1);

				for(int j = 0; j < 2; j++){
					while(sz(cnt[j]) > sz(tot_cnt[j])){
						tot_cnt[j].pb(mp(mi(0), 0));
					}
					for(int i = 0; i < sz(cnt[j]); i++){
						tot_cnt[j][i].f+=cnt[j][i].f;
						// cout << "j, i: " << j << " " << i << " " << tot_cnt[j][i].f.v << "\n";
						tot_cnt[j][i].s+=cnt[j][i].s;
					}
				}

			}
		}

		swap(cnt, tot_cnt);

		
		// cout << mi(-ans.v).v << "\n";
		addCnt(1);

		// cout << ans.v << "\n";
		for(int j = 0; j < 2; j++){
			for(int i = 0; i < sz(cnt[j]); i++){
				if(i <= K){
					// cout << i << " " << j << " " << cnt[j][i].f.v << " " << cnt[j][i].s << "\n";
					ans+=mi(2)*(cnt[j][i].f+a[x]*inv(mi(2))*cnt[j][i].s);
				}
				
			}
		}

		// cout << ans.v << "\n";

		each(y, adj_col[x]) if(!done[y.f]) gen(x,y.f);
	}

	void init(int _N){
		N = _N; FOR(i,1,N+1) done[i] = 0;
		gen(-1, 1);
	}
	// void upd(int x, int y){
	// 	int cur = x, pre = -1;
	// 	R0F(i,lev[x]+1){
	// 		ad(stor[cur], y-dist[i][x]);
	// 		if(pre != -1) ad(STOR[pre], y-dist[i][x]);
	// 		if(i > 0) pre = cur, cur = cen[cur];
	// 	}
	// }

	// void propAll(){FOR(i,1,N+1) prop(stor[i]), prop(STOR[i]);}
	// int query(int x){
	// 	int cur  = x, pre = -1, ans = 0;
	// 	R0F(i,lev[x]+1){
	// 		ans+=stor[cur][dist[i][x]];
	// 		if(pre != -1) ans-=STOR[pre][dist[]i][x]];	
	// 		if(i > 0) pre = cur, cur = cen[cur];
	// 	}
	// 	return ans;
	// }
};

struct Eff{
	int n;
	Centroid<200005> cent;
	void solve(){
		cin >> n >> cent.K;

		for(int i = 1; i <= n; i++){
			ll val;
			cin >> val;
			cent.a[i] = mi(val);
			// cin >> cent.a[i];
		}


		for(int i = 1; i <= n-1; i++){
			int u, v;
			bool t;
			cin >> u >> v >> t;
			cent.ae(u, v, t);
		}

		cent.init(n+3);

		

		cent.ans*=inv(mi(2));

		for(int i = 1; i <= n; i++){
			cent.ans+=cent.a[i];
		}

		cout << cent.ans.v << "\n";
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	Eff e; e.solve();
}
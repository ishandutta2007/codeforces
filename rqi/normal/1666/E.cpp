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
tcT, size_t SZ> using AR = array<T, SZ>;
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

#define each(a, x) for(auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
	return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
	return a < b ? a = b, 1 : 0;
}

const int mx = 100005;
int l, n;
int a[mx];

pair<bool, vpi> solveMinMax(int min_sz, int max_sz, bool recover_ans = false){
	// cout << "min_sz, max_sz: " << min_sz << " " << max_sz << "\n";
	pi last_rang = mp(0, 0);
	vpi stored_last_rangs = vpi{last_rang};
	for(int i = 1; i <= n; i++){
		pi new_last_rang = mp(last_rang.f+min_sz, last_rang.s+max_sz);
		ckmax(new_last_rang.f, a[i]);
		if(i+1 <= n){
			ckmin(new_last_rang.s, a[i+1]);
		}
		if(new_last_rang.f > new_last_rang.s){
			// cout << "FAILING" << "\n";
			return mp(false, vpi{});
		}

		swap(last_rang, new_last_rang);
		if(recover_ans){
			stored_last_rangs.pb(last_rang);
		}
	}


	assert(last_rang.f <= last_rang.s);
	if(last_rang.s < l || l < last_rang.f) return mp(false, vpi{});

	if(!recover_ans){
		return mp(true, vpi{});
	}

	vi splits;
	int last_split = l;
	for(int i = n-1; i >= 0; i--){
		int L = last_split-max_sz;
		int R = last_split-min_sz;
		pi allowed_rang = stored_last_rangs[i];
		
		int try_split = max(L, allowed_rang.f);
		if(try_split <= R && try_split <= allowed_rang.s){
			splits.pb(try_split);
			last_split = try_split;
		}
		else{
			assert(false);
		}
	}

	reverse(all(splits));
	splits.pb(l);

	vpi res;
	for(int i = 0; i+1 < sz(splits); i++){
		res.pb(mp(splits[i], splits[i+1]));
	}
	return mp(true, res);
}

int givenMin(int min_sz){ //given min, find minimum max coor
	int L = min_sz;
	int R = MOD;
	while(L < R){
		int M = (L+R)/2;
		pair<bool, vpi> splits = solveMinMax(min_sz, M);
		if(splits.f){
			R = M;
		}
		else{
			L = M+1;
		}
	}
	if(R > l){
		return MOD; //impossible to satisfy
	}
	return L;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> l >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int L = 0;
	int R = l/n;

	while(L < R){
		// cout << L << " " << R << "\n";
		// cout.flush();
		if(R-L <= 20){
			pi best_func = mp(MOD, 0);
			for(int M = L; M <= R; M++){
				int res = givenMin(M);
				if(res == MOD) continue;
				ckmin(best_func, mp(res-M, M));
			}
			assert(best_func.f < MOD);
			L = best_func.s;
			R = best_func.s;
			break;
		}
		int DIFF = (R-L)/3;
		int M1 = L+DIFF;
		int M2 = L+2*DIFF;

		int min_max1 = givenMin(M1);
		int min_max2 = givenMin(M2);
		if(min_max2 == MOD){
			R = M2-1;
			continue;
		}

		int ans1 = min_max1-M1;
		int ans2 = min_max2-M2;
		if(ans1 > ans2){
			L = M1+1;
		}
		else if(ans1 < ans2){
			R = M2-1;
		}
		else{
			L = M1+1;
		}

	}

	assert(L == R);

	int ans_min = L;
	int ans_max = givenMin(ans_min);
	pair<bool, vpi> res = solveMinMax(ans_min, ans_max, true);

	for(auto u: res.s){
		cout << u.f << " " << u.s << "\n";
	}

	// for(int i = 0; i <= l; i++){
	// 	cout << i << " " << givenMin(i) << "\n";
	// }

	// cout << givenMin(3) << "\n";


}
#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
template <typename T>
struct lazy_segment_tree{
	int N;
	vector<T> ST;
	vector<T> lazy;
	lazy_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, -INF);
		lazy = vector<T>(N * 2 - 1, -1);
	}
	void eval(int i){
		if (lazy[i] != -1){
			if (i < N - 1){
				lazy[i * 2 + 1] = lazy[i];
				lazy[i * 2 + 2] = lazy[i];
			}
			ST[i] = lazy[i];
			lazy[i] = -1;
		}
	}
	void range_update(int L, int R, T x, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] = x;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_update(L, R, x, i * 2 + 1, l, m);
			range_update(L, R, x, i * 2 + 2, m, r);
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void range_update(int L, int R, T x){
		return range_update(L, R, x, 0, 0, N);
	}
	T range_min(int L, int R, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return INF;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return min(range_min(L, R, i * 2 + 1, l, m), range_min(L, R, i * 2 + 2, m, r));
		}
	}
	T range_min(int L, int R){
		return range_min(L, R, 0, 0, N);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> S(n);
  for (int i = 0; i < n; i++){
    int l, r, w;
    cin >> l >> r >> w;
    S[i] = make_tuple(w, l, r);
  }
  sort(S.begin(), S.end());
  lazy_segment_tree<int> ST(m);
  int ans = INF;
  for (int i = 0; i < n; i++){
    int w = get<0>(S[i]);
    int l = get<1>(S[i]);
    int r = get<2>(S[i]);
    ST.range_update(l, r, w);
    ans = min(ans, w - ST.range_min(1, m));
  }
  cout << ans << endl;
}
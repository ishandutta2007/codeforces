#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
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
		lazy = vector<T>(N * 2 - 1, -INF);
	}
	void eval(int i){
		if (i < N - 1){
			lazy[i * 2 + 1] = max(lazy[i * 2 + 1], lazy[i]);
			lazy[i * 2 + 2] = max(lazy[i * 2 + 2], lazy[i]);
		}
		ST[i] = max(ST[i], lazy[i]);
		lazy[i] = -INF;
	}
	void range_chmax(int L, int R, T x, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] = x;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_chmax(L, R, x, i * 2 + 1, l, m);
			range_chmax(L, R, x, i * 2 + 2, m, r);
			ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void range_chmax(int L, int R, T x){
		return range_chmax(L, R, x, 0, 0, N);
	}
	void chmax(int k, T x){
		return range_chmax(k, k + 1, x);
	}
	T range_max(int L, int R, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return -INF;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return max(range_max(L, R, i * 2 + 1, l, m), range_max(L, R, i * 2 + 2, m, r));
		}
	}
	T range_max(int L, int R){
		return range_max(L, R, 0, 0, N);
	}
	T operator [](int k){
		return range_max(k, k + 1);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
    h[i]--;
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    p[h[i]] = i;
  }
  vector<int> l(n), r(n);
  set<int> st;
  st.insert(-1);
  st.insert(n);
  for (int i = 0; i < n; i++){
    l[p[i]] = *prev(st.lower_bound(p[i])) + 1;
    r[p[i]] = *st.lower_bound(p[i]);
    st.insert(p[i]);
  }
  lazy_segment_tree<long long> dp(n + 1);
  dp.chmax(0, 0);
  for (int i = 0; i < n; i++){
    long long t = dp.range_max(l[i], i + 1);
    dp.range_chmax(i + 1, r[i] + 1, t + b[i]);
  }
  cout << dp[n] << endl;
}
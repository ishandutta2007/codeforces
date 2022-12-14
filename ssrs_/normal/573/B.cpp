#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
template <typename T>
struct range_add_range_min{
	int N;
	vector<T> ST;
	vector<T> lazy;
	range_add_range_min(vector<int> &A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
		lazy = vector<T>(N * 2 - 1, 0);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void eval(int i){
		if (i < N - 1){
			lazy[i * 2 + 1] += lazy[i];
			lazy[i * 2 + 2] += lazy[i];
		}
		ST[i] += lazy[i];
		lazy[i] = 0;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] += x;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
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
  int n;
  cin >> n;
  vector<int> h(n + 2, 0);
  for (int i = 1; i <= n; i++){
    cin >> h[i];
  }
  range_add_range_min<int> ST(h);
  for (int i = 0; i < n + 2; i++){
    ST.range_add(i, i + 1, i);
  }
  int ans = ST.range_min(0, n + 2);
  for (int i = 1; i < n + 2; i++){
    ST.range_add(0, i, 1);
    ST.range_add(i, n + 2, -1);
    ans = max(ans, ST.range_min(0, n + 2));
  }
  cout << ans << endl;
}
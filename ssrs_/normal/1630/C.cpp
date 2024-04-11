#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
	dual_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, -INF);
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k];
		while (k > 0){
			k = (k - 1) / 2;
			ans = max(ans, ST[k]);
		}
		return ans;
	}
	void range_chmax(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] = max(ST[i], x);
			return;
		} else {
			int m = (l + r) / 2;
			range_chmax(L, R, x, i * 2 + 1, l, m);
			range_chmax(L, R, x, i * 2 + 2, m, r);
		}
	}
	void range_chmax(int L, int R, T x){
		range_chmax(L, R, x, 0, 0, N);
	}
};
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> L(n, n), R(n, 0);
  for (int i = 0; i < n; i++){
    L[a[i]] = min(L[a[i]], i);
    R[a[i]] = max(R[a[i]], i);
  }
  vector<int> id(n, -1);
  for (int i = 0; i < n; i++){
    if (L[i] != n){
      id[L[i]] = i;
    }
  }
  dual_segment_tree<int> dp(n + 1);
  dp.range_chmax(0, 1, 0);
  for (int i = 0; i < n; i++){
    dp.range_chmax(i + 1, i + 2, dp[i] - 1);
    if (id[i] != -1){
      int x = id[i];
      dp.range_chmax(L[x] + 1, R[x] + 1, dp[i] - 1);
    }
  }
  cout << dp[n] + n << endl;
}
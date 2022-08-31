#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
	dual_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, (1 << 30) - 1);
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k];
		while (k > 0){
			k = (k - 1) / 2;
			ans &= ST[k];
		}
		return ans;
	}
	void range_and(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] &= x;
			return;
		} else {
			int m = (l + r) / 2;
			range_and(L, R, x, i * 2 + 1, l, m);
			range_and(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void range_and(int L, int R, T x){
		range_and(L, R, x, 0, 0, N);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    dual_segment_tree<int> ST(n);
    for (int j = 0; j < m; j++){
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      ST.range_and(l, r, x);
    }
    long long S = 0;
    for (int j = 0; j < n; j++){
      S |= ST[j];
    }
    S %= MOD;
    for (int j = 0; j < n - 1; j++){
      S *= 2;
      S %= MOD;
    }
    cout << S << endl;
  }
}
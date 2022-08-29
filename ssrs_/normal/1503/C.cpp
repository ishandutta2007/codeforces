#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
	dual_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, INF);
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k];
		while (k > 0){
			k = (k - 1) / 2;
			ans = min(ans, ST[k]);
		}
		return ans;
	}
	void range_chmin(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] = min(ST[i], x);
			return;
		} else {
			int m = (l + r) / 2;
			range_chmin(L, R, x, i * 2 + 1, l, m);
			range_chmin(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void range_chmin(int L, int R, T x){
		range_chmin(L, R, x, 0, 0, N);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), c(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> c[i];
  }
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(a[i], c[i]);
  }
  sort(P.begin(), P.end());
  for (int i = 0; i < n; i++){
    a[i] = P[i].first;
    c[i] = P[i].second;
  }
  dual_segment_tree<long long> dp1(n), dp2(n);
  dp1.range_chmin(0, 1, 0);
  dp2.range_chmin(0, 1, -a[0]);
  for (int i = 0; i < n - 1; i++){
    long long dp = min(dp1[i], dp2[i] + a[i]);
    int p = upper_bound(a.begin(), a.end(), a[i] + c[i]) - a.begin();
    dp1.range_chmin(i + 1, p, dp);
    dp2.range_chmin(p, n, dp - a[i] - c[i]);
  }
  long long ans = min(dp1[n - 1], dp2[n - 1] + a[n - 1]);
  for (int i = 0; i < n; i++){
    ans += c[i];
  }
  cout << ans << endl;
}
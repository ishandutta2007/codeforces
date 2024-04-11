#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
	}
	T operator [](int k){
		return ST[N - 1 + k];
	}
	void update(int k, T x){
		k += N - 1;
		ST[k] = x;
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = max(ST[k * 2 + 1], ST[k * 2 + 2]);
		}
	}
	T range_max(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return 0;
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
	T all(){
		return ST[0];
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> L(n, n), R(n, -1), cnt(n, 0);
  for (int i = 0; i < n; i++){
    L[a[i]] = min(L[a[i]], i);
    R[a[i]] = max(R[a[i]], i);
    cnt[a[i]]++;
  }
  vector<vector<pair<int, int>>> LP(n + 1);
  for (int i = 0; i < n; i++){
    if (cnt[i] > 0){
      LP[R[i] + 1].push_back(make_pair(L[i], cnt[i]));
    }
  }
  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; i++){
    dp[i] = max(dp[i], dp[i - 1]);
    for (auto P : LP[i]){
      dp[i] = max(dp[i], dp[P.first] + P.second);
    }
  }
  segment_tree<int> ST(n);
  int ans = n;
  for (int i = n; i >= 0; i--){
    ans = min(ans, n - dp[i] - ST.all());
    if (i > 0){
      ST.update(a[i - 1], ST[a[i - 1]] + 1);
    }
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
template <typename T>
struct lazy_segment_tree{
	int N;
	vector<T> ST;
	vector<T> lazy;
	lazy_segment_tree(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, INF);
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
	T all(){
		eval(0);
		return ST[0];
	}
};
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < k; i++){
    lazy_segment_tree<long long> ST(dp[i]);
    map<int, int> mp;
    for (int j = 0; j < n; j++){
      if (mp.count(a[j]) == 1){
        int p = mp[a[j]];
        ST.range_add(0, p + 1, j - p);
      }
      mp[a[j]] = j;
      dp[i + 1][j + 1] = ST.all();
    }
  }
  cout << dp[k][n] << endl;
}
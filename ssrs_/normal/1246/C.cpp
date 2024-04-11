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
		ST = vector<T>(N * 2 - 1, 0);
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k];
		while (k > 0){
			k = (k - 1) / 2;
			ans += ST[k];
			if (ans >= MOD){
    		ans -= MOD;
			}
		}
		return ans;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] += x;
			if (ST[i] >= MOD){
    		ST[i] -= MOD;
			}
			return;
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	void add(int i, T x){
		range_add(i, i + 1, x, 0, 0, N);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  vector<vector<int>> R(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (a[i][j] == 'R'){
        R[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = m - 2; j >= 0; j--){
      R[i][j] += R[i][j + 1];
    }
  }
  vector<vector<int>> D(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (a[i][j] == 'R'){
        D[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < m; i++){
    for (int j = n - 2; j >= 0; j--){
      D[j][i] += D[j + 1][i];
    }
  }
  vector<dual_segment_tree<long long>> dp1(n + 1, dual_segment_tree<long long>(m + 1));
  vector<dual_segment_tree<long long>> dp2(m + 1, dual_segment_tree<long long>(n + 1));
  dp1[0].add(0, 1);
  if (n > 1 || m > 1){
    dp2[0].add(0, 1);
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      dp2[j].range_add(i + 1, n - D[i + 1][j], dp1[i][j]);
      dp1[i].range_add(j + 1, m - R[i][j + 1], dp2[j][i]);
    }
  }
  cout << (dp1[n - 1][m - 1] + dp2[m - 1][n - 1]) % MOD << endl;
}
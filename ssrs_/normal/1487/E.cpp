#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
template <typename T>
struct sparse_table{
	vector<vector<T>> ST;
	sparse_table(vector<T> &A){
		int N = A.size();
		int LOG = 32 - __builtin_clz(N);
		ST = vector<vector<int>>(LOG, vector<int>(N));
		for (int i = 0; i < N; i++){
			ST[0][i] = A[i];
		}
		for (int i = 0; i < LOG - 1; i++){
			for (int j = 0; j < N - (1 << i); j++){
				ST[i + 1][j] = min(ST[i][j], ST[i][j + (1 << i)]);
			}
		}
	}
	int range_min(int L, int R){
		if (L == R){
			return INF;
		}
		int d = 31 - __builtin_clz(R - L);
		return min(ST[d][L], ST[d][R - (1 << d)]);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> n(4);
  for (int i = 0; i < 4; i++){
    cin >> n[i];
  }
  vector<vector<int>> A(4);
  for (int i = 0; i < 4; i++){
    A[i] = vector<int>(n[i]);
    for (int j = 0; j < n[i]; j++){
      cin >> A[i][j];
    }
  }
  vector<vector<vector<int>>> E(3);
  for (int i = 0; i < 3; i++){
    E[i] = vector<vector<int>>(n[i + 1]);
    for (int j = 0; j < n[i + 1]; j++){
      E[i][j].push_back(-1);
      E[i][j].push_back(n[i]);
    }
    int m;
    cin >> m;
    for (int j = 0; j < m; j++){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      E[i][y].push_back(x);
    }
  }
  vector<vector<int>> dp(4);
  for (int i = 0; i < 4; i++){
    dp[i] = vector<int>(n[i], INF);
  }
  for (int i = 0; i < n[0]; i++){
    dp[0][i] = A[0][i];
  }
  for (int i = 0; i < 3; i++){
    sparse_table<int> ST(dp[i]);
    for (int j = 0; j < n[i + 1]; j++){
      sort(E[i][j].begin(), E[i][j].end());
      int cnt = E[i][j].size();
      for (int k = 0; k < cnt - 1; k++){
        dp[i + 1][j] = min(dp[i + 1][j], ST.range_min(E[i][j][k] + 1, E[i][j][k + 1]) + A[i + 1][j]);
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < n[3]; i++){
    ans = min(ans, dp[3][i]);
  }
  if (ans == INF){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
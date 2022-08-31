#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct dual_sparse_table{
  vector<vector<T>> ST;
  function<T(T, T)> f;
  T E;
  dual_sparse_table(int N, function<T(T, T)> f, T E): f(f), E(E){
    int LOG = 32 - __builtin_clz(N);
    ST = vector<vector<T>>(LOG, vector<T>(N, E));
  }
  dual_sparse_table(vector<T> &A, function<T(T, T)> f, T E): f(f), E(E){
    int N = A.size();
    int LOG = 32 - __builtin_clz(N);
    ST = vector<vector<T>>(LOG, vector<T>(N, E));
    ST[0] = A;
  }
  void apply(int L, int R, T x){
    if (L == R){
      return;
    }
    int d = 31 - __builtin_clz(R - L);
    ST[d][L] = f(ST[d][L], x);
    ST[d][R - (1 << d)] = f(ST[d][R - (1 << d)], x);
  }
  vector<T> get(){
    int LOG = ST.size();
    int N = ST[0].size();
    for (int i = LOG - 2; i >= 0; i--){
      for (int j = 0; j < N - (1 << i); j++){
        ST[i][j] = f(ST[i][j], ST[i + 1][j]);
        ST[i][j + (1 << i)] = f(ST[i][j + (1 << i)], ST[i + 1][j]);
      }
    }
    return ST[0];
  }
};
vector<pair<int, pair<int, int>>> quotient_ranges(int N){
	vector<pair<int, pair<int, int>>> ans;
	for (int i = 1; i * i <= N; i++){
		ans.push_back(make_pair(N / i, make_pair(i, i)));
	}
	for (int i = N / ((int) sqrt(N) + 1); i >= 1; i--){
		ans.push_back(make_pair(i, make_pair(N / (i + 1) + 1, N / i)));
	}
	return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    function<int(int, int)> op = [](int a, int b){
      return max(a, b);
    };
    dual_sparse_table<int> ST(a[0] + 1, op, 0);
    for (int j = 0; j < n; j++){
      vector<pair<int, pair<int, int>>> Q = quotient_ranges(a[j]);
      int cnt = Q.size();
      vector<int> b;
      for (int l = 0; l < cnt; l++){
        if (Q[l].second.first <= k){
          b.push_back(Q[l].first);
        }
      }
      reverse(b.begin(), b.end());
      int cnt2 = b.size();
      int x = 0;
      for (int l = 0; l < cnt2; l++){
        int y = min(b[l], a[0]);
        if (x <= y){
          ST.apply(x + 1, y + 1, b[l]);
          x = b[l];
        }
      }
    }
    vector<int> res = ST.get();
    int ans = a[n - 1];
    for (int j = 1; j <= a[0]; j++){
      ans = min(ans, res[j] - j);
    }
    cout << ans << endl;
  }
}
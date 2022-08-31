#include <bits/stdc++.h>
using namespace std;
const int LOG = 20;
const int INF = 100000000;
struct sparse_table{
  int N;
  vector<vector<int>> ST;
  sparse_table(vector<int> &A){
    N = A.size();
    ST = vector<vector<int>>(LOG, vector<int>(N, 0));
    for (int i = 0; i < N; i++){
      ST[0][i] = A[i];
    }
    for (int i = 0; i < LOG - 1; i++){
      for (int j = 0; j < N - (1 << i); j++){
        ST[i + 1][j] = max(ST[i][j], ST[i][j + (1 << i)]);
      }
    }
  }
  int range_max(int L, int R){
    int d = 31 - __builtin_clz(R - L);
    return max(ST[d][L], ST[d][R - (1 << d)]);
  }
};
struct partially_persistent_segment_tree{
  int N;
  vector<vector<pair<int, int>>> ST;
  int t;
  partially_persistent_segment_tree(int n){
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<vector<pair<int, int>>>(N * 2 - 1);
    for (int i = 0; i < N * 2 - 1; i++){
      ST[i].push_back(make_pair(0, 0));
    }
    t = 0;
  }
  void update(int i, int x){
    t++;
    i += N - 1;
    ST[i].push_back(make_pair(t, x));
    while (i > 0){
      i = (i - 1) / 2;
      int L = ST[i * 2 + 1].back().second;
      int R = ST[i * 2 + 2].back().second;
      if (ST[i].back().second != max(L, R)){
        ST[i].push_back(make_pair(t, max(L, R)));
      }
    }
  }
  int range_max(int L, int R, int T, int i, int l, int r){
    if (r <= L || R <= l){
      return 0;
    } else if (L <= l && r <= R){
      return (*(upper_bound(ST[i].begin(), ST[i].end(), make_pair(T, INF)) - 1)).second;
    } else {
      int m = (l + r) / 2;
      return max(range_max(L, R, T, i * 2 + 1, l, m), range_max(L, R, T, i * 2 + 2, m, r));
    }
  }
  int range_max(int L, int R, int T){
    return range_max(L, R, T, 0, 0, N);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<pair<int, int>> p(n);
    for (int j = 0; j < n; j++){
      p[j] = make_pair(a[j], j);
    }
    sort(p.begin(), p.end());
    for (int j = 0; j < n; j++){
      a[p[j].second] = j;
    }
    sparse_table ST(a);
    partially_persistent_segment_tree dp(n);
    int ans = 0;
    for (int j = n - 1; j >= 0; j--){
      int next = 1;
      if (j < n - 1){
        if (ST.range_max(j, n) > a[j]){
          next = 2;
        }
      }
      next = max(next, dp.range_max(a[j], n, n - 1 - j) + 1);
      if (ST.range_max(j, n) > a[j]){
        int tv = j + 1;
        int fv = n;
        while (fv - tv > 1){
          int mid = (tv + fv) / 2;
          if (ST.range_max(j, mid) > a[j]){
            fv = mid;
          } else {
            tv = mid;
          }
        }
        next = max(next, dp.range_max(a[j], n, n - fv) + 2);
      }
      if (j == 0){
        ans = max(ans, next);
      } else if (ST.range_max(0, j) >= a[j]){
        ans = max(ans, next + 1);
      } else {
        ans = max(ans, next);
      }
      dp.update(a[j], next);
    }
    cout << ans << "\n";
  }
}
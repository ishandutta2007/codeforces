#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int longest_increasing_subsequence(vector<int> &A){
	int N = A.size();
	vector<int> dp(N, INF);
	for (int i = 0; i < N; i++){
		*lower_bound(dp.begin(), dp.end(), A[i]) = A[i];
	}
	return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}
struct segment_tree_min{
  int N;
  vector<pair<int, int>> ST;
  segment_tree_min(vector<pair<int, int>> &A){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<pair<int, int>>(N * 2 - 1, make_pair(INF, 0));
    for (int i = 0; i < n; i++){
      ST[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void erase(int i){
    i += N - 1;
    ST[i].first = INF;
    while (i > 0){
      i = (i - 1) / 2;
      ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  pair<int, int> range_min(int L, int R, int i, int l, int r){
    if (r <= L || R <= l){
      return make_pair(INF, INF);
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return min(range_min(L, R, i * 2 + 1, l, m), range_min(L, R, i * 2 + 2, m, r));
    }
  }
  pair<int, int> range_min(int L, int R){
    return range_min(L, R, 0, 0, N);
  }
};
struct segment_tree_max{
  int N;
  vector<pair<int, int>> ST;
  segment_tree_max(vector<pair<int, int>> &A){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<pair<int, int>>(N * 2 - 1, make_pair(-INF, 0));
    for (int i = 0; i < n; i++){
      ST[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void erase(int i){
    i += N - 1;
    ST[i].first = -INF;
    while (i > 0){
      i = (i - 1) / 2;
      ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  pair<int, int> range_max(int L, int R, int i, int l, int r){
    if (r <= L || R <= l){
      return make_pair(-INF, -INF);
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return max(range_max(L, R, i * 2 + 1, l, m), range_max(L, R, i * 2 + 2, m, r));
    }
  }
  pair<int, int> range_max(int L, int R){
    return range_max(L, R, 0, 0, N);
  }
};
int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  bool ok = true;
  for (int i = 0; i < n; i++){
    if (a[i] < n && b[i] < n){
      ok = false;
    }
    if (a[i] >= n && b[i] >= n){
      ok = false;
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    vector<int> B(n, -1);
    for (int i = 0; i < n; i++){
      if (a[i] < b[i]){
        B[a[i]] = b[i];
      } else {
        B[b[i]] = a[i];
      }
    }
    int lis = longest_increasing_subsequence(B);
    if (lis >= 3){
      cout << -1 << endl;
    } else {
      vector<tuple<int, int, int>> C(n);
      for (int i = 0; i < n; i++){
        C[i] = make_tuple(min(a[i], b[i]), a[i], b[i]);
      }
      sort(C.begin(), C.end());
      for (int i = 0; i < n; i++){
        a[i] = get<1>(C[i]);
        b[i] = get<2>(C[i]);
      }
      vector<int> l(n), r(n);
      for (int i = 0; i < n; i++){
        l[i] = min(a[i], b[i]);
        r[i] = max(a[i], b[i]);
      }
      vector<bool> f(n, false);
      for (int i = 0; i < n; i++){
        f[i] = a[i] > b[i];
      }
      vector<pair<int, int>> L(n * 2, make_pair(INF, 0));
      vector<pair<int, int>> R(n * 2, make_pair(-INF, 0));
      for (int i = 0; i < n; i++){
        L[r[i]] = make_pair(l[i], i);
        R[l[i]] = make_pair(r[i], i);
      }
      segment_tree_min ST1(L);
      segment_tree_max ST2(R);
      int ans = 0;
      vector<int> c(n, -1);
      for (int i = 0; i < n; i++){
        if (c[i] == -1){
          c[i] = 0;
          ST1.erase(r[i]);
          ST2.erase(l[i]);
          int p0 = 0, p1 = 0;
          queue<int> Q;
          Q.push(i);
          while (!Q.empty()){
            int v = Q.front();
            Q.pop();
            if (c[v] == 0 && !f[v] || c[v] == 1 && f[v]){
              p0++;
            }
            if (c[v] == 0 && f[v] || c[v] == 1 && !f[v]){
              p1++;
            }
            while (true){
              pair<int, int> P = ST1.range_min(l[v], r[v]);
              if (P.first >= l[v]){
                break;
              }
              int w = P.second;
              c[w] = 1 - c[v];
              ST1.erase(r[w]);
              ST2.erase(l[w]);
              Q.push(w);
            }
            while (true){
              pair<int, int> P = ST2.range_max(l[v], r[v]);
              if (P.first <= r[v]){
                break;
              }
              int w = P.second;
              c[w] = 1 - c[v];
              ST1.erase(r[w]);
              ST2.erase(l[w]);
              Q.push(w);
            }
          }
          ans += min(p0, p1);
        }
      }
      if (!ok){
        cout << -1 << endl;
      } else {
        cout << ans << endl;
      }
   }
  }
}
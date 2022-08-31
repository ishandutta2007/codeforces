#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
struct dual_segment_tree_chmax{
  int N;
  vector<int> ST;
  dual_segment_tree_chmax(int N2){
    N = 1;
    while (N < N2){
      N *= 2;
    }
    ST = vector<int>(N * 2 - 1, -INF);
  }
  void range_chmax(int L, int R, int x, int i, int l, int r){
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      ST[i] = max(ST[i], x);
    } else {
      int m = (l + r) / 2;
      range_chmax(L, R, x, i * 2 + 1, l, m);
      range_chmax(L, R, x, i * 2 + 2, m, r);
    }
  }
  void range_chmax(int L, int R, int x){
    range_chmax(L, R, x, 0, 0, N);
  }
  int operator [](int i){
    i += N - 1;
    int ans = ST[i];
    while (i > 0){
      i = (i - 1) / 2;
      ans = max(ans, ST[i]);
    }
    return ans;
  }
};
struct dual_segment_tree_chmin{
  int N;
  vector<int> ST;
  dual_segment_tree_chmin(int N2){
    N = 1;
    while (N < N2){
      N *= 2;
    }
    ST = vector<int>(N * 2 - 1, INF);
  }
  void range_chmin(int L, int R, int x, int i, int l, int r){
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      ST[i] = min(ST[i], x);
    } else {
      int m = (l + r) / 2;
      range_chmin(L, R, x, i * 2 + 1, l, m);
      range_chmin(L, R, x, i * 2 + 2, m, r);
    }
  }
  void range_chmin(int L, int R, int x){
    range_chmin(L, R, x, 0, 0, N);
  }
  int operator [](int i){
    i += N - 1;
    int ans = ST[i];
    while (i > 0){
      i = (i - 1) / 2;
      ans = min(ans, ST[i]);
    }
    return ans;
  }
};
int main(){
  int n;
  cin >> n;
  vector<int> p(n + 1);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  p[n] = 0;
  dual_segment_tree_chmax inc(n);
  dual_segment_tree_chmin dec(n);
  long long ans = 0;
  int L = 0;
  for (int i = 0; i < n; i++){
    int tv1 = i, fv1 = L - 1;
    while (tv1 - fv1 > 1){
      int mid = (tv1 + fv1) / 2;
      if (inc[mid] < p[i]){
        tv1 = mid;
      } else {
        fv1 = mid;
      }
    }
    int p1 = tv1;
    int tv2 = i, fv2 = L - 1;
    while (tv2 - fv2 > 1){
      int mid = (tv2 + fv2) / 2;
      if (dec[mid] > p[i]){
        tv2 = mid;
      } else {
        fv2 = mid;
      }
    }
    int p2 = tv2;
    L = min(p1, p2);
    ans += i + 1 - L;
    if (p1 < p2){
      inc.range_chmax(p1, p2, p[i]);
    } else {
      dec.range_chmin(p2, p1, p[i]);
    }
    if (p[i] < p[i + 1]){
      inc.range_chmax(max(p1, p2), i + 1, p[i]);
    } else {
      dec.range_chmin(max(p1, p2), i + 1, p[i]);
    }
  }
  cout << ans << endl;
}
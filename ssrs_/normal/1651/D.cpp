#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R){
    return sum(R) - sum(L);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    tie(x[i], y[i]) = make_pair(x[i] + y[i] + 1, x[i] - y[i] + 200000);
  }
  vector<vector<int>> update(400001);
  for (int i = 0; i < n; i++){
    update[y[i]].push_back(i);
  }
  vector<int> tv(n, 0), fv(n, 1000);
  while (true){
    bool ok = true;
    vector<int> mid(n, -1);
    for (int i = 0; i < n; i++){
      if (fv[i] - tv[i] > 1){
        mid[i] = (tv[i] + fv[i]) / 2;
        ok = false;
      }
    }
    if (ok){
      break;
    }
    vector<vector<int>> query_add(400001), query_sub(400001);
    for (int i = 0; i < n; i++){
      if (mid[i] != -1){
        query_add[min(y[i] + mid[i] + 1, 400000)].push_back(i);
        query_sub[max(y[i] - mid[i], 0)].push_back(i);
      }
    }
    binary_indexed_tree<int> BIT(400000);
    vector<int> cnt(n, 0);
    for (int i = 0; i <= 400000; i++){
      for (int p : query_add[i]){
        int L = max(x[p] - mid[p], 0);
        int R = min(x[p] + mid[p] + 1, 400000);
        cnt[p] += BIT.sum(L, R);
      }
      for (int p : query_sub[i]){
        int L = max(x[p] - mid[p], 0);
        int R = min(x[p] + mid[p] + 1, 400000);
        cnt[p] -= BIT.sum(L, R);
      }
      for (int p : update[i]){
        BIT.add(x[p], 1);
      }
    }
    for (int i = 0; i < n; i++){
      if (mid[i] != -1){
        if (cnt[i] == 2 * mid[i] * (mid[i] + 1) + 1){
          tv[i] = mid[i];
        } else {
          fv[i] = mid[i];
        }
      }
    }
  }
  vector<vector<int>> xy(400001), yx(400001);
  for (int i = 0; i < n; i++){
    xy[x[i]].push_back(y[i]);
    yx[y[i]].push_back(x[i]);
  }
  for (int i = 0; i < 400001; i++){
    sort(xy[i].begin(), xy[i].end());
    sort(yx[i].begin(), yx[i].end());
  }
  set<pair<int, int>> st;
  for (int i = 0; i < n; i++){
    st.insert(make_pair(x[i], y[i]));
  }
  for (int i = 0; i < n; i++){
    int ansx, ansy;
    bool ok = false;
    if (!ok){
      int d1 = lower_bound(xy[x[i] - fv[i]].begin(), xy[x[i] - fv[i]].end(), y[i] + fv[i] + 1) - lower_bound(xy[x[i] - fv[i]].begin(), xy[x[i] - fv[i]].end(), y[i] - fv[i]);
      if (d1 != fv[i] + 1){
        for (int j = 0; j <= fv[i]; j++){
          if (st.count(make_pair(x[i] - fv[i], y[i] - fv[i] + j * 2)) == 0){
            ansx = x[i] - fv[i];
            ansy = y[i] - fv[i] + j * 2;
            ok = true;
            break;
          }
        }
      }
    }
    if (!ok){
      int d2 = lower_bound(xy[x[i] + fv[i]].begin(), xy[x[i] + fv[i]].end(), y[i] + fv[i] + 1) - lower_bound(xy[x[i] + fv[i]].begin(), xy[x[i] + fv[i]].end(), y[i] - fv[i]);
      if (d2 != fv[i] + 1){
        for (int j = 0; j <= fv[i]; j++){
          if (st.count(make_pair(x[i] + fv[i], y[i] - fv[i] + j * 2)) == 0){
            ansx = x[i] + fv[i];
            ansy = y[i] - fv[i] + j * 2;
            ok = true;
            break;
          }
        }
      }
    }
    if (!ok){
      int d3 = lower_bound(yx[y[i] - fv[i]].begin(), yx[y[i] - fv[i]].end(), x[i] + fv[i] + 1) - lower_bound(yx[y[i] - fv[i]].begin(), yx[y[i] - fv[i]].end(), x[i] - fv[i]);
      if (d3 != fv[i] + 1){
        for (int j = 0; j <= fv[i]; j++){
          if (st.count(make_pair(x[i] - fv[i] + j * 2, y[i] - fv[i])) == 0){
            ansx = x[i] - fv[i] + j * 2;
            ansy = y[i] - fv[i];
            ok = true;
            break;
          }
        }
      }
    }
    if (!ok){
      int d4 = lower_bound(yx[y[i] + fv[i]].begin(), yx[y[i] + fv[i]].end(), x[i] + fv[i] + 1) - lower_bound(yx[y[i] + fv[i]].begin(), yx[y[i] + fv[i]].end(), x[i] - fv[i]);
      if (d4 != fv[i] + 1){
        for (int j = 0; j <= fv[i]; j++){
          if (st.count(make_pair(x[i] - fv[i] + j * 2, y[i] + fv[i])) == 0){
            ansx = x[i] - fv[i] + j * 2;
            ansy = y[i] + fv[i];
            ok = true;
            break;
          }
        }
      }
    }
    ansx--;
    ansy -= 200000;
    cout << (ansx + ansy) / 2 + 1 << ' ' << (ansx - ansy) / 2 + 1 << "\n";
  }
}
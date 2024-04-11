#include <bits/stdc++.h>
using namespace std;
const int INF1 = 1000000001;
const long long INF2 = 1100000000000000000;
struct lazy_segment_tree{
  int N;
  vector<long long> x;
  vector<long long> mn;
  vector<bool> is_upd;
  vector<long long> lazy_a, lazy_b;
  lazy_segment_tree(vector<long long> &x): x(x){
    int n = x.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    while (x.size() < N){
      x.push_back(INF1);
    }
    mn = vector<long long>(N * 2 - 1, INF2);
    is_upd = vector<bool>(N * 2 - 1, false);
    lazy_a = vector<long long>(N * 2 - 1, 0);
    lazy_b = vector<long long>(N * 2 - 1, 0);
  }
  void push(int i, int j){
    if (is_upd[i]){
      is_upd[j] = true;
      lazy_a[j] = lazy_a[i];
      lazy_b[j] = lazy_b[i];
    } else {
      lazy_b[j] += lazy_b[i];
    }
  }
  void eval(int i, int l, int r){
    if (i < N - 1){
      push(i, i * 2 + 1);
      push(i, i * 2 + 2);
    }
    if (is_upd[i]){
      if (lazy_a[i] >= 0){
        mn[i] = x[l] * lazy_a[i] + lazy_b[i];
      } else {
        mn[i] = x[r - 1] * lazy_a[i] + lazy_b[i];
      }
    } else {
      mn[i] += lazy_b[i];
    }
    is_upd[i] = false;
    lazy_b[i] = 0;
  }
  void range_add(int L, int R, long long x, int i, int l, int r){
    eval(i, l, r);
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      lazy_b[i] = x;
      eval(i, l, r);
    } else {
      int m = (l + r) / 2;
      range_add(L, R, x, i * 2 + 1, l, m);
      range_add(L, R, x, i * 2 + 2, m, r);
      mn[i] = min(mn[i * 2 + 1], mn[i * 2 + 2]);
    }
  }
  void range_add(int L, int R, long long x){
    range_add(L, R, x, 0, 0, N);
  }
  void range_update(int L, int R, long long a, long long b, int i, int l, int r){
    eval(i, l, r);
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      is_upd[i] = true;
      lazy_a[i] = a;
      lazy_b[i] = b;
      eval(i, l, r);
    } else {
      int m = (l + r) / 2;
      range_update(L, R, a, b, i * 2 + 1, l, m);
      range_update(L, R, a, b, i * 2 + 2, m, r);
      mn[i] = min(mn[i * 2 + 1], mn[i * 2 + 2]);
    }
  }
  void range_update(int L, int R, long long a, long long b){
    range_update(L, R, a, b, 0, 0, N);
  }
  long long range_min(int L, int R, int i, int l, int r){
    eval(i, l, r);
    if (r <= L || R <= l){
      return INF2;
    } else if (L <= l && r <= R){
      return mn[i];
    } else {
      int m = (l + r) / 2;
      return min(range_min(L, R, i * 2 + 1, l, m), range_min(L, R, i * 2 + 2, m, r));
    }
  }
  long long range_min(int L, int R){
    return range_min(L, R, 0, 0, N);
  }
  long long operator [](int k){
    return range_min(k, k + 1, 0, 0, N);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(7);
  int q;
  cin >> q;
  vector<tuple<int, int, int, int>> query(q);
  for (int i = 0; i < q; i++){
    int T;
    cin >> T;
    if (T == 1){
      int t, s;
      cin >> t >> s;
      query[i] = make_tuple(1, t, s, -1);
    }
    if (T == 2){
      int t;
      cin >> t;
      query[i] = make_tuple(2, t, -1, -1);
    }
    if (T == 3){
      int l, r, v;
      cin >> l >> r >> v;
      query[i] = make_tuple(3, l, r, v);
    }
  }
  vector<long long> time;
  time.push_back(0);
  time.push_back(INF1);
  for (int i = 0; i < q; i++){
    if (get<0>(query[i]) == 1){
      time.push_back(get<1>(query[i]));
    }
    if (get<0>(query[i]) == 3){
      time.push_back(get<1>(query[i]));
      time.push_back(get<2>(query[i]));
    }
  }
  sort(time.begin(), time.end());
  time.erase(unique(time.begin(), time.end()), time.end());
  for (int i = 0; i < q; i++){
    if (get<0>(query[i]) == 1){
      get<1>(query[i]) = lower_bound(time.begin(), time.end(), get<1>(query[i])) - time.begin();
    }
    if (get<0>(query[i]) == 2){
      get<1>(query[i]) = lower_bound(time.begin(), time.end(), get<1>(query[i])) - time.begin();
    }
    if (get<0>(query[i]) == 3){
      get<1>(query[i]) = lower_bound(time.begin(), time.end(), get<1>(query[i])) - time.begin();
      get<2>(query[i]) = lower_bound(time.begin(), time.end(), get<2>(query[i])) - time.begin();
    }
  }
  int n = time.size();
  map<int, int> speed;
  speed[0] = 0;
  speed[n - 1] = 0;
  lazy_segment_tree ST(time);
  ST.range_update(0, n, 0, 0);
  for (int i = 0; i < q; i++){
    int T = get<0>(query[i]);
    if (T == 1){
      int t = get<1>(query[i]);
      int s = get<2>(query[i]);
      int R = (*speed.upper_bound(t)).first;
      int p = (*prev(speed.lower_bound(t))).second;
      ST.range_update(t, R, s, ST[t] - s * time[t]);
      ST.range_add(R, n, (time[R] - time[t]) * (s - p));
      speed[t] = s;
    }
    if (T == 2){
      int t = get<1>(query[i]);
      int s = (*prev(speed.lower_bound(t))).second;
      int R = (*speed.upper_bound(t)).first;
      int p = speed[t];
      ST.range_update(t, R, s, ST[t] - s * time[t]);
      ST.range_add(R, n, (time[R] - time[t]) * (s - p));
      speed.erase(t);
    }
    if (T == 3){
      int l = get<1>(query[i]);
      int r = get<2>(query[i]);
      int v = get<3>(query[i]);
      bool add = false;
      if (!speed.count(l)){
        add = true;
        int t = l;
        int s = 0;
        int R = (*speed.upper_bound(t)).first;
        int p = (*prev(speed.lower_bound(t))).second;
        ST.range_update(t, R, s, ST[t] - s * time[t]);
        ST.range_add(R, n, (time[R] - time[t]) * (s - p));
        speed[t] = s;
      }
      if (v == 0){
        cout << time[l] << "\n";
      } else if (l == r){
        cout << -1 << "\n";
      } else {
        long long b = ST[l];
        if (ST.range_min(l, r + 1) > b - v){
          cout << -1 << "\n";
        } else {
          int tv = l, fv = r + 1;
          while (fv - tv > 1){
            int mid = (tv + fv) / 2;
            if (ST.range_min(l, mid + 1) > b - v){
              tv = mid;
            } else {
              fv = mid;
            }
          }
          long long R = ST[tv] - (b - v);
          int s = (*prev(speed.upper_bound(tv))).second;
          cout << time[tv] - (double) R / s << "\n";
        }
      }
      if (add){
        int t = l;
        int s = (*prev(speed.lower_bound(t))).second;
        int R = (*speed.upper_bound(t)).first;
        int p = 0;
        ST.range_update(t, R, s, ST[t] - s * time[t]);
        ST.range_add(R, n, (time[R] - time[t]) * (s - p));
        speed.erase(t);
      }
    }
  }
}
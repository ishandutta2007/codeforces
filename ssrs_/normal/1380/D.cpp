#include <bits/stdc++.h>
using namespace std;
int INF = 1100000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  long long x;
  int k;
  long long y;
  cin >> x >> k >> y;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  vector<bool> r(n, false);
  int pos = 0;
  bool ok = true;
  for (int i = 0; i < m; i++){
    while (pos < n && a[pos] != b[i]){
      pos++;
      if (pos == n){
        ok = false;
        break;
      }
    }
    r[pos] = true;
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    a.insert(a.begin(), -INF);
    a.push_back(-INF);
    r.insert(r.begin(), 1);
    r.push_back(1);
    n += 2;
    vector<int> left;
    vector<vector<int>> mid;
    vector<int> right;
    for (int i = 1; i < n; i++){
      if (r[i - 1] == 1 && r[i] == 0){
        left.push_back(a[i - 1]);
        mid.push_back(vector<int>(1, a[i]));
      }
      if (r[i - 1] == 0 && r[i] == 0){
        mid.back().push_back(a[i]);
      }
      if (r[i - 1] == 0 && r[i] == 1){
        right.push_back(a[i]);
      }
    }
    int cnt = left.size();
    long long ans = 0;
    for (int i = 0; i < cnt; i++){
      int sz = mid[i].size();
      int mid_max = 0;
      for (int j = 0; j < sz; j++){
        mid_max = max(mid_max, mid[i][j]);
      }
      if (sz >= k){
        if (y * k >= x){
          ans += y * (sz % k) + x * (sz / k);
        } else if (mid_max > max(left[i], right[i])){
          ans += y * (sz - k) + x;
        } else {
          ans += y * sz;
        }
      } else {
        if (mid_max > max(left[i], right[i])){
          ok = false;
        } else {
          ans += y * sz;
        }
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
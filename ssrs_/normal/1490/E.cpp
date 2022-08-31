#include <bits/stdc++.h>
using namespace std;
int main(){
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
    int tv = n, fv = -1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      long long c = 0;
      for (int j = 0; j <= mid; j++){
        c += p[j].first;
      }
      bool ok = true;
      for (int j = mid + 1; j < n; j++){
        if (c < p[j].first){
          ok = false;
          break;
        } else {
          c += p[j].first;
        }
      }
      if (ok){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    vector<int> ans;
    for (int j = tv; j < n; j++){
      ans.push_back(p[j].second);
    }
    sort(ans.begin(), ans.end());
    int cnt = ans.size();
    cout << cnt << endl;
    for (int j = 0; j < cnt; j++){
      cout << ans[j] + 1;
      if (j < cnt - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
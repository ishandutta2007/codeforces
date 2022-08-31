#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n), y(n), c(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i] >> c[i];
    c[i]--;
  }
  int ans = 0;
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 3; j++){
      int j1 = (j + 1) % 3;
      int j2 = (j + 2) % 3;
      vector<int> pos;
      for (int k = 0; k < n; k++){
        if (c[k] == j){
          pos.push_back(x[k]);
        }
      }
      sort(pos.begin(), pos.end());
      int tv = 0, fv = n / 3 + 1;
      while (fv - tv > 1){
        int mid = (tv + fv) / 2;
        int L = pos[mid - 1];
        vector<int> x1, y1, x2, y2;
        for (int k = 0; k < n; k++){
          if (x[k] > L){
            if (c[k] == j1){
              x1.push_back(x[k]);
              y1.push_back(y[k]);
            }
            if (c[k] == j2){
              x2.push_back(x[k]);
              y2.push_back(y[k]);
            }
          }
        }
        sort(x1.begin(), x1.end());
        sort(y1.begin(), y1.end());
        sort(x2.begin(), x2.end());
        sort(y2.begin(), y2.end());
        bool ok = false;
        int cnt1 = x1.size();
        int cnt2 = x2.size();
        if (cnt1 >= mid && cnt2 >= mid){
          if (x1[mid - 1] < x2[cnt2 - mid]){
            ok = true;
          }
          if (x2[mid - 1] < x1[cnt1 - mid]){
            ok = true;
          }
          if (y1[mid - 1] < y2[cnt2 - mid]){
            ok = true;
          }
          if (y2[mid - 1] < y1[cnt1 - mid]){
            ok = true;
          }
        }
        if (ok){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      ans = max(ans, tv);
    }
    for (int j = 0; j < n; j++){
      swap(x[j], y[j]);
      y[j] *= -1;
    }
  }
  cout << ans * 3 << endl;
}
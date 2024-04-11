#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int m, k;
    cin >> m >> k;
    vector<int> a(k);
    for (int j = 0; j < k; j++){
      cin >> a[j];
    }
    vector<pair<int, int>> P(k);
    for (int j = 0; j < k; j++){
      P[j] = make_pair(a[j], j);
    }
    sort(P.begin(), P.end(), greater<pair<int, int>>());
    int tv = 1000, fv = 0;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      int cnt1, cnt2;
      if (mid % 2 == 0){
        cnt1 = mid * mid / 2;
        cnt2 = mid * mid / 4 * 3;
      } else {
        cnt1 = mid * (mid + 1) / 2;
        cnt2 = mid * mid - (mid / 2) * (mid / 2);
      }
      if (cnt1 >= P[0].first && cnt2 >= m){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    int n = tv;
    vector<pair<int, int>> pos;
    for (int j = 0; j < n; j++){
      for (int l = 0; l < n; l++){
        if (j % 2 == 0 && l % 2 == 1){
          pos.push_back(make_pair(j, l));
        }
      }
    }
    for (int j = 0; j < n; j++){
      for (int l = 0; l < n; l++){
        if (j % 2 == 0 && l % 2 == 0){
          pos.push_back(make_pair(j, l));
        }
      }
    }
    for (int j = 0; j < n; j++){
      for (int l = 0; l < n; l++){
        if (j % 2 == 1 && l % 2 == 0){
          pos.push_back(make_pair(j, l));
        }
      }
    }
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int c = 0;
    for (int j = 0; j < k; j++){
      for (int l = 0; l < P[j].first; l++){
        int x = pos[c].first;
        int y = pos[c].second;
        ans[x][y] = P[j].second + 1;
        c++;
      }
    }
    cout << n << "\n";
    for (int j = 0; j < n; j++){
      for (int l = 0; l < n; l++){
        cout << ans[j][l];
        if (l < n - 1){
          cout << ' ';
        }
      }
      cout << "\n";
    }

  }
}
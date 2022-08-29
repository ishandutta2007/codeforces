#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<pair<int, int>> P(n);
    for (int j = 0; j < n; j++){
      int l, r;
      cin >> l >> r;
      P[j] = make_pair(l, r);
    }
    sort(P.begin(), P.end());
    vector<int> L(n + 1, 0);
    vector<pair<int, int>> left;
    vector<pair<int, int>> left2(n + 1);
    for (int j = 0; j < n - 1; j++){
      if (left.empty()){
        left.push_back(P[j]);
      } else {
        if (left.back().second >= P[j].first){
          left.back().second = max(left.back().second, P[j].second);
        } else {
          left.push_back(P[j]);
        }
      }
      L[j + 1] = left.size();
      left2[j + 1] = left.back();
    }
    vector<pair<int, int>> right;
    int ans = L[n - 1];
    for (int j = n - 1; j >= 1; j--){
      while (1){
        if (right.empty()){
          right.push_back(P[j]);
          break;
        } else if (P[j].second >= right.back().second){
          right.pop_back();
        } else if (right.back().first <= P[j].second){
          right.back().first = min(right.back().first, P[j].first);
          break;
        } else {
          right.push_back(P[j]);
          break;
        }
      }
      int sz = right.size();
      if (j == 1){
        ans = max(ans, sz);
      } else {
        int r = left2[j - 1].second;
        int tv = 0;
        int fv = sz + 1;
        while (fv - tv > 1){
          int mid = (tv + fv) / 2;
          if (right[sz - mid].first <= r){
            tv = mid;
          } else {
            fv = mid;
          }
        }
        int sz2 = L[j - 1];
        int tmp = sz + sz2;
        tmp -= tv;
        ans = max(ans, tmp);
      }
    }
    cout << ans << endl;
  }
}
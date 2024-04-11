#include <bits/stdc++.h>
using namespace std;
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
    vector<int> a2 = a;
    sort(a2.begin(), a2.end());
    a2.erase(unique(a2.begin(), a2.end()), a2.end());
    int cnt = a2.size();
    for (int j = 0; j < n; j++){
      a[j] = lower_bound(a2.begin(), a2.end(), a[j]) - a2.begin();
    }
    vector<vector<int>> P(cnt);
    for (int j = 0; j < n; j++){
      P[a[j]].push_back(j);
    }
    int ans = -1;
    for (int j = 0; j < cnt; j++){
      int cnt2 = P[j].size();
      for (int k = 0; k < cnt2 - 1; k++){
        ans = max(ans, n - (P[j][k + 1] - P[j][k]));
      }
    }
    cout << ans << endl;
  }
}
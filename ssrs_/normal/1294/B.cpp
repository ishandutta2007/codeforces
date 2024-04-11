#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1);
    x[0] = 0;
    y[0] = 0;
    for (int j = 1; j <= n; j++){
      cin >> x[j] >> y[j];
    }
    vector<pair<int, int>> P(n + 1);
    for (int j = 0; j <= n; j++){
      P[j] = make_pair(x[j], y[j]);
    }
    sort(P.begin(), P.end());
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (P[j + 1].first < P[j].first || P[j + 1].second < P[j].second){
        ok = false;
      }
    }
    if (!ok){
      cout << "NO" << endl;
    } else {
      string ans;
      for (int j = 0; j < n; j++){
        for (int k = 0; k < P[j + 1].first - P[j].first; k++){
          ans += 'R';
        }
        for (int k = 0; k < P[j + 1].second - P[j].second; k++){
          ans += 'U';
        }
      }
      cout << "YES" << endl;
      cout << ans << endl;
    }
  }
}
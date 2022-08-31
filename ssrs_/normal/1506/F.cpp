#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<pair<int, int>> P(n + 1);
    P[0] = make_pair(1, 1);
    for (int j = 1; j <= n; j++){
      cin >> P[j].first;
    }
    for (int j = 1; j <= n; j++){
      cin >> P[j].second;
    }
    sort(P.begin(), P.end());
    long long ans = 0;
    for (int j = 0; j < n; j++){
      int r1 = P[j].first;
      int c1 = P[j].second;
      int r2 = P[j + 1].first;
      int c2 = P[j + 1].second;
      if ((r1 - c1) % 2 == 0){
        if (r1 - c1 == r2 - c2){
          ans += r2 - r1;
        } else {
          ans += ((r2 - c2) - (r1 - c1)) / 2;
        }
      } else {
        ans += ((r2 - c2) - (r1 - c1) + 1) / 2;
      }
    }
    cout << ans << endl;
  }
}
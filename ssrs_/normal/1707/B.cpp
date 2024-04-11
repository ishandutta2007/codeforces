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
    vector<pair<int, int>> P;
    P.push_back(make_pair(a[0], 1));
    for (int j = 1; j < n; j++){
      if (a[j] == a[j - 1]){
        P.back().second++;
      } else {
        P.push_back(make_pair(a[j], 1));
      }
    }
    for (int j = 0; j < n - 1; j++){
      int m = P.size();
      int zero = 0;
      vector<int> b;
      for (int k = 0; k < m; k++){
        zero += P[k].second - 1;
      }
      for (int k = 0; k < m - 1; k++){
        b.push_back(P[k + 1].first - P[k].first);
      }
      sort(b.begin(), b.end());
      P.clear();
      if (zero > 0){
        P.push_back(make_pair(0, zero));
      }
      int cnt = b.size();
      if (cnt > 0){
        P.push_back(make_pair(b[0], 1));
        for (int k = 1; k < cnt; k++){
          if (b[k] == b[k - 1]){
            P.back().second++;
          } else {
            P.push_back(make_pair(b[k], 1));
          }
        }
      }
    }
    cout << P[0].first << endl;
  }
}
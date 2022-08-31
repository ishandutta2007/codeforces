#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> h(n), w(n);
    for (int j = 0; j < n; j++){
      cin >> h[j] >> w[j];
    }
    vector<int> L(n * 2);
    for (int j = 0; j < n; j++){
      L[j * 2] = h[j];
      L[j * 2 + 1] = w[j];
    }
    sort(L.begin(), L.end());
    L.erase(unique(L.begin(), L.end()), L.end());
    for (int j = 0; j < n; j++){
      h[j] = lower_bound(L.begin(), L.end(), h[j]) - L.begin();
      w[j] = lower_bound(L.begin(), L.end(), w[j]) - L.begin();
    }
    int cnt = L.size();
    vector<pair<int, int>> M(cnt, make_pair(INF, INF));
    for (int j = 0; j < n; j++){
      M[w[j]] = min(M[w[j]], make_pair(h[j], j));
    }
    for (int j = 1; j < cnt; j++){
      M[j] = min(M[j], M[j - 1]);
    }
    for (int j = 0; j < n; j++){
      int ans = -2;
      if (w[j] > 0){
        if (M[w[j] - 1].first < h[j]){
          ans = M[w[j] - 1].second;
        }
      }
      if (h[j] > 0){
        if (M[h[j] - 1].first < w[j]){
          ans = M[h[j] - 1].second;
        }
      }
      cout << ans + 1;
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
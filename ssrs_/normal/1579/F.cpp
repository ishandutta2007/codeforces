#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int ans = 0;
    vector<bool> used(n, false);
    for (int j = 0; j < n; j++){
      if (!used[j]){
        used[j] = true;
        int v = j;
        vector<int> b;
        b.push_back(a[j]);
        while (true){
          int w = (v + d) % n;
          if (used[w]){
            break;
          }
          used[w] = true;
          b.push_back(a[w]);
          v = w;
        }
        int cnt = b.size();
        vector<int> p;
        for (int j = 0; j < cnt; j++){
          if (b[j] == 0){
            p.push_back(j);
          }
        }
        if (p.empty()){
          ans = INF;
        } else {
          int cnt2 = p.size();
          for (int j = 0; j < cnt2 - 1; j++){
            ans = max(ans, p[j + 1] - p[j] - 1);
          }
          ans = max(ans, p[0] + cnt - p[cnt2 - 1] - 1);
        }
      }
    }
    if (ans == INF){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
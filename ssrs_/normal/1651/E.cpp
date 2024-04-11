#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> E(n * 2);
  for (int i = 0; i < n * 2; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  long long ans = 0;
  vector<bool> used(n * 2, false);
  for (int i = 0; i < n; i++){
    if (!used[i]){
      int v = i;
      used[v] = true;
      vector<int> id;
      while (true){
        id.push_back(v);
        bool ok = false;
        for (int w : E[v]){
          if (!used[w]){
            used[w] = true;
            v = w;
            ok = true;
            break;
          }
        }
        if (!ok){
          break;
        }
      }
      int cnt = id.size();
      id.resize(cnt * 2);
      for (int j = 0; j < cnt; j++){
        id[cnt + j] = id[j];
      }
      for (int j = 0; j < cnt; j++){
        int mnl, mxl, mnr, mxr;
        if (id[j] < n){
          mnl = id[j];
          mxl = id[j];
          mnr = id[j + 1];
          mxr = id[j + 1];
        } else {
          mnl = id[j + 1];
          mxl = id[j + 1];
          mnr = id[j];
          mxr = id[j];
        }
        for (int k = j + 2; k <= j + cnt; k++){
          if ((k - j) % 2 == 0){
            ans += (long long) (mnl + 1) * (n - mxl) * (mnr - n + 1) * (n * 2 - mxr);
          } else {
            ans -= (long long) (mnl + 1) * (n - mxl) * (mnr - n + 1) * (n * 2 - mxr);
          }
          if (k == j + cnt){
            break;
          }
          if (id[k] < n){
            mnl = min(mnl, id[k]);
            mxl = max(mxl, id[k]);
          } else {
            mnr = min(mnr, id[k]);
            mxr = max(mxr, id[k]);
          }
        }
        if (j == 0){
          ans -= (long long) (cnt / 2) * (mnl + 1) * (n - mxl) * (mnr - n + 1) * (n * 2 - mxr);
        }
      }
    }
  }
  cout << ans << endl;
}
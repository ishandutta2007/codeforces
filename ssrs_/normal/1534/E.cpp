#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> E(n + 1);
  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= min(i, k); j++){
      if (k - j <= n - i){
        int i2 = (i - j) + (k - j);
        E[i].push_back(i2);
      }
    }
  }
  vector<int> d(n + 1, -1);
  d[0] = 0;
  vector<int> p(n + 1);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (d[w] == -1){
        d[w] = d[v] + 1;
        p[w] = v;
        Q.push(w);
      }
    }
  }
  if (d[n] == -1){
    cout << -1 << endl;
  } else {
    vector<int> id;
    for (int v = n; v != 0; v = p[v]){
      id.push_back(v);
    }
    id.push_back(0);
    reverse(id.begin(), id.end());
    vector<bool> used(n, false);
    int m = id.size() - 1;
    int ans = 0;
    for (int i = 0; i < m; i++){
      int cnt1, cnt2;
      for (int j = 0; j <= min(k, id[i]); j++){
        if (k - j <= n - id[i]){
          int i2 = (id[i] - j) + (k - j);
          if (i2 == id[i + 1]){
            cnt1 = j;
            cnt2 = k - j;
          }
        }
      }
      vector<int> b;
      for (int j = 0; j < n; j++){
      if (used[j] && cnt1 > 0){
          b.push_back(j);
          cnt1--;
        }
        if (!used[j] && cnt2 > 0){
          b.push_back(j);
          cnt2--;
        }
      }
      cout << "?";
      for (int j = 0; j < k; j++){
        cout << ' ' << b[j] + 1;
      }
      cout << endl;
      int x;
      cin >> x;
      ans ^= x;
      for (int j = 0; j < k; j++){
        used[b[j]] = !used[b[j]];
      }
    }
    cout << "! " << ans << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(q), b(q), x(q);
  for (int i = 0; i < q; i++){
    cin >> a[i] >> b[i] >> x[i];
    a[i]--;
    b[i]--;
  }
  vector<vector<int>> id(n);
  for (int i = 0; i < q; i++){
    if (a[i] != b[i]){
      id[a[i]].push_back(i);
      id[b[i]].push_back(i);
    }
  }
  vector<bool> ok(n, true);
  vector<int> mn(n, 0);
  vector<int> mx(n, (1 << 30) - 1);
  for (int i = 0; i < q; i++){
    if (a[i] == b[i]){
      mn[a[i]] = x[i];
      mx[a[i]] = x[i];
    } else {
      mx[a[i]] &= x[i];
      mx[b[i]] &= x[i];
      ok[a[i]] = false;
      ok[b[i]] = false;
    }
  }
  queue<int> Q;
  for (int i = 0; i < n; i++){
    if (!ok[i]){
      Q.push(i);
    }
  }
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    if (!ok[v]){
      ok[v] = true;
      for (int i : id[v]){
        int w = v ^ a[i] ^ b[i];
        int s = x[i];
        int mn2 = mn[w] | (s & ~mx[v]);
        if (mn2 > mn[w]){
          ok[w] = false;
          mn[w] = mn2;
          Q.push(w);
        }
      }
    }
  }
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++){
    for (int j = 29; j >= 0; j--){
      if ((mn[i] >> j & 1) == 1){
        ans[i] += 1 << j;
      } else if ((mx[i] >> j & 1) == 1){
        mx[i] &= ~(1 << j);
        ok[i] = false;
        Q.push(i);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          if (!ok[v]){
            ok[v] = true;
            for (int i : id[v]){
              int w = v ^ a[i] ^ b[i];
              int s = x[i];
              int mn2 = mn[w] | (s & ~mx[v]);
              if (mn2 > mn[w]){
                ok[w] = false;
                mn[w] = mn2;
                Q.push(w);
              }
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}
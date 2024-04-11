#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  vector<int> b;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    b.push_back(v);
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  reverse(b.begin(), b.end());
  vector<vector<int>> dp1(n, vector<int>(k * 2, 0));
  for (int v : b){
    dp1[v][0] = a[v];
    for (int w : c[v]){
      for (int i = 0; i < k * 2; i++){
        dp1[v][(i + 1) % (k * 2)] ^= dp1[w][i];
      }
    }
  }
  reverse(b.begin(), b.end());
  vector<vector<int>> dp2(n, vector<int>(k * 2, 0));
  for (int v : b){
    vector<int> tmp = dp2[v];
    tmp[0] ^= a[v];
    for (int w : c[v]){
      for (int i = 0; i < k * 2; i++){
        tmp[(i + 1) % (k * 2)] ^= dp1[w][i];
      }
    }
    for (int w : c[v]){
      for (int i = 0; i < k * 2; i++){
        tmp[(i + 1) % (k * 2)] ^= dp1[w][i];
      }
      for (int i = 0; i < k * 2; i++){
        dp2[w][(i + 1) % (k * 2)] ^= tmp[i];
      }
      for (int i = 0; i < k * 2; i++){
        tmp[(i + 1) % (k * 2)] ^= dp1[w][i];
      }
    }
  }
  for (int i = 0; i < n; i++){
    int x = 0;
    for (int j = k; j < k * 2; j++){
      x ^= dp1[i][j];
      x ^= dp2[i][j];
    }
    if (x == 0){
      cout << 0;
    } else {
      cout << 1;
    }
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}
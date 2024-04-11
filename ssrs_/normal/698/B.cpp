#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n; i++){
    E[i].push_back(a[i]);
    E[a[i]].push_back(i);
  }
  vector<int> c(n, -1);
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (c[i] == -1){
      c[i] = cnt;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (c[w] == -1){
            c[w] = cnt;
            Q.push(w);
          }
        }
      }
      cnt++;
    }
  }
  vector<int> d(n);
  for (int i = 0; i < n; i++){
    d[i] = E[i].size();
  }
  vector<bool> cycle(n, true);
  queue<int> Q2;
  for (int i = 0; i < n; i++){
    if (d[i] == 1){
      Q2.push(i);
      cycle[i] = false;
    }
  }
  while (!Q2.empty()){
    int v = Q2.front();
    Q2.pop();
    for (int w : E[v]){
      d[w]--;
      if (d[w] == 1){
        cycle[w] = false;
        Q2.push(w);
      }
    }
  }
  vector<vector<int>> cp(cnt);
  for (int i = 0; i < n; i++){
    if (cycle[i]){
      cp[c[i]].push_back(i);
    }
  }
  int m = 0;
  int r = -1;
  for (int i = 0; i < n; i++){
    if (a[i] == i){
      r = i;
    }
  }
  if (r == -1){
    r = cp[0][0];
    a[r] = r;
    m++;
  }
  for (int i = 0; i < cnt; i++){
    if (i != c[r]){
      a[cp[i][0]] = r;
      m++;
    }
  }
  cout << m << endl;
  for (int i = 0; i < n; i++){
    cout << a[i] + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}
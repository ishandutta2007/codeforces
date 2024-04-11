#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> d(n);
  for (int i = 0; i < n; i++){
    d[i] = E[i].size();
  }
  queue<int> Q;
  for (int i = 0; i < n; i++){
    if (d[i] == 1){
      Q.push(i);
    }
  }
  vector<int> t;
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    t.push_back(v);
    for (int w : E[v]){
      d[w]--;
      if (d[w] == 1){
        Q.push(w);
      }
    }
  }
  reverse(t.begin(), t.end());
  int r = t[0];
  vector<int> p(n, -1);
  queue<int> Q2;
  Q2.push(r);
  while (!Q2.empty()){
    int v = Q2.front();
    Q2.pop();
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        Q2.push(w);
      }
    }
  }
  cout << "? " << n;
  for (int i = 0; i < n; i++){
    cout << ' ' << i + 1;
  }
  cout << endl;
  int M;
  cin >> M;
  int tv = n, fv = 1;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    cout << "? " << mid;
    for (int i = 0; i < mid; i++){
      cout << ' ' << t[i] + 1;
    }
    cout << endl;
    int x;
    cin >> x;
    if (x == M){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  int a = t[tv - 1];
  int b = p[a];
  cout << "! " << a + 1 << ' ' << b + 1 << endl;
}
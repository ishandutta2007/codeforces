#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int f(int x){
  if (__builtin_popcount(x) == 1){
    return 0;
  }
  return (1 << (32 - __builtin_clz(x))) - x;
}
vector<int> bfs(vector<vector<int>> &E, int s){
  int V = E.size();
  vector<int> d(V, -1);
  d[s] = 0;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (d[w] == -1){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
  }
  return d;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b;
  for (int i = 0; i < n; i++){
    int x = a[i];
    while (x > 0){
      b.push_back(x);
      x = f(x);
    }
  }
  b.push_back(0);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for (int i = 0; i < n; i++){
    a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
  }
  int V = b.size();
  vector<int> p(V, -1);
  for (int i = 1; i < V; i++){
    p[i] = lower_bound(b.begin(), b.end(), f(b[i])) - b.begin();
  }
  vector<vector<int>> E(V);
  for (int i = 1; i < V; i++){
    E[p[i]].push_back(i);
    E[i].push_back(p[i]);
  }
  vector<int> d1 = bfs(E, a[0]);
  int s = 0;
  for (int i = 1; i < n; i++){
    if (d1[a[i]] > d1[a[s]]){
      s = i;
    }
  }
  vector<int> d2 = bfs(E, a[s]);
  int t = s;
  for (int i = 0; i < n; i++){
    if (d2[a[i]] > d2[a[t]]){
      t = i;
    }
  }
  cout << s + 1 << ' ' << t + 1 << ' ' << d2[a[t]] << endl;
}
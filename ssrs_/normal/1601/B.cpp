#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int, int>>> &E, int L, int R, int x, int i, int l, int r){
  if (r <= L || R <= l){
    return;
  } else if (L <= l && r <= R){
    E[x].push_back(make_pair(1, i));
  } else {
    int m = (l + r) / 2;
    dfs(E, L, R, x, i * 2 + 1, l, m);
    dfs(E, L, R, x, i * 2 + 2, m, r);
  }
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  int n2 = 1;
  while (n2 < n + 1){
    n2 *= 2;
  }
  vector<vector<pair<int, int>>> E(n2 * 2 - 1 + n + 1);
  for (int i = 0; i < n2 - 1; i++){
    E[i].push_back(make_pair(0, i * 2 + 1));
    E[i].push_back(make_pair(0, i * 2 + 2));
  }
  for (int i = 0; i < n; i++){
    dfs(E, i + 1 - a[i], i + 2, n2 * 2 - 1 + i + 1, 0, 0, n2);
  }
  for (int i = 0; i < n; i++){
    E[n2 - 1 + i + 1].push_back(make_pair(0, n2 * 2 - 1 + i + 1 + b[i]));
  }
  int V = n2 * 2 - 1 + n + 1;
  int s = n2 * 2 - 1 + n, t = n2 - 1;
  vector<int> d(V, -1);
  deque<pair<int, int>> dq;
  dq.push_back(make_pair(0, s));
  vector<int> R;
  while (!dq.empty()){
    int c = dq.front().first;
    int v = dq.front().second;
    dq.pop_front();
    if (d[v] == -1){
      d[v] = c;
      R.push_back(v);
      for (auto P : E[v]){
        int w = P.second;
        if (d[w] == -1){
          if (P.first == 0){
            dq.push_front(make_pair(c, w));
          } else {
            dq.push_back(make_pair(c + 1, w));
          }
        }
      }
    }
  }
  vector<int> pr(V, -1);
  for (int v : R){
    for (auto P : E[v]){
      int w = P.second;
      if (d[w] == d[v] + P.first){
        pr[w] = v;
      }
    }
  }
  if (d[t] == -1){
    cout << -1 << endl;
  } else {
    vector<int> C;
    int v = t;
    while (v != s){
      if (n2 -1 <= v && v < n2 * 2 - 1){
        C.push_back(v - (n2 - 1));
      }
      v = pr[v];
    }
    int k = d[t];
    reverse(C.begin(), C.end());
    cout << k << endl;
    for (int i = 0; i < k; i++){
      cout << C[i];
      if (i < k - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000002;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> mx(MAX, -1);
  for (int i = 2; i < MAX; i++){
    if (mx[i] == -1){
      for (int j = i * 2; j < MAX; j += i){
        mx[j] = i;
      }
    }
  }
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> prime;
  vector<int> prime_id(MAX);
  for (int i = 2; i < MAX; i++){
    if (mx[i] == -1){
      prime_id[i] = prime.size();
      prime.push_back(i);
    }
  }
  int cnt = prime.size();
  vector<vector<int>> F1(n);
  for (int i = 0; i < n; i++){
    int x = a[i];
    while (mx[x] != -1){
      F1[i].push_back(prime_id[mx[x]]);
      x /= mx[x];
    }
    F1[i].push_back(prime_id[x]);
    sort(F1[i].begin(), F1[i].end());
    F1[i].erase(unique(F1[i].begin(), F1[i].end()), F1[i].end());
  }
  vector<vector<int>> F2(n);
  for (int i = 0; i < n; i++){
    int x = a[i] + 1;
    while (mx[x] != -1){
      F2[i].push_back(prime_id[mx[x]]);
      x /= mx[x];
    }
    F2[i].push_back(prime_id[x]);
    sort(F2[i].begin(), F2[i].end());
    F2[i].erase(unique(F2[i].begin(), F2[i].end()), F2[i].end());
  }
  int V = n + cnt;
  vector<vector<int>> E(V);
  for (int i = 0; i < n; i++){
    for (int j : F1[i]){
      E[i].push_back(n + j);
      E[n + j].push_back(i);
    }
  }
  vector<int> c(V, -1);
  int cc = 0;
  for (int i = 0; i < V; i++){
    if (c[i] == -1){
      c[i] = cc;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (c[w] == -1){
            c[w] = cc;
            Q.push(w);
          }
        }
      }
      cc++;
    }
  }
  vector<pair<int, int>> P;
  for (int i = 0; i < n; i++){
    for (int x : F1[i]){
      for (int y : F2[i]){
        if (c[n + x] != c[n + y]){
          P.push_back(minmax(c[n + x], c[n + y]));
        }
      }
    }
    for (int x : F1[i]){
      for (int y : F1[i]){
        if (c[n + x] != c[n + y]){
          P.push_back(minmax(c[n + x], c[n + y]));
        }
      }
    }
    for (int x : F2[i]){
      for (int y : F2[i]){
        if (c[n + x] != c[n + y]){
          P.push_back(minmax(c[n + x], c[n + y]));
        }
      }
    }
  }
  sort(P.begin(), P.end());
  P.erase(unique(P.begin(), P.end()), P.end());
  for (int i = 0; i < q; i++){
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    if (c[s] == c[t]){
      cout << 0 << "\n";
    } else {
      pair<int, int> P2 = minmax(c[s], c[t]);
      if (binary_search(P.begin(), P.end(), P2)){
        cout << 1 << "\n";
      } else {
        cout << 2 << "\n";
      }
    }
  }
}
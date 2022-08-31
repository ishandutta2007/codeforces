#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
      b[j]--;
    }
    vector<int> cnt(n, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    int mx = 0;
    for (int j = 0; j < n; j++){
      mx = max(mx, cnt[j]);
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < n; j++){
      E[a[j]].push_back(b[j]);
    }
    vector<int> cycle;
    vector<int> time(n, -1);
    for (int j = 0; j < n; j++){
      if (!E[j].empty()){
        time[j] = 0;
        cycle.push_back(j);
        break;
      }
    }
    while (true){
      int v = cycle.back();
      int w = E[v][0];
      if (time[w] != -1){
        break;
      }
      time[w] = cycle.size();
      cycle.push_back(w);
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (cnt[j] == mx && time[j] == -1){
        ok = false;
      }
    }
    if (!ok){
      cout << "WA" << endl;
    } else {
      vector<pair<int, int>> P;
      for (int j = 0; j < n; j++){
        if (cnt[j] == mx){
          P.push_back(make_pair(time[j], j));
        }
      }
      sort(P.begin(), P.end());
      int big = P.size();
      vector<int> id(n, -1);
      for (int j = 0; j < big; j++){
        id[P[j].second] = j;
      }
      queue<pair<int, int>> Q;
      vector<int> p(n, -1);
      for (int j = 0; j < n; j++){
        if (cnt[j] == mx){
          p[j] = id[j];
          Q.push(make_pair(j, id[j]));
        }
      }
      while (!Q.empty()){
        int v = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        for (int w : E[v]){
          if (cnt[w] != mx){
            if (p[w] != -1 && p[w] != c){
              ok = false;
            } else if (p[w] == -1){
              p[w] = c;
              Q.push(make_pair(w, c));
            }
          } else {
            if (id[w] != (c + 1) % big){
              ok = false;
            }
          }
        }
      }
      vector<vector<int>> E2(n);
      for (int j = 0; j < n; j++){
        if (cnt[a[j]] != mx && cnt[b[j]] != mx){
          E2[a[j]].push_back(b[j]);
        }
      }
      vector<int> in(n, 0);
      for (int j = 0; j < n; j++){
        for (int k : E2[j]){
          in[k]++;
        }
      }
      queue<int> Q2;
      for (int j = 0; j < n; j++){
        if (in[j] == 0){
          Q2.push(j);
        }
      }
      while (!Q2.empty()){
        int v = Q2.front();
        Q2.pop();
        for (int w : E2[v]){
          in[w]--;
          if (in[w] == 0){
            Q2.push(w);
          }
        }
      }
      if (in != vector<int>(n, 0)){
        ok = false;
      }
      if (ok){
        cout << "AC" << endl;
      } else {
        cout << "WA" << endl;
      }
    }
  }
}
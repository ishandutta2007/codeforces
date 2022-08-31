#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++){
    mp[h[i]].push_back(i);
  }
  vector<vector<int>> R;
  for (auto P : mp){
    R.push_back(P.second);
  }
  int sz = R.size();
  vector<vector<int>> E(n);
  set<int> st1;
  for (int i = 0; i < sz; i++){
    for (int j : R[i]){
      st1.insert(j);
    }
    for (int j : R[i]){
      if (*st1.begin() != j){
        int a = *prev(st1.lower_bound(j));
        E[a].push_back(j);
      }
      if (*st1.rbegin() != j){
        int b = *st1.upper_bound(j);
        E[j].push_back(b);
      }
    }
  }
  set<int> st2;
  for (int i = sz - 1; i >= 0; i--){
    for (int j : R[i]){
      st2.insert(j);
    }
    for (int j : R[i]){
      if (*st2.begin() != j){
        int a = *prev(st2.lower_bound(j));
        E[a].push_back(j);
      }
      if (*st2.rbegin() != j){
        int b = *st2.upper_bound(j);
        E[j].push_back(b);
      }
    }
  }
  for (int i = 0; i < n - 1; i++){
    E[i].push_back(i + 1);
  }
  vector<int> d(n, -1);
  d[0] = 0;
  queue<int> Q;
  Q.push(0);
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
  cout << d[n - 1] << endl;
}
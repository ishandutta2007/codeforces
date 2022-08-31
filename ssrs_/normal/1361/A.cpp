#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vector<int> t(n);
  for (int i = 0; i < n; i++){
    cin >> t[i];
  }
  vector<pair<int, int>> t2(n);
  for (int i = 0; i < n; i++){
    t2[i] = make_pair(t[i], i);
  }
  sort(t2.begin(), t2.end());
  vector<int> st(n, 1);
  vector<bool> used(n, false);
  vector<int> p(n);
  bool ok = true;
  for (int i = 0; i < n; i++){
    int topic = t2[i].first;
    int id = t2[i].second;
    used[id] = true;
    if (st[id] != topic){
      ok = false;
      break;
    } else {
      p[i] = id;
      for (int j : E[id]){
        if (st[j] == topic && !used[j]){
          st[j]++;
        }
      }
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++){
      cout << p[i] + 1;
      if (i < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
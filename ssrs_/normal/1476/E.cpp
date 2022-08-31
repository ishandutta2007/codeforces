#include <bits/stdc++.h>
using namespace std;
bool match(string p, string s, int k){
  for (int i = 0; i < k; i++){
    if (p[i] != s[i] && p[i] != '_'){
      return false;
    }
  }
  return true;
}
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  vector<string> s(m);
  vector<int> mt(m);
  for (int i = 0; i < m; i++){
    cin >> s[i] >> mt[i];
    mt[i]--;
  }
  map<string, int> mp;
  for (int i = 0; i < n; i++){
    mp[p[i]] = i;
  }
  for (int i = 0; i < m; i++){
    if (!match(p[mt[i]], s[i], k)){
      cout << "NO" << endl;
      return 0;
    }
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    for (int j = 0; j < (1 << k); j++){
      string p2 = s[i];
      for (int l = 0; l < k; l++){
        if (j >> l & 1){
          p2[l] = '_';
        }
      }
      if (mp.count(p2)){
        int id = mp[p2];
        if (id != mt[i]){
          E[mt[i]].push_back(id);
        }
      }
    }
  }
  vector<int> d(n, 0);
  for (int i = 0; i < n; i++){
    for (int j : E[i]){
      d[j]++;
    }
  }
  queue<int> Q;
  for (int i = 0; i < n; i++){
    if (d[i] == 0){
      Q.push(i);
    }
  }
  vector<int> b;
  while (!Q.empty()){
    int v = Q.front();
    b.push_back(v);
    Q.pop();
    for (int w : E[v]){
      d[w]--;
      if (d[w] == 0){
        Q.push(w);
      }
    }
  }
  if (b.size() != n){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++){
      cout << b[i] + 1;
      if (i < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
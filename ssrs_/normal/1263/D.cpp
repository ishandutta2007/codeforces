#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<vector<int>> L(26);
  for (int i = 0; i < n; i++){
    int l = s[i].size();
    for (int j = 0; j < l; j++){
      L[s[i][j] - 'a'].push_back(i);
    }
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < 26; i++){
    sort(L[i].begin(), L[i].end());
    L[i].erase(unique(L[i].begin(), L[i].end()), L[i].end());
    int cnt = L[i].size();
    for (int j = 0; j < cnt - 1; j++){
      E[L[i][j]].push_back(L[i][j + 1]);
      E[L[i][j + 1]].push_back(L[i][j]);
    }
  }
  int ans = 0;
  vector<bool> used(n, false);
  for (int i = 0; i < n; i++){
    if (!used[i]){
      used[i] = true;
      ans++;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (!used[w]){
            used[w] = true;
            Q.push(w);
          }
        }
      }
    }
  }
  cout << ans << endl;
}
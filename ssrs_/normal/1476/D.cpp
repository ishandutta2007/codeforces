#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> E((n + 1) * 2);
    for (int j = 0; j < n; j++){
      if (s[j] == 'L'){
        E[j + 1].push_back(n + 1 + j);
        E[n + 1 + j].push_back(j + 1);
      }
      if (s[j] == 'R'){
        E[j].push_back(n + 1 + j + 1);
        E[n + 1 + j + 1].push_back(j);
      }
    }
    int cnt = 0;
    vector<int> c((n + 1) * 2, -1);
    vector<int> sz;
    for (int j = 0; j < (n + 1) * 2; j++){
      if (c[j] == -1){
        c[j] = cnt;
        sz.push_back(1);
        queue<int> Q;
        Q.push(j);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          for (int w : E[v]){
            if (c[w] == -1){
              c[w] = cnt;
              sz.back()++;
              Q.push(w);
            }
          }
        }
        cnt++;
      }
    }
    for (int j = 0; j <= n; j++){
      cout << sz[c[j]];
      if (j < n){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
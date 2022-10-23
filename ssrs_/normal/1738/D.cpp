#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<int> s(n + 2, 0);
    for (int j = 0; j < n; j++){
      s[b[j]]++;
    }
    for (int j = 1; j <= n + 1; j++){
      s[j] += s[j - 1];
    }
    int k;
    for (int j = 0; j <= n; j++){
      if (j + s[j] == n){
        k = j;
      }
    }
    vector<vector<int>> pos(n + 2);
    for (int j = 0; j < n; j++){
      pos[b[j]].push_back(j + 1);
    }
    queue<int> Q;
    Q.push(0);
    Q.push(n + 1);
    vector<int> a;
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : pos[v]){
        if (pos[w].empty()){
          a.push_back(w);
          Q.push(w);
        }
      }
      for (int w : pos[v]){
        if (!pos[w].empty()){
          a.push_back(w);
          Q.push(w);
        }
      }
    }
    cout << k << endl;
    for (int j = 0; j < n; j++){
      cout << a[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
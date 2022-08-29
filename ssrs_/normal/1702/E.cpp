#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> E(n);
    for (int j = 0; j < n; j++){
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      E[a].push_back(b);
      E[b].push_back(a);
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (E[j].size() >= 3){
        ok = false;
      }
      for (int k : E[j]){
        if (k == j){
          ok = false;
        }
      }
    }
    vector<bool> used(n, false);
    for (int j = 0; j < n; j++){
      if (!used[j]){
        used[j] = true;
        queue<int> Q;
        Q.push(j);
        int cv = 0, ce = 0;
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          cv++;
          for (int w : E[v]){
            ce++;
            if (!used[w]){
              used[w] = true;
              Q.push(w);
            }
          }
        }
        ce /= 2;
        if (ce == cv && cv % 2 == 1){
          ok = false;
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
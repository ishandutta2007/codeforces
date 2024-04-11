#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<set<int>> E(n);
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].insert(b);
    E[b].insert(a);
  }
  int ans = 0;
  set<int> unused;
  for (int i = 0; i < n; i++){
    unused.insert(i);
  }
  for (int i = 0; i < n; i++){
    if (unused.count(i)){
      ans++;
      unused.erase(i);
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        vector<int> used;
        for (int w : unused){
          if (!E[v].count(w)){
            used.push_back(w);
          }
        }
        for (int w : used){
          unused.erase(w);
          Q.push(w);
        }
      }
    }
  }
  cout << ans - 1 << endl;
}
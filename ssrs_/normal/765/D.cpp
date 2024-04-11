#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> f(n);
  for (int i = 0; i < n; i++){
    cin >> f[i];
    f[i]--;
  }
  vector<bool> same(n, false);
  for (int i = 0; i < n; i++){
    if (f[i] == i){
      same[i] = true;
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++){
    if (!same[f[i]]){
      ok = false;
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    vector<int> p;
    for (int i = 0; i < n; i++){
      if (same[i]){
        p.push_back(i);
      }
    }
    int m = p.size();
    vector<int> id(n);
    for (int i = 0; i < m; i++){
      id[p[i]] = i;
    }
    vector<int> g(n);
    for (int i = 0; i < n; i++){
      g[i] = id[f[i]];
    }
    vector<int> h = p;
    cout << m << endl;
    for (int i = 0; i < n; i++){
      cout << g[i] + 1;
      if (i < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
    for (int i = 0; i < m; i++){
      cout << h[i] + 1;
      if (i < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
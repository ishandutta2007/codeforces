#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> f(n + 1, -1);
  for (int i = 2; i <= n; i++){
    if (f[i] == -1){
      for (int j = i; j <= n; j += i){
        if (f[j] == -1){
          f[j] = i;
        }
      }
    }
  }
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++){
    g[f[i]].push_back(i);
  }
  set<int> st;
  for (int j = 1; j <= n; j++){
    st.insert(j);
  }
  vector<int> a, b;
  int m = 0;
  for (int i = n; i >= 0; i--){
    int cnt = g[i].size();
    vector<int> g2;
    for (int j = 0; j < cnt; j++){
      if (st.count(g[i][j])){
        g2.push_back(g[i][j]);
      }
    }
    int cnt2 = g2.size();
    for (int j = 0; j + 1 < cnt2; j += 2){
      a.push_back(g2[j]);
      b.push_back(g2[j + 1]);
      st.erase(g2[j]);
      st.erase(g2[j + 1]);
      m++;
    }
    if (cnt2 % 2 == 1){
      int x = g2.back();
      for (int j = i; j <= n; j += i){
        if (st.count(j) && j != x){
          a.push_back(x);
          b.push_back(j);
          m++;
          st.erase(x);
          st.erase(j);
          break;
        }
      }
    }
  }
  cout << m << endl;
  for (int i = 0; i < m; i++){
    cout << a[i] << ' ' << b[i] << endl;
  }
}
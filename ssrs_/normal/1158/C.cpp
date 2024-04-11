#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &c, vector<int> &q, int v){
  q.push_back(v);
  for (int w : c[v]){
    dfs(c, q, w);
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> next(n);
    for (int j = 0; j < n; j++){
      cin >> next[j];
      if (next[j] > 0){
        next[j]--;
      }
      if (next[j] == -1){
        next[j] = j + 1;
      }
    }
    vector<vector<int>> c(n + 1);
    for (int j = 0; j < n; j++){
      c[next[j]].push_back(j);
    }
    stack<int> st;
    bool ok = true;
    for (int j = 0; j < n; j++){
      int cnt = c[j].size();
      for (int k = cnt - 1; k >= 0; k--){
        if (st.empty()){
          ok = false;
          break;
        }
        if (st.top() != c[j][k]){
          ok = false;
          break;
        }
        st.pop();
      }
      st.push(j);
      if (!ok){
        break;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      vector<int> q;
      dfs(c, q, n);
      vector<int> p(n);
      for (int j = 1; j <= n; j++){
        p[q[j]] = n - j;
      }
      for (int j = 0; j < n; j++){
        cout << p[j] + 1;
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<int> l(m), r(m);
    for (int j = 0; j < m; j++){
      cin >> l[j] >> r[j];
      l[j]--;
    }
    vector<long long> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    vector<long long> T(n + 1);
    T[0] = 0;
    for (int j = 0; j < n; j++){
      T[j + 1] = T[j] + b[j];
    }
    vector<vector<int>> seg(n + 1);
    for (int j = 0; j < m; j++){
      seg[l[j]].push_back(j);
      seg[r[j]].push_back(j);
    }
    vector<bool> used(n + 1, false);
    queue<int> Q;
    for (int j = 0; j <= n; j++){
      if (S[j] == T[j]){
        used[j] = true;
        Q.push(j);
      }
    }
    set<int> st;
    for (int j = 0; j <= n; j++){
      if (!used[j]){
        st.insert(j);
      }
    }
    st.insert(n + 1);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int j : seg[v]){
        if (used[l[j]] && used[r[j]]){
          while (true){
            auto itr = st.lower_bound(l[j]);
            if (*itr < r[j]){
              used[*itr] = true;
              Q.push(*itr);
              st.erase(itr);
            } else {
              break;
            }
          }
        }
      }
    }
    if (used == vector<bool>(n + 1, true)){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
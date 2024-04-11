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
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    vector<char> c(n);
    for (int j = 0; j < n; j++){
      cin >> c[j];
    }
    vector<tuple<int, char, int>> R(n);
    for (int j = 0; j < n; j++){
      R[j] = make_tuple(x[j], c[j], j);
    }
    sort(R.begin(), R.end());
    for (int j = 0; j < n; j++){
      x[j] = get<0>(R[j]);
      c[j] = get<1>(R[j]);
    }
    vector<int> ans(n, -1);
    for (int j = 0; j < 2; j++){
      vector<int> id;
      for (int k = 0; k < n; k++){
        if (x[k] % 2 == j){
          id.push_back(k);
        }
      }
      int cnt = id.size();
      vector<int> x2(cnt);
      vector<char> c2(cnt);
      for (int k = 0; k < cnt; k++){
        x2[k] = x[id[k]];
        c2[k] = c[id[k]];
      }
      stack<int> st;
      for (int k = 0; k < cnt; k++){
        if (!st.empty() && c2[k] == 'L'){
          int p = st.top();
          if (c2[p] == 'L'){
            int t = (x2[k] + x2[p]) / 2;
            ans[id[k]] = t;
            ans[id[p]] = t;
            st.pop();
          } else {
            int t = (x2[k] - x2[p]) / 2;
            ans[id[k]] = t;
            ans[id[p]] = t;
            st.pop();
          }
        } else {
          st.push(k);
        }
      }
      while (st.size() >= 2){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (c2[b] == 'R'){
          int t = m - (x2[a] + x2[b]) / 2;
          ans[id[a]] = t;
          ans[id[b]] = t;
        } else {
          int t = m - (x2[a] - x2[b]) / 2;
          ans[id[a]] = t;
          ans[id[b]] = t;
        }
      }
    }
    vector<int> ans2(n);
    for (int j = 0; j < n; j++){
      ans2[get<2>(R[j])] = ans[j];
    }
    for (int j = 0; j < n; j++){
      cout << ans2[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
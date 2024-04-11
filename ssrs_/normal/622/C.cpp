#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> l(m), r(m), x(m);
  for (int i = 0; i < m; i++){
    cin >> l[i] >> r[i] >> x[i];
    l[i]--;
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]].push_back(i);
  }
  map<int, vector<tuple<int, int, int>>> mp2;
  for (int i = 0; i < m; i++){
    mp2[x[i]].push_back(make_tuple(l[i], r[i], i));
  }
  set<int> st;
  for (int i = 0; i <= n; i++){
    st.insert(i);
  }
  vector<int> ans(m, -2);
  for (auto P : mp2){
    int X = P.first;
    if (mp.count(X) == 1){
      for (int j : mp[X]){
        st.erase(j);
      }
    }
    int cnt = P.second.size();
    for (int i = 0; i < cnt; i++){
      int L = get<0>(P.second[i]);
      int R = get<1>(P.second[i]);
      int id = get<2>(P.second[i]);
      auto itr = st.lower_bound(L);
      if (*itr < R){
        ans[id] = *itr;
      }
    }
    if (mp.count(X) == 1){
      for (int j : mp[X]){
        st.insert(j);
      }
    }
  }
  for (int i = 0; i < m; i++){
    cout << ans[i] + 1 << "\n";
  }
}
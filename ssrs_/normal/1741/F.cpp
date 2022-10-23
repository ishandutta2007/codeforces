#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> l(n), r(n), c(n);
    for (int j = 0; j < n; j++){
      cin >> l[j] >> r[j] >> c[j];
      c[j]--;
    }
    vector<vector<int>> id(n);
    for (int j = 0; j < n; j++){
      id[c[j]].push_back(j);
    }
    vector<int> ans(n, INF);
    for (int j = 0; j < 2; j++){
      set<int> st;
      for (int k = 0; k < n; k++){
        for (int x : id[k]){
          auto itr1 = st.lower_bound(l[x]);
          if (itr1 != st.end()){
            ans[x] = min(ans[x], *itr1 - l[x]);
          }
          if (itr1 != st.begin()){
            ans[x] = min(ans[x], l[x] - *prev(itr1));
          }
          auto itr2 = st.lower_bound(r[x]);
          if (itr2 != st.end()){
            ans[x] = min(ans[x], *itr2 - r[x]);
          }
          if (itr2 != st.begin()){
            ans[x] = min(ans[x], r[x] - *prev(itr2));
          }
        }
        for (int x : id[k]){
          st.insert(l[x]);
          st.insert(r[x]);
        }
      }
      reverse(id.begin(), id.end());
    }
    vector<int> x;
    for (int j = 0; j < n; j++){
      x.push_back(l[j]);
      x.push_back(r[j]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int j = 0; j < n; j++){
      l[j] = lower_bound(x.begin(), x.end(), l[j]) - x.begin();
      r[j] = lower_bound(x.begin(), x.end(), r[j]) - x.begin();
    }
    int cnt = x.size();
    vector<vector<int>> L(cnt), R(cnt);
    for (int j = 0; j < n; j++){
      L[l[j]].push_back(j);
      R[r[j]].push_back(j);
    }
    set<int> st;
    map<int, int> mp;
    for (int j = 0; j < cnt; j++){
      for (int k : L[j]){
        st.insert(k);
        mp[c[k]]++;
        if (mp.size() > 1){
          for (int a : st){
            ans[a] = 0;
          }
          st.clear();
        }
      }
      for (int k : R[j]){
        mp[c[k]]--;
        if (mp[c[k]] == 0){
          mp.erase(c[k]);
        }
        st.erase(k);
      }
    }
    for (int j = 0; j < n; j++){
      cout << ans[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
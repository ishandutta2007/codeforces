#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    map<int, int> mp;
    for (int j = 0; j < n; j++){
      mp[a[j]]++;
    }
    set<int> st;
    for (auto P : mp){
      if (P.second >= k){
        st.insert(P.first);
      }
    }
    if (st.empty()){
      cout << -1 << endl;
    } else {
      int mx = 0;
      int l = 0, r = 0;
      int cnt = 0;
      int pr = -1;
      for (int x : st){
        if (x == pr + 1){
          cnt++;
        } else {
          cnt = 1;
        }
        if (cnt > mx){
          mx = cnt;
          l = x - cnt + 1;
          r = x;
        }
        pr = x;
      }
      cout << l << ' ' << r << endl;
    }
  }
}
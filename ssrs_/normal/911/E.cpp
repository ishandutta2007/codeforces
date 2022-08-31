#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < k; i++){
    cin >> p[i];
    p[i]--;
  }
  set<int> st;
  for (int i = 0; i < n; i++){
    st.insert(i);
  }
  set<int> st2;
  st.erase(p[0]);
  st2.insert(p[0]);
  bool ok = true;
  for (int i = 1; i < k; i++){
    if (p[i] > p[i - 1]){
      auto itr = prev(st2.lower_bound(p[i]));
      if (*st.begin() < *itr){
        ok = false;
        break;
      } else {
        while (*st2.begin() < p[i]){
          st2.erase(st2.begin());
          if (st2.empty()){
            break;
          }
        }
      }
    }
    st2.insert(p[i]);
    st.erase(p[i]);
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    for (int i = k; i < n; i++){
      if (*st.begin() < p[i - 1]){
        p[i] = *prev(st.lower_bound(p[i - 1]));
      } else {
        auto itr = st2.lower_bound(*st.begin());
        if (itr == st2.end()){
          st2.clear();
          p[i] = *prev(st.end());
        } else {
          p[i] = *prev(st.lower_bound(*itr));
          while (*st2.begin() < p[i]){
            st2.erase(st2.begin());
            if (st2.empty()){
              break;
            }
          }
        }
      }
      st2.insert(p[i]);
      st.erase(p[i]);
    }
    for (int i = 0; i < n; i++){
      cout << p[i] + 1;
      if (i < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
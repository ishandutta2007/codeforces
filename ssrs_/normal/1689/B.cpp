#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    if (n == 1){
      cout << -1 << endl;
    } else {
      set<int> st;
      for (int j = 0; j < n; j++){
        st.insert(j);
      }
      vector<int> ans(n);
      for (int j = 0; j < n; j++){
        for (int x : st){
          bool ok = true;
          if (x == p[j]){
            ok = false;
          }
          if (j == n - 2){
            set<int> st2 = st;
            st2.erase(x);
            if (*st2.begin() == p[n - 1]){
              ok = false;
            }
          }
          if (ok){
            st.erase(x);
            ans[j] = x;
            break;
          }
        }
      }
      for (int j = 0; j < n; j++){
        cout << ans[j] + 1;
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}
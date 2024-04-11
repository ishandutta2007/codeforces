#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t;  i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int tv = 0, fv = n + 1;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      multiset<int> st;
      for (int j = 0; j < n; j++){
        st.insert(a[j]);
      }
      bool ok = true;
      for (int j = 0; j < mid; j++){
        int x = mid - j;
        while (!st.empty()){
          if (*prev(st.end()) > x){
            st.erase(prev(st.end()));
          } else {
            break;
          }
        }
        if (st.empty()){
          ok = false;
          break;
        }
        st.erase(prev(st.end()));
        if (!st.empty()){
          int a = *st.begin();
          st.erase(st.begin());
        }
      }
      if (ok){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}
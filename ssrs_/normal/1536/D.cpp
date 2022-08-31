#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    set<int> st;
    st.insert(b[0]);
    bool ok = true;
    for (int j = 1; j < n; j++){
      st.insert(b[j]);
      auto itr1 = st.lower_bound(b[j - 1]);
      auto itr2 = st.lower_bound(b[j]);
      if (b[j - 1] < b[j]){
        if (distance(itr1, itr2) >= 2){
          ok = false;
          break;
        }
      }
      if (b[j - 1] > b[j]){
        if (distance(itr2, itr1) >= 2){
          ok = false;
          break;
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
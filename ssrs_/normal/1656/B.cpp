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
    set<int> st;
    for (int j = 0; j < n; j++){
      st.insert(a[j]);
    }
    bool ok = false;
    for (int j = 0; j < n; j++){
      if (st.count(a[j] - k) == 1){
        ok = true;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
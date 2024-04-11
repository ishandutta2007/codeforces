#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int j = 0; j < n; j++){
      cin >> l[j] >> r[j];
    }
    set<pair<int, int>> st;
    for (int j = 0; j < n; j++){
      st.insert(make_pair(l[j], r[j]));
    }
    for (int j = 0; j < n; j++){
      for (int k = l[j]; k <= r[j]; k++){
        bool ok = true;
        if (k != l[j]){
          if (st.count(make_pair(l[j], k - 1)) == 0){
            ok = false;
          }
        }
        if (k != r[j]){
          if (st.count(make_pair(k + 1, r[j])) == 0){
            ok =  false;
          }
        }
        if (ok){
          cout << l[j] << ' ' << r[j] << ' ' << k << endl;
        }
      }
    }
  }
}
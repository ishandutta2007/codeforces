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
    if (k == 1){
      int mx = *max_element(a.begin(), a.end());
      int mn = *min_element(a.begin(), a.end());
      if (mx != mn){
        cout << -1 << endl;
      } else {
        cout << 1 << endl;
      }
    } else {
      set<int> st;
      for (int j = 0; j < n; j++){
        st.insert(a[j]);
      }
      int sz = st.size();
      cout << max((sz + k - 3) / (k - 1), 1) << endl;
    }
  }
}
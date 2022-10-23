#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
      a[j] -= j;
    }
    vector<vector<int>> p(n * 2 - 1);
    for (int j = 0; j < n; j++){
      p[a[j] + (n - 1)].push_back(j);
    }
    set<int> st;
    st.insert(n);
    long long ans = 0;
    for (int j = n - 1; j >= 0; j--){
      auto itr = st.lower_bound(j);
      ans += *itr - j;
      for (int k : p[n - 1 - j]){
        st.insert(k);
      }
    }
    cout << ans << "\n";
  }
}
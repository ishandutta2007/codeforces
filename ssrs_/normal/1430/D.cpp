#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(1, 1);
    for (int j = 1; j < n; j++){
      if (s[j] == s[j - 1]){
        a.back()++;
      } else {
        a.push_back(1);
      }
    }
    int m = a.size();
    set<int> st;
    for (int j = 0; j < m; j++){
      if (a[j] >= 2){
        st.insert(j);
      }
    }
    int L = 0;
    int ans = 0;
    while (1){
      if (st.empty()){
        ans += (m - L + 1) / 2;
        break;
      }
      a[*st.begin()]--;
      if (a[*st.begin()] == 1){
        st.erase(st.begin());
      }
      if (st.empty()){
        ans += (m - L) / 2 + 1;
        break;
      }
      if (a[L] >= 2){
        st.erase(L);
      }
      a[L] = 0;
      L++;
      ans++;
    }
    cout << ans << endl;
  }
}
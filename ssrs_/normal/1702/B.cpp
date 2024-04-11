#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    set<char> st;
    int ans = 1;
    for (int j = 0; j < n; j++){
      st.insert(s[j]);
      if (st.size() >= 4){
        ans++;
        st.clear();
        st.insert(s[j]);
      }
    }
    cout << ans << endl;
  }
}
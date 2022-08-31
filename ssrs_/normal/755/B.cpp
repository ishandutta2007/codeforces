#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<string> t(m);
  for (int i = 0; i < m; i++){
    cin >> t[i];
  }
  set<string> st;
  for (int i = 0; i < n; i++){
    st.insert(s[i]);
  }
  int c = 0;
  for (int i = 0; i < m; i++){
    if (st.count(t[i]) == 1){
      c++;
    }
  }
  if (c % 2 == 0){
    if (n > m){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    if (n >= m){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
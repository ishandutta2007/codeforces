#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  set<char> st;
  char M = s[0];
  char m = s[0];
  for (char c : s){
    st.insert(c);
    M = max(M, c);
    m = min(m, c);
  }
  vector<char> t(k);
  for (int i = 0; i < min(k, n); i++){
    t[i] = s[i];
  }
  if (k <= n){
    for (int i = k - 1; i >= 0; i--){
      if (t[i] == M){
        t[i] = m;
      } else {
        t[i] = *st.upper_bound(t[i]);
        break;
      }
    }
  } else {
    for (int i = n; i < k; i++){
      t[i] = m;
    }
  }
  for (int i = 0; i < k; i++){
    cout << t[i];
  }
  cout << endl;
}
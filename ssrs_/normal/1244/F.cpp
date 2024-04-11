#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s += s;
  s += s;
  set<int> st;
  for (int i = 0; i < n * 3 - 1; i++){
    if (s[i] == s[i + 1]){
      st.insert(i);
    }
  }
  string t = s.substr(0, n);
  if (st.empty()){
    if (k % 2 == 1){
      for (int i = 0; i < n; i++){
        if (t[i] == 'B'){
          t[i] = 'W';
        } else {
          t[i] = 'B';
        }
      }
    }
    cout << t << endl;
  } else {
    for (int i = 0; i < n; i++){
      if (s[i + n - 1] != s[i + n] && s[i + n + 1] != s[i + n]){
        int L = *prev(st.lower_bound(n + i)) + 1;
        int R = *st.lower_bound(n + i);
        int d1 = (n + i) - L;
        int d2 = R - (n + i);
        if (d1 <= k && d2 <= k){
          if (d1 < d2){
            t[i] = s[L];
          } else {
            t[i] = s[R];
          }
        } else if (d1 <= k){
          t[i] = s[L];
        } else if (d2 <= k){
          t[i] = s[R];
        } else if (k % 2 == 1){
          if (t[i] == 'W'){
            t[i] = 'B';
          } else {
            t[i] = 'W';
          }
        }
      }
    }
    cout << t << endl;
  }
}
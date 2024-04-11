#include <bits/stdc++.h>
using namespace std;
string f(string &s, int k){
  int n = s.size();
  string r;
  for (int i = 0; i < n - k + 1; i++){
    r += s[k - 1 + i];
  }
  if ((n - k) % 2 == 0){
    for (int i = k - 2; i >= 0; i--){
      r += s[i];
    }
  } else {
    for (int i = 0; i < k - 1; i++){
      r += s[i];
    }
  }
  return r;
}
string rev(string &s){
  string r;
  for (int i = s.size() - 1; i >= 0; i--){
    r += s[i];
  }
  return r;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> S;
    for (int j = 0; j < n; j++){
      S.insert(s[j]);
    }
    if (S.size() == 1){
      cout << s << endl;
      cout << 1 << endl;
    } else {
      string m = s;
      int k = 1;
      for (int j = 2; j <= n; j++){
        string s2 = f(s, j);
        if (m > s2){
          m = s2;
          k = j;
        }
      }
      cout << m << endl;
      cout << k << endl;
    }
  }
}
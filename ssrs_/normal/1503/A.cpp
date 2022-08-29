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
    string s;
    cin >> s;
    int cnt1 = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == '1'){
        cnt1++;
      }
    }
    if (cnt1 % 2 != 0){
      cout << "NO" << "\n";
    } else {
      int c0 = 0, c1 = 0;
      int cnta = 0, cntb = 0;
      bool ok = true;
      string a, b;
      for (int j = 0; j < n; j++){
        if (s[j] == '0'){
          if (c0 % 2 == 0){
            a += '(';
            cnta++;
            b += ')';
            cntb--;
          } else {
            a += ')';
            cnta--;
            b += '(';
            cntb++;
          }
          c0++;
        }
        if (s[j] == '1'){
          if (c1 * 2 < cnt1){
            a += '(';
            cnta++;
            b += '(';
            cntb++;
          } else {
            a += ')';
            cnta--;
          b += ')';
            cntb--;
          }
          c1++;
        }
        if (cnta < 0){
          ok = false;
        }
        if (cntb < 0){
          ok = false;
        }
      }
      if (!ok){
        cout << "NO" << "\n";
      } else {
        cout << "YES" << "\n";
        cout << a << "\n";
        cout << b << "\n";
      }
    }
  }
}
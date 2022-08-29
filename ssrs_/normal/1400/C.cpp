#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int x;
    cin >> x;
    int n = s.size();
    vector<char> tmp(n, '1');
    for (int j = 0; j < n; j++){
      if (s[j] == '0' && j >= x){
        tmp[j - x] = '0';
      }
      if (s[j] == '0' && j + x < n){
        tmp[j + x] = '0';
      }
    }
    vector<char> tmp2(n, '0');
    for (int j = 0; j < n; j++){
      if (j >= x){
        if (tmp[j - x] == '1'){
          tmp2[j] = '1';
        }
      }
      if (j + x < n){
        if (tmp[j + x] == '1'){
          tmp2[j] = '1';
        }
      }
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (s[j] != tmp2[j]){
        ok = false;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      for (int j = 0; j < n; j++){
        cout << tmp[j];
      }
      cout << endl;
    }
  }
}
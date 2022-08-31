#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    int l = 0;
    while (l < n - 1){
      if (s.substr(l, 2) != "11"){
        l++;
      } else {
        break;
      }
    }
    int r = n - 2;
    while (r > 1){
      if (s.substr(r, 2) != "00"){
        r--;
      } else {
        break;
      }
    }
    if (r - l <= 1){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
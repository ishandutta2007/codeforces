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
    string t0;
    for (int j = 0; j < n; j++){
      if (s[j] == '0'){
        t0 += s[j];
      } else {
        break;
      }
    }
    string t1;
    for (int j = n - 1; j >= 0; j--){
      if (s[j] == '1'){
        t1 += s[j];
      } else {
        break;
      }
    }
    if (t0.size() + t1.size() == n){
      cout << t0 << t1 << endl;
    } else {
      cout << t0 << '0' << t1 << endl;
    }
  }
}
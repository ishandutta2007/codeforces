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
    int L = n / 2;
    while (L > 0){
      if (s[L - 1] == s[n / 2]){
        L--;
      } else {
        break;
      }
    }
    int R = n / 2;
    while (R < n){
      if (s[R] == s[n / 2]){
        R++;
      } else {
        break;
      }
    }
    cout << R - L << endl;
  }
}
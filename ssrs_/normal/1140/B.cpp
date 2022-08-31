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
    int L = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == '<'){
        L++;
      } else {
        break;
      }
    }
    int R = 0;
    for (int j = n - 1; j >= 0; j--){
      if (s[j] == '>'){
        R++;
      } else {
        break;
      }
    }
    cout << min(L, R) << endl;
  }
}
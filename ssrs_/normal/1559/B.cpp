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
    for (int j = 0; j < n - 1; j++){
      if (s[j] != '?' && s[j + 1] == '?'){
        if (s[j] == 'B'){
          s[j + 1] = 'R';
        }
        if (s[j] == 'R'){
          s[j + 1] = 'B';
        }
      }
    }
    for (int j = n - 2; j >= 0; j--){
      if (s[j] == '?' && s[j + 1] != '?'){
        if (s[j + 1] == 'B'){
          s[j] = 'R';
        }
        if (s[j + 1] == 'R'){
          s[j] = 'B';
        }
      }
    }
    if (s[0] == '?'){
      for (int j = 0; j < n; j++){
        if (j % 2 == 0){
          s[j] = 'B';
        }
        if (j % 2 == 1){
          s[j] = 'R';
        }
      }
    }
    cout << s << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<string> s(2);
    for (int j = 0; j < 2; j++){
      cin >> s[j];
    }
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < n; k++){
        if (s[j][k] == 'G'){
          s[j][k] = 'B';
        }
      }
    }
    if (s[0] == s[1]){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
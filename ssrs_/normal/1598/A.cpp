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
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (s[0][j] == '1' && s[1][j] == '1'){
        ok = false;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
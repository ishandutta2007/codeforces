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
    bool ok = false;
    for (int j = n / 2; j < n; j++){
      if (s[j] == '0'){
        cout << 1 << ' ' << j + 1 << ' ' << 1 << ' ' << j << endl;
        ok = true;
        break;
      }
    }
    if (!ok){
      for (int j = 0; j < n / 2; j++){
        if (s[j] == '0'){
          cout << j + 2 << ' ' << n << ' ' << j + 1 << ' ' << n << endl;
          ok = true;
          break;
        }
      }
      if (!ok){
        cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << endl;
      }
    }
  }
}
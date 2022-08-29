#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    char c;
    cin >> c;
    int n = s.size();
    bool ok = false;
    for (int j = 0; j < n; j += 2){
      if (s[j] == c){
        ok = true;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
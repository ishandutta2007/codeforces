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
    for (int j = 0; j <= 4; j++){
      string t = s.substr(0, j) + s.substr(s.size() - (4 - j));
      if (t == "2020"){
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
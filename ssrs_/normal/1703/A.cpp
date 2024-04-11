#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    for (int j = 0; j < 3; j++){
      s[j] = toupper(s[j]);
    }
    if (s == "YES"){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
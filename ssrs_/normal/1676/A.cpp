#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int a = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
    int b = (s[3] - '0') + (s[4] - '0') + (s[5] - '0');
    if (a == b){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
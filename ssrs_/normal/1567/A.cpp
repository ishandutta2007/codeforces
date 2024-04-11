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
    string t = s;
    for (int j = 0; j < n; j++){
      if (s[j] == 'U'){
        t[j] = 'D';
      }
      if (s[j] == 'D'){
        t[j] = 'U';
      }
    }
    cout << t << endl;
  }
}
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
    int mn = 0;
    int c = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == '('){
        c++;
      } else {
        c--;
        mn = min(mn, c);
      }
    }
    cout << -mn << endl;
  }
}
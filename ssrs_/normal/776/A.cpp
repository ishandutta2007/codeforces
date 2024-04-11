#include <bits/stdc++.h>
using namespace std;
int main(){
  string s, t;
  cin >> s >> t;
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++){
    cout << s << ' ' << t << endl;
    if (i < n){
      string a, b;
      cin >> a >> b;
      if (s == a){
        s = b;
      } else {
        t = b;
      }
    }
  }
}
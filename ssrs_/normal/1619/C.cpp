#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long a, s;
    cin >> a >> s;
    string b;
    bool ok = true;
    while (a > 0 && s > 0){
      int x = a % 10;
      int y = s % 10;
      if (x <= y){
        b += '0' + (y - x);
        a /= 10;
        s /= 10;
      } else {
        s /= 10;
        if (s % 10 != 1){
          ok = false;
          break;
        }
        b += '0' + (y - x + 10);
        a /= 10;
        s /= 10;
      }
    }
    reverse(b.begin(), b.end());
    if (a > 0 && s == 0){
      ok = false;
    }
    if (a == 0 && s > 0){
      b = to_string(s) + b;
    }
    while (b.size() >= 1){
      if (b[0] == '0'){
        b.erase(b.begin());
      } else {
        break;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      cout << b << endl;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>> t;
  for (int i = 0; i < t; i++){
    string a;
    cin >> a;
    string b;
    cin >> b;
    int n = a.size();
    int m = b.size();
    int ans = n + m;
    for (int j = 0; j <= min(n, m); j++){
      for (int x = 0; x <= n - j; x++){
        for (int y = 0; y <= m - j; y++){
          if (a.substr(x, j) == b.substr(y, j)){
            ans = n + m - j * 2;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
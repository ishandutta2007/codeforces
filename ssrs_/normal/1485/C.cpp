#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x, y;
    cin >> x >> y;
    long long ans = 0;
    for (int a = 1; a * a <= x; a++){
      ans += max(min(x / a - 1, y) - a, 0);
    }
    cout << ans << endl;
  }
}
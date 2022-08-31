#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y){
  if (y == 0){
    return x;
  } else {
    return gcd(y, x % y);
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int ans = n - 1;
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        int cnt = n - 2;
        int x = a[k], d = a[k] - a[j];
        int g = gcd(abs(d), k - j);
        d /= g;
        int p = (k - j) / g;
        for (int l = k + p; l < n; l += p){
          x += d;
          if (a[l] == x){
            cnt--;
          }
        }
        ans = min(ans, cnt);
      }
    }
    cout << ans << endl;
  }
}
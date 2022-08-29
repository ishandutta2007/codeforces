#include <bits/stdc++.h>
using namespace std;
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
    int ans = 0;
    for (int j = 1; j < n; j++){
      ans = gcd(ans, a[j] - a[0]);
    }
    if (ans == 0){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
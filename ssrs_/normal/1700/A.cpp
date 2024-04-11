#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    for (int j = 1; j <= m; j++){
      ans += j;
    }
    for (int j = 2; j <= n; j++){
      ans += m * j;
    }
    cout << ans << endl;
  }
}
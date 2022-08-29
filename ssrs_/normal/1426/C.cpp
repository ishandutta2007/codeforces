#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int ans = INF;
    for (int j = 1; j * j <= n; j ++){
      ans = min(ans, (j - 1) + (n + j - 1) / j - 1);
    }
    cout << ans << endl;
  }
}
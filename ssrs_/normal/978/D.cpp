#include <bits/stdc++.h>
using namespace std;
int INF = 10000000;

int main(){
  int n;
  cin >> n;
  vector<long long> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  if (n <= 2){
    cout << 0 << endl;
  } else {
    int ans = INF;
    for (int i = -1; i <= 1; i++){
      for (int j = -1; j <= 1; j++){
        vector<long long> a(n);
        a[0] = b[0] + i;
        a[1] = b[1] + j;
        for (int k = 2; k < n; k++){
          a[k] = a[k - 1] * 2 - a[k - 2];
        }
        bool ok = true;
        long long sum = 0;
        for (int k = 0; k < n; k++){
          long long d = abs(a[k] - b[k]);
          if (d >= 2){
            ok = false;
          } else {
            sum += d;
          }
        }
        if (ok){
          ans = min(ans, (int) sum);
        }
      }
    }
    if (ans == INF){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
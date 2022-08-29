#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int L(int x){
  int ans = 0;
  while (x > 0){
    x /= 2;
    ans++;
  }
  return ans;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    b[i] = L(a[i]);
  }
  bool ok = false;
  for (int i = 0; i < n - 2; i++){
    if (b[i] == b[i + 2]){
      ok = true;
    }
  }
  if (ok){
    cout << 1 << endl;
  } else {
    vector<int> X(n + 1);
    X[0] = 0;
    for (int i = 0; i < n; i++){
      X[i + 1] = X[i] ^ a[i];
    }
    int ans = INF;
    for (int i = 0; i <= n; i++){
      for (int j = i + 1; j <= n; j++){
        for (int k = j + 1; k <= n; k++){
          int a = X[j] ^ X[i];
          int b = X[k] ^ X[j];
          if (a > b){
            ans = min(ans, k - i - 2);
          }
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
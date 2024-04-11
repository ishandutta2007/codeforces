#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
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
    vector<int> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    int ans = INF;
    for (int j = 1; j <= n; j++){
      if (S[n] % S[j] == 0){
        int mx = 0;
        bool ok = true;
        int p = 0;
        int pr = 0;
        for (int k = 1; k <= n; k++){
          if (S[k] % S[j] == 0){
            if (S[k] / S[j] > pr + 1){
              ok = false;
              break;
            } else {
              pr++;
              mx = max(mx, k - p);
              p = k;
            }
          }
        }
        if (ok){
          ans = min(ans, mx);
        }
      }
    }
    cout << ans << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    long long k, b, s;
    cin >> n >> k >> b >> s;
    if (s < b * k || s > b * k + n * (k - 1)){
      cout << -1 << endl;
    } else {
      vector<long long> ans(n, 0);
      ans[0] = (long long) b * k;
      s -= b * k;
      for (int j = 0; j < n; j++){
        long long add = min(s, k - 1);
        ans[j] += add;
        s -= add;
      }
      for (int j = 0; j < n; j++){
        cout << ans[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}
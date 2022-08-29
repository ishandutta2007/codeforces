#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> h(n);
    for (int j = 0; j < n; j++){
      cin >> h[j];
    }
    int mx = 0;
    for (int j = 0; j < n; j++){
      mx = max(mx, h[j]);
    }
    long long ans = INF;
    for (int j = 0; j < 3; j++){
      long long sum = 0;
      int cnt = 0;
      for (int k = 0; k < n; k++){
        sum += mx + j - h[k];
        if ((mx + j - h[k]) % 2 == 1){
          cnt++;
        }
      }
      long long res = sum / 3 * 2;
      if (sum % 3 == 1){
        res++;
      }
      if (sum % 3 == 2){
        res += 2;
      }
      res = max(res, (long long) cnt * 2 - 1);
      ans = min(ans, res);
    }
    cout << ans << endl;
  }
}
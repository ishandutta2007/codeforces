#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long ans = -1;
  for (long long i = 1; i <= 2000000; i++){
    if (a[0] <= i * (i + 1)){
      int mn = max(a[0] - i * i, (long long) 0), mx = i;
      long long F = i * i - a[0];
      int pr = 1;
      for (long long j = i; ; j++){
        int L = j * j - F - i;
        int R = j * (j + 1) - F;
        auto itr = lower_bound(a.begin(), a.end(), pr + 1);
        if (itr != a.end()){
          if (*itr < L){
            mx = -1;
            break;
          }
        }
        if (L > a[n - 1]){
          break;
        }
        int s_mn = *lower_bound(a.begin(), a.end(), L);
        int s_mx = *(upper_bound(a.begin(), a.end(), R) - 1);
        mn = max(mn, (int) (i - (s_mn - L)));
        mx = min(mx, R - s_mx);
        pr = R;
      }
      if (mn <= mx){
        ans = i * i - a[0] + mn;
        break;
      }
    }
  }
  cout << ans << endl;
}
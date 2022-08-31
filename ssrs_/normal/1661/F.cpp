#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
long long cost(int d, int cnt){
  int q = d / cnt;
  int r = d % cnt;
  return (long long) q * q * (cnt - r) + (long long) (q + 1) * (q + 1) * r;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n + 1);
  a[0] = 0;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  long long m;
  cin >> m;
  long long tv = 1, fv = INF;
  while (fv - tv > 1){
    long long mid = (tv + fv) / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++){
      long long d = a[i + 1] - a[i];
      int tv2 = 1, fv2 = d + 1;
      while (fv2 - tv2 > 1){
        int mid2 = (tv2 + fv2) / 2;
        long long x1 = cost(d, mid2 - 1);
        long long x2 = cost(d, mid2);
        if (x1 - x2 >= mid){
          tv2 = mid2;
        } else {
          fv2 = mid2;
        }
      }
      sum += cost(d, tv2);
    }
    if (sum <= m){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  long long ans = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++){
    long long d = a[i + 1] - a[i];
    int tv2 = 1, fv2 = d + 1;
    while (fv2 - tv2 > 1){
      int mid2 = (tv2 + fv2) / 2;
      long long x1 = cost(d, mid2 - 1);
      long long x2 = cost(d, mid2);
      if (x1 - x2 > tv){
        tv2 = mid2;
      } else {
        fv2 = mid2;
      }
    }
    ans += tv2 - 1;
    sum += cost(d, tv2);
  }
  ans += (sum - m + tv - 1) / tv;
  cout << ans << endl;
}
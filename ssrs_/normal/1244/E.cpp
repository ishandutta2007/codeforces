#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
const long long INF2 = 10000000000000000;
long long f(vector<int> &a, long long L, long long R){
  int n = a.size();
  long long ans = 0;
  for (int i = 0; i < n; i++){
    if (a[i] < L){
      ans += L - a[i];
    }
    if (R < a[i]){
      ans += a[i] - R;
    }
  }
  return ans;
}
int main(){
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long tv = INF;
  long long fv = -1;
  while (tv - fv > 1){
    long long mid = (tv + fv) / 2;
    long long L = 0;
    long long R = INF;
    while (R - L > 2){
      long long mid1 = (L * 2 + R) / 3;
      long long mid2 = (L + R * 2) / 3;
      if (f(a, mid1, mid1 + mid) < f(a, mid2, mid2 + mid)){
        R = mid2;
      } else {
        L = mid1;
      }
    }
    long long ans = INF2;
    for (int i = L; i <= R; i++){
      ans = min(ans, f(a, i, i + mid));
    }
    if (ans <= k){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}
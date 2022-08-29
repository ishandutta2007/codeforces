#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long long A, cf, cm, m;
  cin >> n >> A >> cf >> cm >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(a[i], i);
  }
  sort(P.begin(), P.end());
  vector<long long> L(n + 1);
  L[0] = 0;
  for (int i = 0; i < n; i++){
    L[i + 1] = L[i] + P[i].first;
  }
  vector<long long> R(n + 1);
  R[n] = 0;
  for (int i = n - 1; i >= 0; i--){
    R[i] = R[i + 1] + P[i].first;
  }
  long long ans = 0;
  long long Acnt = 0;
  int Amn = 0;
  for (int i = 0; i <= n; i++){
    long long tmp = A * i - R[n - i];
    if (tmp <= m){
      if (i == n){
        long long force = n * cf + A * cm;
        if (force > ans){
          ans = force;
          Acnt = n;
          Amn = A;
        }
      } else {
        long long tv = 0;
        long long fv = A + 1;
        while (fv - tv > 1){
          int mid = (tv + fv) / 2;
          int cnt = lower_bound(P.begin(), P.end(), make_pair(mid, -1)) - P.begin();
          cnt = min(cnt, n - i);
          long long sum = (long long) cnt * mid - L[cnt];
          if (sum + tmp <= m){
            tv = mid;
          } else {
            fv = mid;
          }
        }
        long long force = i * cf + tv * cm;
        if (force > ans){
          ans = force;
          Acnt = i;
          Amn = tv;
        }
      }
    }
  }
  vector<pair<int, int>> Q = P;
  for (int i = 0; i < Acnt; i++){
    Q[n - 1 - i].first = A;
  }
  for (int i = 0; i < n; i++){
    Q[i].first = max(Q[i].first, Amn);
  }
  vector<int> a2(n);
  for (int i = 0; i < n; i++){
    a2[Q[i].second] = Q[i].first;
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++){
    cout << a2[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}
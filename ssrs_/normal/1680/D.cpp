#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> S1(n + 1);
  vector<int> S2(n + 1);
  S1[0] = 0;
  S2[0] = 0;
  for (int i = 0; i < n; i++){
    S1[i + 1] = S1[i] + a[i];
    S2[i + 1] = S2[i];
    if (a[i] == 0){
      S2[i + 1]++;
    }
  }
  if (S1[n] - (long long) S2[n] * k > 0 || S1[n] + (long long) S2[n] * k < 0){
    cout << -1 << endl;
  } else {
    long long ans = 0;
    for (int i = 0; i <= n; i++){
      for (int j = i + 1; j <= n; j++){
        long long mn1 = S1[i] - (long long) S2[i] * k + (S1[n] - S1[j]) - (long long) (S2[n] - S2[j]) * k;
        long long mx1 = S1[i] + (long long) S2[i] * k + (S1[n] - S1[j]) + (long long) (S2[n] - S2[j]) * k;
        long long mn2 = (S1[i] - S1[j]) - (long long) (S2[j] - S2[i]) * k;
        long long mx2 = (S1[i] - S1[j]) + (long long) (S2[j] - S2[i]) * k;
        if (max(mn1, mn2) <= min(mx1, mx2)){
          ans = max(ans, min(mx1, mx2));
        }
      }
    }
    for (int i = 0; i <= n; i++){
      for (int j = i + 1; j <= n; j++){
        long long mn1 = -S1[i] - (long long) S2[i] * k - (S1[n] - S1[j]) - (long long) (S2[n] - S2[j]) * k;
        long long mx1 = -S1[i] + (long long) S2[i] * k - (S1[n] - S1[j]) + (long long) (S2[n] - S2[j]) * k;
        long long mn2 = (S1[j] - S1[i]) - (long long) (S2[j] - S2[i]) * k;
        long long mx2 = (S1[j] - S1[i]) + (long long) (S2[j] - S2[i]) * k;
        if (max(mn1, mn2) <= min(mx1, mx2)){
          ans = max(ans, min(mx1, mx2));
        }
      }
    }
    cout << ans + 1 << endl;
  }
}
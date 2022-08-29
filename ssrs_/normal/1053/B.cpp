#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    b[i] = __builtin_popcountll(a[i]);
  }
  vector<int> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + b[i];
  }
  vector<long long> cnt(2, 0);
  for (int i = 0; i <= n; i++){
    cnt[S[i] % 2]++;
  }
  long long ans = cnt[0] * (cnt[0] - 1) / 2 + cnt[1] * (cnt[1] - 1) / 2;
  for (int i = 0; i < n; i++){
    int sum = 0, mx = 0;
    for (int j = i; j < n; j++){
      sum += b[j];
      mx = max(mx, b[j]);
      if (sum % 2 == 0 && mx * 2 > sum){
        ans--;
      }
      if (sum > 120){
        break;
      }
    }
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(10);
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  double ans = 0;
  for (int i = 1; i <= n; i++){
    if (n - i <= m){
      ans = max(ans, (double) (S[i] + min((long long) m - (n - i), (long long) k * i)) / i);
    }
  }
  cout << ans << endl;
}
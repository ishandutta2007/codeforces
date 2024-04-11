#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(20);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  double ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = i + k; j <= n; j++){
      ans = max(ans, (double) (S[j] - S[i]) / (j - i));
    }
  }
  cout << ans << endl;
}
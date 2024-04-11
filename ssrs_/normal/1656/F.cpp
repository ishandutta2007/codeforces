#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    long long S1 = 0;
    for (int j = 1; j < n; j++){
      S1 += a[0] + a[j];
    }
    long long S2 = 0;
    for (int j = 0; j < n - 1; j++){
      S2 += a[n - 1] + a[j];
    }
    if (S1 > 0 || S2 < 0){
      cout << "INF" << endl;
    } else {
      vector<long long> imos_a(n, 0);
      vector<long long> imos_b(n, 0);
      imos_a[0] += a[0] + a[n - 1];
      imos_b[0] += a[0] * a[n - 1];
      imos_a[n - 1] -= a[0] + a[n - 1];
      imos_b[n - 1] -= a[0] * a[n - 1];
      for (int j = 1; j < n - 1; j++){
        imos_a[0] += a[j] + a[n - 1];
        imos_b[0] += a[j] * a[n - 1];
        imos_a[n - 1 - j] -= a[j] + a[n - 1];
        imos_b[n - 1 - j] -= a[j] * a[n - 1];
        imos_a[n - 1 - j] += a[j] + a[0];
        imos_b[n - 1 - j] += a[j] * a[0];
        imos_a[n - 1] -= a[j] + a[0];
        imos_b[n - 1] -= a[j] * a[0];
      }
      for (int j = 0; j < n - 1; j++){
        imos_a[j + 1] += imos_a[j];
        imos_b[j + 1] += imos_b[j];
      }
      long long ans = -INF;
      for (int j = 0; j < n - 1; j++){
        ans = max(ans, -a[n - 2 - j] * imos_a[j] + imos_b[j]);
      }
      cout << ans << endl;
    }
  }
}
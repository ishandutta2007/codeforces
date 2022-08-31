#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    long long sum = 0;
    for (int j = 0; j < n; j++){
      sum += a[j];
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      b[j] = a[j] - (n - 1 - j);
    }
    sort(b.begin(), b.end(), greater<long long>());
    vector<long long> s(k + 1);
    s[0] = sum;
    for (int j = 0; j < k; j++){
      s[j + 1] = s[j] - b[j];
    }
    for (int j = 0; j <= k; j++){
      s[j] -= (long long) j * (j - 1) / 2;
    }
    long long ans = INF;
    for (int j = 0; j <= k; j++){
      ans = min(ans, s[j]);
    }
    cout << ans << endl;
  }
}
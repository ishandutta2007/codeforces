#include <bits/stdc++.h>
using namespace std;
const long long INF = 100000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<long long> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    long long a1 = INF, a2 = INF, b1 = INF, b2 = INF;
    for (int j = 0; j < n; j++){
      a1 = min(a1, abs(a[0] - b[j]));
      a2 = min(a2, abs(a[n - 1] - b[j]));
      b1 = min(b1, abs(b[0] - a[j]));
      b2 = min(b2, abs(b[n - 1] - a[j]));
    }
    long long ans = INF;
    ans = min(ans, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
    ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
    ans = min(ans, abs(a[0] - b[0]) + a2 + b2);
    ans = min(ans, abs(a[0] - b[n - 1]) + a2 + b1);
    ans = min(ans, abs(a[n - 1] - b[0]) + a1 + b2);
    ans = min(ans, abs(a[n - 1] - b[n - 1]) + a1 + b1);
    ans = min(ans, a1 + a2 + b1 + b2);
    cout << ans << endl;
  }
}
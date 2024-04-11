#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int mn = INF, mx = 0;
    for (int j = 0; j < n; j++){
      mn = min(mn, a[j]);
      mx = max(mx, a[j]);
    }
    long long sum = 0;
    for (int j = 0; j < n - 1; j++){
      sum += abs(a[j + 1] - a[j]);
    }
    mx = min(mx, x);
    long long ans = sum + (mn - 1) * 2 + (x - mx) * 2;
    ans = min(ans, sum + abs(a[0] - 1) + (x - mx) * 2);
    ans = min(ans, sum + abs(a[n - 1] - 1) + (x - mx) * 2);
    ans = min(ans, sum + (mn - 1) * 2 + abs(a[0] - x));
    ans = min(ans, sum + (mn - 1) * 2 + abs(a[n - 1] - x));
    ans = min(ans, sum + abs(a[0] - 1) + abs(a[n - 1] - x));
    ans = min(ans, sum + abs(a[n - 1] - 1) + abs(a[0] - x));
    ans = min(ans, sum + abs(a[0] - 1) + (x - 1));
    ans = min(ans, sum + abs(a[0] - x) + (x - 1));
    ans = min(ans, sum + abs(a[n - 1] - 1) + (x - 1));
    ans = min(ans, sum + abs(a[n - 1] - x) + (x - 1));
    cout << ans << endl;
  }
}
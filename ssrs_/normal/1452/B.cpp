#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    long long sum = 0;
    int mx = 0;
    for (int j = 0; j < n; j++){
      sum += a[j];
      mx = max(mx, a[j]);
    }
    long long ans = (sum + (n - 1) - 1) / (n - 1) * (n - 1);
    ans = max(ans, (long long) mx * (n - 1));
    cout << ans - sum << endl;
  }
}
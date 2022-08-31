#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int j = 0; j < n; j++){
      int L = lower_bound(a.begin(), a.end(), l - a[j]) - a.begin();
      int R = upper_bound(a.begin(), a.end(), r - a[j]) - a.begin();
      L = max(L, j + 1);
      ans += max(R - L, 0);
    }
    cout << ans << endl;
  }
}
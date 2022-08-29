#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 0; i < n; i++){
    a[i] = abs(a[i]);
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < n; i++){
    ans += upper_bound(a.begin(), a.end(), a[i] * 2) - (a.begin() + i) - 1;
  }
  cout << ans << endl;
}
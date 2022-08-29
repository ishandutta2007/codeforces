#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> s(n / 2);
  for (int i = 0; i < n / 2; i++){
    s[i] = a[i] + a[n - 1 - i];
  }
  long long ans = 0;
  for (int i = 0; i < n / 2; i++){
    ans += (long long) s[i] * s[i];
  }
  cout << ans << endl;
}
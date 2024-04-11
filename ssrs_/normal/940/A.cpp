#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, d;
  cin >> n >> d;
  vector<int> x(n);
  for (int i = 0; i < n; i++){
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  int ans = n;
  for (int i = 0; i <= 100; i++){
    int tmp = lower_bound(x.begin(), x.end(), i + d + 1) - lower_bound(x.begin(), x.end(), i);
    ans = min(ans, n - tmp);
  }
  cout << ans << endl;
}
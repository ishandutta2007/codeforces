#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 31; j++){
      int d = 1 << j;
      int p = d - a[i];
      if (p < a[i]){
        continue;
      }
      ans += upper_bound(a.begin() + i + 1, a.end(), p) - lower_bound(a.begin() + i + 1, a.end(), p);
    }
  }
  cout << ans << endl;
}
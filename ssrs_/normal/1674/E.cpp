#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> a2 = a;
  sort(a2.begin(), a2.end());
  int ans = (a2[0] + 1) / 2 + (a2[1] + 1) / 2;
  for (int i = 0; i < n - 2; i++){
    if (a[i] <= a[i + 2]){
      ans = min(ans, a[i] + (a[i + 2] - a[i] + 1) / 2);
    } else {
      ans = min(ans, a[i + 2] + (a[i] - a[i + 2] + 1) / 2);
    }
  }
  for (int i = 0; i < n - 1; i++){
    ans = min(ans, max({(a[i] + 1) / 2, (a[i + 1] + 1) / 2, (a[i] + a[i + 1] + 2) / 3}));
  }
  cout << ans << endl;
}
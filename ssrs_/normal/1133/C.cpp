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
  int ans = 0;
  for (int i = 0; i < n; i++){
    ans = max(ans, (int) (upper_bound(a.begin(), a.end(), a[i] + 5) - a.begin() - i));
  }
  cout << ans << endl;
}
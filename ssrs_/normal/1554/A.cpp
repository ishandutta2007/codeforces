#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    long long ans = 0;
    for (int j = 0; j < n - 1; j++){
      ans = max(ans, (long long) a[j] * a[j + 1]);
    }
    cout << ans << endl;
  }
}
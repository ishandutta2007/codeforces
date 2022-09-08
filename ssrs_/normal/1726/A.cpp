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
    int ans = a[n - 1] - a[0];
    for (int j = 1; j < n; j++){
      ans = max(ans, a[j] - a[0]);
    }
    for (int j = 0; j < n - 1; j++){
      ans = max(ans, a[n - 1] - a[j]);
    }
    for (int j = 1; j < n; j++){
      ans = max(ans, a[j - 1] - a[j]);
    }
    cout << ans << endl;
  }
}
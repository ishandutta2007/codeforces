#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> mx(k, 0);
    for (int j = 0; j < n; j++){
      mx[j % k] = max(mx[j % k], a[j]);
    }
    long long ans = 0;
    for (int j = 0; j < k; j++){
      ans += mx[j];
    }
    cout << ans << endl;
  }
}
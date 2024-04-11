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
    map<int, long long> mp;
    long long ans = 0;
    for (int j = 0; j < n; j++){
      ans += mp[a[j]] * (n - j);
      mp[a[j]] += j + 1;
    }
    cout << ans << endl;
  }
}
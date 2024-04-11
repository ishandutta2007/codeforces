#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    map<int, int> mp;
    long long ans = 0;
    for (int j = 0; j < n; j++){
      int a;
      cin >> a;
      ans += mp[a - j];
      mp[a - j]++;
    }
    cout << ans << endl;
  }
}
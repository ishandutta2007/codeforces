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
    map<int, int> mp;
    for (int j = 0; j < n; j++){
      mp[a[j]]++;
    }
    vector<int> c;
    for (auto P : mp){
      c.push_back(P.second);
    }
    int m = c.size();
    vector<int> L(m + 1);
    L[0] = 0;
    for (int j = 0; j < m; j++){
      L[j + 1] = L[j] + min(c[j], 2);
    }
    vector<int> R(m + 1);
    R[m] = 0;
    for (int j = m - 1; j >= 0; j--){
      R[j] = R[j + 1] + min(c[j], 2);
    }
    int ans = 0;
    for (int j = 0; j < m; j++){
      ans = max(ans, (L[j] + R[j + 1]) / 2 + 1);
    }
    cout << ans << endl;
  }
}
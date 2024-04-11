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
    sort(c.begin(), c.end());
    int cnt = c.size();
    vector<int> s(cnt + 1, 0);
    for (int j = 0; j < cnt; j++){
      s[j + 1] = s[j] + c[j];
    }
    int ans = n;
    for (int j = 0; j < cnt; j++){
      ans = min(ans, s[cnt] - (cnt - j) *c[j]);
    }
    cout << ans << endl;
  }
}
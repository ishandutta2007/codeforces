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
    vector<int> b;
    b.push_back(a[0]);
    for (int j = 1; j < n; j++){
      if (a[j] != a[j - 1]){
        b.push_back(a[j]);
      }
    }
    n = b.size();
    map<int, int> mp;
    for (int j = 0; j < n; j++){
      mp[b[j]]++;
    }
    mp[b[0]]--;
    mp[b[n - 1]]--;
    int ans = n;
    for (auto P : mp){
      ans = min(ans, P.second);
    }
    cout << ans + 1 << endl;
  }
}
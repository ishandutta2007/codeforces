#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string a;
  cin >> a;
  string b;
  cin >> b;
  int ans = 0;
  for (int i = 0; i < n / 2; i++){
    map<char, int> mp;
    mp[a[i]]++;
    mp[a[n - 1 - i]]++;
    mp[b[i]]++;
    mp[b[n - 1 - i]]++;
    vector<int> c;
    for (auto P : mp){
      c.push_back(P.second);
    }
    sort(c.rbegin(), c.rend());
    if (c[0] == 3){
      ans++;
    }
    if (c[0] == 2){
      if (c[1] == 1){
        if (a[i] == a[n - 1 - i]){
          ans += 2;
        } else {
          ans++;
        }
      }
    }
    if (c[0] == 1){
      ans += 2;
    }
  }
  if (n % 2 == 1){
    if (a[n / 2] != b[n / 2]){
      ans++;
    }
  }
  cout << ans << endl;
}
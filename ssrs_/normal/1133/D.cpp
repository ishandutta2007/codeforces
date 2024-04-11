#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  map<pair<int, int>, int> mp;
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (a[i] == 0){
      if (b[i] == 0){
        cnt++;
      }
    } else {
      int g = gcd(b[i], a[i]);
      int c = a[i] / g;
      int d = b[i] / g;
      if (c < 0){
        c *= -1;
        d *= -1;
      }
      mp[make_pair(c, d)]++;
    }
  }
  int mx = 0;
  for (auto P : mp){
    mx = max(mx, P.second);
  }
  cout << mx + cnt << endl;
}
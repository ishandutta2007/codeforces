#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  map<int, int> mpx, mpy;
  map<pair<int, int>, int> mp;
  long long ans = 0;
  for (int i = 0; i < n; i++){
    ans += mpx[x[i]];
    mpx[x[i]]++;
    ans += mpy[y[i]];
    mpy[y[i]]++;
    ans -= mp[make_pair(x[i], y[i])];
    mp[make_pair(x[i], y[i])]++;
  }
  cout << ans << endl;
}
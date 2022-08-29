#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> l(n), r(n), c(n);
    for (int j = 0; j < n; j++){
      cin >> l[j] >> r[j] >> c[j];
    }
    int mn = INF, mnc = INF, mx = 0, mxc = INF;
    map<pair<int, int>, int> mp;
    for (int j = 0; j < n; j++){
      if (mp.count(make_pair(l[j], r[j])) == 0){
        mp[make_pair(l[j], r[j])] = c[j];
      } else {
        mp[make_pair(l[j], r[j])] = min(mp[make_pair(l[j], r[j])], c[j]);
      }
      if (l[j] <= mn){
        if (l[j] < mn){
          mnc = INF;
        }
        mn = l[j];
        mnc = min(mnc, c[j]);
      }
      if (r[j] >= mx){
        if (r[j] > mx){
          mxc = INF;
        }
        mx = r[j];
        mxc = min(mxc, c[j]);
      }
      int ans = mnc + mxc;
      if (mp.count(make_pair(mn, mx)) == 1){
        ans = min(ans, mp[make_pair(mn, mx)]);
      }
      cout << ans << "\n";
    }
  }
}
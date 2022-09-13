#include <bits/stdc++.h>
using namespace std;
int main(){
  long long ans = -1;
  cout << "? 1 2" << endl;
  long long x;
  cin >> x;
  map<long long, int> mp;
  for (int j = 3; j < 27; j++){
    cout << "? " << 1 << ' ' << j + 1 << endl;
    long long y;
    cin >> y;
    if (y == -1){
      ans = j;
      break;
    }
    cout << "? " << 2 << ' ' << j + 1 << endl;
    long long z;
    cin >> z;
    if (x != y + z & y != x + z && z != x + y){
      mp[x + y - z]++;
      mp[y + z - x]++;
      mp[z + x - y]++;
      mp[x + y + z]++;
      mp[(x + y + z) / 2]++;
    }
  }
  if (ans != -1){
    cout << "! " << ans << endl;
  } else {
    vector<pair<int, long long>> F;
    for (auto P : mp){
      F.push_back(make_pair(P.second, P.first));
    }
    sort(F.begin(), F.end(), greater<pair<int, long long>>());
    cout << "! " << F[0].second << endl;
  }
}
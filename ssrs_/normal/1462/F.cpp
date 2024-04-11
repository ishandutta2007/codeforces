#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int j = 0; j < n; j++){
      cin >> l[j] >> r[j];
      r[j]++;
    }
    vector<int> x;
    for (int j = 0; j < n; j++){
      x.push_back(l[j]);
      x.push_back(r[j]);
    }
    sort(x.begin(), x.end());
    int cnt = x.size();
    map<int, int> mp;
    for (int j = 0; j < cnt; j++){
      mp[x[j]] = j;
    }
    for (int j = 0; j < n; j++){
      l[j] = mp[l[j]];
      r[j] = mp[r[j]];
    }
    vector<int> LC(cnt + 1, 0);
    for (int j = 0; j < n; j++){
      LC[l[j]]++;
    }
    for (int j = cnt - 1; j >= 0; j--){
      LC[j] += LC[j + 1];
    }
    vector<int> RC(cnt + 1, 0);
    for (int j = 0; j < n; j++){
      RC[r[j] + 1]++;
    }
    for (int j = 0; j < cnt; j++){
      RC[j + 1] += RC[j];
    }
    int ans = n;
    for (int j = 0; j < n; j++){
      ans = min(ans, RC[l[j] + 1] + LC[r[j]]);
    }
    cout << ans << endl;
  }
}
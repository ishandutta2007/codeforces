#include <bits/stdc++.h>
using namespace std;
int main(){
  int k;
  cin >> k;
  vector<int> n(k);
  vector<vector<int>> a(k);
  for (int i = 0; i < k; i++){
    cin >> n[i];
    a[i] = vector<int>(n[i]);
    for (int j = 0; j < n[i]; j++){
      cin >> a[i][j];
    }
  }
  map<int, vector<pair<int, int>>> mp;
  for (int i = 0; i < k; i++){
    int sum = 0;
    for (int j = 0; j < n[i]; j++){
      sum += a[i][j];
    }
    for (int j = 0; j < n[i]; j++){
      mp[sum - a[i][j]].push_back(make_pair(i + 1, j + 1));
    }
  }
  bool ok = false;
  for (auto P : mp){
    if (P.second.size() > 1){
      int sz = P.second.size();
      for (int i = 0; i < sz; i++){
        if (P.second[i].first != P.second[0].first){
          cout << "YES" << endl;
          cout << P.second[0].first << ' ' << P.second[0].second << endl;
          cout << P.second[i].first << ' ' << P.second[i].second << endl;
          ok = true;
          break;
        }
      }
      if (ok){
        break;
      }
    }
  }
  if (!ok){
    cout << "NO" << endl;
  }
}
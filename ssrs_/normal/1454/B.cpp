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
    map<int, vector<int>> mp;
    for (int j = 0; j < n; j++){
      mp[a[j]].push_back(j);
    }
    bool ok = false;
    for (auto P : mp){
      if (P.second.size() == 1){
        cout << P.second[0] + 1 << endl;
        ok = true;
        break;
      }
    }
    if (!ok){
      cout << -1 << endl;
    }
  }
}
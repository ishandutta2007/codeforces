#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    for (int j = 0; j < n * m; j++){
      cin >> a[j];
    }
    map<int, vector<int>> mp;
    for (int j = 0; j < n * m; j++){
      mp[a[j]].push_back(j);
    }
    int c = 0;
    vector<int> p(n * m);
    for (auto P : mp){
      int cnt = P.second.size();
      for (int x : P.second){
        p[x] = c;
        c++;
      }
    }
    vector<int> id(n * m);
    for (int j = 0; j < n * m; j++){
      id[p[j]] = j;
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        for (int l = 0; l < k; l++){
          int x = id[j * m + k];
          int y = id[j * m + l];
          if (x > y && a[x] != a[y]){
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
}
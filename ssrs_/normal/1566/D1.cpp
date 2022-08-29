#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int j = 0; j < m; j++){
      cin >> a[j];
    }
    map<int, vector<int>> mp;
    for (int j = m - 1; j >= 0; j--){
      mp[a[j]].push_back(j);
    }
    int c = 0;
    vector<int> p(m);
    for (auto P : mp){
      for (int x : P.second){
        p[x] = c;
        c++;
      }
    }
    int ans = 0;
    for (int j = 0; j < m; j++){
      for (int k = 0; k < j; k++){
        if (p[k] < p[j]){
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}
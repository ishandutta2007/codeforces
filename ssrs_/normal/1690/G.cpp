#include <bits/stdc++.h>
using namespace std;
const int INF = 1100000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int mn = INF;
    map<int, int> mp;
    for (int j = 0; j < n; j++){
      if (a[j] < mn){
        mp[j] = a[j];
        mn = a[j];
      }
    }
    for (int j = 0; j < m; j++){
      int k, d;
      cin >> k >> d;
      k--;
      a[k] -= d;
      if (mp.count(k) == 1){
        mp[k] = a[k];
      } else {
        auto itr = prev(mp.upper_bound(k));
        if (a[k] < (*itr).second){
          mp[k] = a[k];
        }
      }
      while (true){
        auto itr = mp.upper_bound(k);
        if (itr == mp.end()){
          break;
        }
        if ((*itr).second < a[k]){
          break;
        }
        mp.erase(itr);
      }
      cout << mp.size();
      if (j < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
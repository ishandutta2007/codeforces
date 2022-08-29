#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  int cnt1 = 0, cnt2 = 0;
  map<pair<int, int>, char> mp;
  for (int i = 0; i < m; i++){
    char t;
    cin >> t;
    if (t == '+'){
      int u, v;
      char c;
      cin >> u >> v >> c;
      u--;
      v--;
      if (mp.count(make_pair(v, u))){
        cnt1++;
        if (mp[make_pair(v, u)] == c){
          cnt2++;
        }
      }
      mp[make_pair(u, v)] = c;
    }
    if (t == '-'){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      char c = mp[make_pair(u, v)];
      if (mp.count(make_pair(v, u))){
        cnt1--;
        if (mp[make_pair(v, u)] == c){
          cnt2--;
        }
      }
      mp.erase(make_pair(u, v));
    }
    if (t == '?'){
      int k;
      cin >> k;
      if (k % 2 == 1){
        if (cnt1 >= 1){
          cout << "YES" << "\n";
        } else {
          cout << "NO" << "\n";
        }
      }
      if (k % 2 == 0){
        if (cnt2 >= 1){
          cout << "YES" << "\n";
        } else {
          cout << "NO" << "\n";
        }
      }
    }
  }
}
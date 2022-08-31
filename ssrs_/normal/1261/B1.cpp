#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]].push_back(i);
  }
  vector<int> id;
  for (auto itr = mp.rbegin(); itr != mp.rend(); itr++){
    for (auto x : (*itr).second){
      id.push_back(x);
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++){
    int k, pos;
    cin >> k >> pos;
    vector<int> sub;
    for (int j = 0; j < k; j++){
      sub.push_back(id[j]);
    }
    sort(sub.begin(), sub.end());
    cout << a[sub[pos - 1]] << endl;
  }
}
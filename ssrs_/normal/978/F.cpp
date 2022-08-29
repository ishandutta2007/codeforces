#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> r(n);
  for (int i = 0; i < n; i++){
    cin >> r[i];
  }
  vector<int> x(k), y(k);
  for (int i = 0; i < k; i++){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++){
    mp[r[i]].push_back(i);
  }
  int sum = 0;
  vector<int> ans(n, 0);
  for (auto P : mp){
    for (auto x : P.second){
      ans[x] = sum;
    }
    sum += P.second.size();
  }
  for (int i = 0; i < k; i++){
    if (r[x[i]] > r[y[i]]){
      ans[x[i]]--;
    }
    if (r[y[i]] > r[x[i]]){
      ans[y[i]]--;
    }
  }
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}
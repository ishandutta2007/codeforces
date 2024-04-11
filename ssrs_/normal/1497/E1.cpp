#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000000;
int main(){
  vector<int> s(MAX + 1);
  for (int i = 0; i <= MAX; i++){
    s[i] = i;
  }
  for (int i = 2; i * i <= MAX; i++){
    for (int j = i * i; j <= MAX; j += i * i){
      while (s[j] % (i * i) == 0){
        s[j] /= i * i;
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j] = s[a[j]];
    }
    map<int, int> mp;
    vector<pair<int, int>> r;
    for (int j = 0; j < n; j++){
      if (mp.count(a[j])){
        r.push_back(make_pair(j, mp[a[j]]));
      }
      mp[a[j]] = j;
    }
    sort(r.begin(), r.end());
    int ans = 0, R = 0;
    for (auto P : r){
      if (R <= P.second){
        R = P.first;
        ans++;
      }
    }
    cout << ans + 1 << endl;
  }
}
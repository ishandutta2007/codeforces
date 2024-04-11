#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
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
    vector<int> s(n + 1);
    s[0] = 0;
    for (int j = 0; j < n; j++){
      s[j + 1] = s[j] ^ a[j];
    }
    map<int, int> mp;
    vector<pair<int, int>> P;
    for (int j = 0; j <= n; j++){
      if (mp.count(s[j]) == 1){
        P.push_back(make_pair(j, mp[s[j]]));
      }
      mp[s[j]] = j;
    }
    sort(P.begin(), P.end());
    int cnt = P.size();
    int ans = 0;
    int L = 0;
    for (int j = 0; j < cnt; j++){
      if (P[j].second >= L){
        L = P[j].first;
        ans++;
      }
    }
    cout << n - ans << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int j = 0; j < m; j++){
      cin >> a[j] >> b[j];
    }
    //compress
    vector<int> value;
    for (int j = 0; j < m; j++){
      value.push_back(a[j]);
      value.push_back(b[j]);
    }
    sort(value.begin(), value.end());
    value.erase(unique(value.begin(), value.end()), value.end());
    int value_cnt = value.size();
    map<int, int> mp;
    for (int j = 0; j < value_cnt; j++){
      mp[value[j]] = j;
    }
    vector<int> a2(m);
    for (int j = 0; j < m; j++){
      a2[j] = mp[a[j]];
    }
    vector<int> b2(m);
    for (int j = 0; j < m; j++){
      b2[j] = mp[b[j]];
    }
    //count a_j>=b_i
    vector<long long> cnt(value_cnt, 0);
    for (int j = 0; j < m; j++){
      cnt[a2[j]]++;
    }
    for (int j = value_cnt - 2; j >= 0; j--){
      cnt[j] += cnt[j + 1];
    }
    //sum a_j>=b_i
    vector<long long> cnt2(value_cnt, 0);
    for (int j = 0; j < m; j++){
      cnt2[a2[j]] += a[j];
    }
    for (int j = value_cnt - 2; j >= 0; j--){
      cnt2[j] += cnt2[j + 1];
    }
    long long ans = 0;
    for (int j = 0; j < m; j++){
      if (a[j] >= b[j]){
        if (cnt[b2[j]] <= n){
          ans = max(ans, cnt2[b2[j]] + b[j] * (n - cnt[b2[j]]));
        }
      } else {
        if (cnt[b2[j]] < n){
          ans = max(ans, cnt2[b2[j]] + a[j] + b[j] * (n - cnt[b2[j]] - 1));
        }
      }
    }
    //sort
    sort(a.rbegin(), a.rend());
    long long ans2 = 0;
    if (n < m){
      for (int j = 0; j < n; j++){
        ans2 += a[j];
      }
    }
    cout << max(ans, ans2) << endl;
  }
}
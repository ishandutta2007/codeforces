#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    for (int j = 0; j < n; j++){
      cin >> k[j];
      k[j]--;
    }
    vector<int> c(m);
    for (int j = 0; j < m; j++){
      cin >> c[j];
    }
    long long ans = 0;
    for (int j = 0; j < n; j++){
      ans += c[k[j]];
    }
    vector<int> cnt(m, 0);
    for (int j = 0; j < n; j++){
      cnt[k[j]]++;
    }
    priority_queue<int> pq;
    for (int j = m - 1; j >= 0; j--){
      for (int l = 0; l < cnt[j]; l++){
        pq.push(c[j]);
      }
      if (!pq.empty()){
        ans -= pq.top();
        pq.pop();
        ans += c[j];
        pq.push(c[j]);
      }
    }
    cout << ans << endl;
  }
}
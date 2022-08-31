#include <bits/stdc++.h>
using namespace std;
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
    vector<int> cnt(n + 1, 0);
    for (int j = 0; j < n; j++){
      cnt[a[j]]++;
    }
    priority_queue<int> pq;
    bool ok = true;
    long long op = 0;
    for (int j = 0; j <= n; j++){
      if (!ok){
        cout << -1;
      } else {
        cout << op + cnt[j];
      }
      for (int k = 0; k < cnt[j]; k++){
        pq.push(j);
      }
      if (pq.empty()){
        ok = false;
      } else {
        op += j - pq.top();
        pq.pop();
      }
      if (j < n){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
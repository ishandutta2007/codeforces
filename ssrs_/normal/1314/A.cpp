#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> t(n);
  for (int i = 0; i < n; i++){
    cin >> t[i];
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]].push_back(t[i]);
  }
  int C = (*mp.begin()).first;
  priority_queue<int> pq;
  long long ans = 0;
  long long sum = 0;
  while (!pq.empty() || C <= (*prev(mp.end())).first){
    for (int x : mp[C]){
      pq.push(x);
      sum += x;
    }
    if (!pq.empty()){
      sum -= pq.top();
      pq.pop();
      ans += sum;
      C++;
    } else {
      C = (*mp.upper_bound(C)).first;
    }
  }
  cout << ans << endl;
}
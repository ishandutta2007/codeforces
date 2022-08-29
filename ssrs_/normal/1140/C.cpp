#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> bt(n);
  for (int i = 0; i < n; i++){
    int t, b;
    cin >> t >> b;
    bt[i] = make_pair(b, t);
  }
  sort(bt.begin(), bt.end());
  reverse(bt.begin(), bt.end());
  long long ans = 0;
  long long sum = 0;
  priority_queue<int, vector<int>, greater<int>> Q;
  for (int i = 0; i < n; i++){
    if (Q.size() == k){
      sum -= Q.top();
      Q.pop();
    }
    Q.push(bt[i].second);
    sum += bt[i].second;
    ans = max(ans, sum * bt[i].first);
  }
  cout << ans << endl;
}
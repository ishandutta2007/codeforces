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
    priority_queue<pair<int, int>> pq;
    for (int j = 0; j < n; j++){
      if (a[j] > 0){
        pq.push(make_pair(a[j], j));
      }
    }
    vector<pair<int, int>> ans;
    while (pq.size() >= 2){
      int a1 = pq.top().first;
      int v1 = pq.top().second;
      pq.pop();
      int a2 = pq.top().first;
      int v2 = pq.top().second;
      pq.pop();
      ans.push_back(make_pair(v1, v2));
      if (a1 > 1){
        pq.push(make_pair(a1 - 1, v1));
      }
      if (a2 > 1){
        pq.push(make_pair(a2 - 1, v2));
      }
    }
    int k = ans.size();
    cout << k << endl;
    for (int j = 0; j < k; j++){
      cout << ans[j].first + 1 << ' ' << ans[j].second + 1 << endl;
    }
  }
}
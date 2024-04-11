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
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    priority_queue<int> pq1, pq2;
    for (int j = 0; j < n; j++){
      pq1.push(a[j]);
      pq2.push(b[j]);
    }
    int ans = 0;
    while (!pq1.empty()){
      int x = pq1.top();
      int y = pq2.top();
      if (x == y){
        pq1.pop();
        pq2.pop();
      } else if (x > y){
        pq1.pop();
        pq1.push(to_string(x).size());
        ans++;
      } else {
        pq2.pop();
        pq2.push(to_string(y).size());
        ans++;
      }
    }
    cout << ans << endl;
  }
}
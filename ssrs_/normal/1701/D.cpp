#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    vector<int> L(n), R(n);
    for (int j = 0; j < n; j++){
      if (b[j] == 0){
        L[j] = j + 2;
        R[j] = n;
      } else {
        L[j] = (j + 1) / (b[j] + 1) + 1;
        R[j] = (j + 1) / b[j];
      }
    }
    vector<vector<int>> P(n + 1);
    for (int j = 0; j < n; j++){
      P[L[j]].push_back(j);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> a(n);
    for (int j = 1; j <= n; j++){
      for (int x : P[j]){
        pq.push(make_pair(R[x], x));
      }
      int p = pq.top().second;
      pq.pop();
      a[p] = j;
    }
    for (int j = 0; j < n; j++){
      cout << a[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << "\n";
  }
}
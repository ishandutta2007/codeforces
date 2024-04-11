#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> h(n);
    for (int j = 0; j < n; j++){
      cin >> h[j];
    }
    vector<int> y(n);
    for (int j = 0; j < m; j++){
      y[j] = j;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int j = 0; j < m; j++){
      pq.push(make_pair(h[j], j));
    }
    for (int j = m; j < n; j++){
      int H = pq.top().first;
      int id = pq.top().second;
      pq.pop();
      y[j] = id;
      pq.push(make_pair(H + h[j], id));
    }
    cout << "YES" << endl;
    for (int j = 0; j < n; j++){
      cout << y[j] + 1;
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
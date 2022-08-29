#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<pair<int, int>>> E(n + 1);
  for (int i = 0; i < n; i++){
    E[i].push_back(make_pair(i + 1, i + 1));
    E[i + 1].push_back(make_pair(0, i));
  }
  for (int i = 0; i < n; i++){
    if (s[i] == '1'){
      int L = max(i - k, 0);
      int R = min(i + k + 1, n);
      E[L].push_back(make_pair(i + 1, R));
    }
  }
  vector<long long> d(n + 1, -1);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  pq.push(make_pair(0, 0));
  while (!pq.empty()){
    long long dd = pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (d[v] == -1){
      d[v] = dd;
      for (auto P : E[v]){
        int w = P.second;
        if (d[w] == -1){
          pq.push(make_pair(dd + P.first, w));
        }
      }
    }
  }
  cout << d[n] << endl;
}
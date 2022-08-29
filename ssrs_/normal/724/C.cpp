#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000;
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(k), y(k);
  for (int i = 0; i < k; i++){
    cin >> x[i] >> y[i];
  }
  map<int, vector<int>> mp1, mp2;
  for (int i = 0; i < k; i++){
    mp1[x[i] - y[i]].push_back(i);
    mp2[x[i] + y[i]].push_back(i);
  }
  vector<long long> ans(k, INF);
  int x1 = 0, y1 = 0, x2 = 1, y2 = 1;
  long long t = 0;
  while (true){
    int dx = x2 - x1, dy = y2 - y1;
    if (dx == dy){
      for (int id : mp1[x1 - y1]){
        long long t2 = t + (x[id] - x1) / (x2 - x1);
        ans[id] = min(ans[id], t2);
      }
      if (dx == 1 && dy == 1){
        if (n - x1 < m - y1){
          int p = n - x1;
          t += p;
          x1 += p;
          y1 += p;
          x2 = x1 - 1;
          y2 = y1 + 1;
        } else if (m - y1 < n - x1){
          int p = m - y1;
          t += p;
          x1 += p;
          y1 += p;
          x2 = x1 + 1;
          y2 = y1 - 1;
        } else {
          break;
        }
      }
      if (dx == -1 && dy == -1){
        if (x1 < y1){
          int p = x1;
          t += p;
          x1 -= p;
          y1 -= p;
          x2 = x1 + 1;
          y2 = y1 - 1;
        } else if (y1 < x1){
          int p = y1;
          t += p;
          x1 -= p;
          y1 -= p;
          x2 = x1 - 1;
          y2 = y1 + 1;
        } else {
          break;
        }
      }
    }
    if (dx != dy){
      for (int id : mp2[x1 + y1]){
        long long t2 = t + (x[id] - x1) / (x2 - x1);
        ans[id] = min(ans[id], t2);
      }
      if (dx == 1 && dy == -1){
        if (n - x1 < y1){
          int p = n - x1;
          t += p;
          x1 += p;
          y1 -= p;
          x2 = x1 - 1;
          y2 = y1 - 1;
        } else if (y1 < n - x1){
          int p = y1;
          t += p;
          x1 += p;
          y1 -= p;
          x2 = x1 + 1;
          y2 = y1 + 1;
        } else {
          break;
        }
      }
      if (dx == -1 && dy == 1){
        if (x1 < m - y1){
          int p = x1;
          t += p;
          x1 -= p;
          y1 += p;
          x2 = x1 + 1;
          y2 = y1 + 1;
        } else if (m - y1 < x1){
          int p = m - y1;
          t += p;
          x1 -= p;
          y1 += p;
          x2 = x1 - 1;
          y2 = y1 - 1;
        } else {
          break;
        }
      }
    }
  }
  for (int i = 0; i < k; i++){
    if (ans[i] == INF){
      cout << -1 << "\n";
    } else {
      cout << ans[i] << "\n";
    }
  }
}
#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n), t(n);
    for (int j = 0; j < n; j++){
      cin >> x[j] >> y[j] >> t[j];
    }
    vector<vector<int>> E(n);
    map<int, vector<pair<int, int>>> mpx;
    for (int j = 0; j < n; j++){
      mpx[x[j]].push_back(make_pair(y[j], j));
    }
    for (auto &P : mpx){
      sort(P.second.begin(), P.second.end());
      int cnt = P.second.size();
      for (int j = 0; j < cnt - 1; j++){
        if (P.second[j + 1].first - P.second[j].first <= k){
          int u = P.second[j].second;
          int v = P.second[j + 1].second;
          E[u].push_back(v);
          E[v].push_back(u);
        }
      }
    }
    map<int, vector<pair<int, int>>> mpy;
    for (int j = 0; j < n; j++){
      mpy[y[j]].push_back(make_pair(x[j], j));
    }
    for (auto &P : mpy){
      sort(P.second.begin(), P.second.end());
      int cnt = P.second.size();
      for (int j = 0; j < cnt - 1; j++){
        if (P.second[j + 1].first - P.second[j].first <= k){
          int u = P.second[j].second;
          int v = P.second[j + 1].second;
          E[u].push_back(v);
          E[v].push_back(u);
        }
      }
    }
    vector<int> T;
    vector<bool> used(n, false);
    for (int j = 0; j < n; j++){
      if (!used[j]){
        used[j] = true;
        queue<int> Q;
        Q.push(j);
        int mn = INF;
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          mn = min(mn, t[v]);
          for (int w : E[v]){
            if (!used[w]){
              used[w] = true;
              Q.push(w);
            }
          }
        }
        T.push_back(mn);
      }
    }
    int cnt = T.size();
    int tv = cnt, fv = -1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      int cnt2 = 0;
      for (int j = 0; j < cnt; j++){
        if (T[j] > mid){
          cnt2++;
        }
      }
      if (cnt2 <= mid + 1){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}
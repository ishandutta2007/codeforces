#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, L, s, t;
  cin >> n >> m >> L >> s >> t;
  vector<int> u(m), v(m), w(m);
  for (int i = 0; i < m; i++){
    cin >> u[i] >> v[i] >> w[i];
  }
  map<pair<int, int>, int> mp;
  for (int i = 0; i < m; i++){
    mp[make_pair(u[i], v[i])] = i;
    mp[make_pair(v[i], u[i])] = i;
  }
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    E[u[i]].push_back(make_pair(i, v[i]));
    E[v[i]].push_back(make_pair(i, u[i]));
  }
  vector<long long> d1(n, -1);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq1;
  pq1.push(make_pair(0, s));
  while (!pq1.empty()){
    long long c = pq1.top().first;
    int v2 = pq1.top().second;
    pq1.pop();
    if (d1[v2] == -1){
      d1[v2] = c;
      for (auto P : E[v2]){
        int w2 = P.second;
        if (d1[w2] == -1){
          pq1.push(make_pair(c + max(w[P.first], 1), w2));
        }
      }
    }
  }
  vector<long long> d2(n, -1);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq2;
  pq2.push(make_pair(0, s));
  while (!pq2.empty()){
    long long c = pq2.top().first;
    int v2 = pq2.top().second;
    pq2.pop();
    if (d2[v2] == -1){
      d2[v2] = c;
      for (auto P : E[v2]){
        int w2 = P.second;
        if (d2[w2] == -1){
          if (w[P.first] != 0){
            pq2.push(make_pair(c + w[P.first], w2));
          } else {
            pq2.push(make_pair(c + L + 1, w2));
          }
        }
      }
    }
  }
  if (d1[t] == -1 || d1[t] > L || d2[t] < L){
    cout << "NO" << endl;
  } else if (d2[t] == L){
    for (int i = 0; i < m; i++){
      if (w[i] == 0){
        w[i] = L;
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < m; i++){
      cout << u[i] << ' ' << v[i] << ' ' << w[i] << endl;
    }
  } else {
    vector<int> p;
    p.push_back(t);
    while (p.back() != s){
      int v2 = p.back();
      int nxt = -1;
      for (auto P : E[v2]){
        int w2 = P.second;
        if (d1[w2] == d1[v2] - max(w[P.first], 1) && d1[w2] != -1){
          nxt = w2;
        }
      }
      assert(nxt != -1);
      p.push_back(nxt);
    }
    reverse(p.begin(), p.end());
    int cnt = p.size();
    vector<int> id;
    for (int i = 0; i < cnt - 1; i++){
      if (w[mp[make_pair(p[i], p[i + 1])]] == 0){
        id.push_back(mp[make_pair(p[i], p[i + 1])]);
      }
    }
    int cnt2 = id.size();
    for (int i = 0; i < m; i++){
      if (w[i] == 0){
        w[i] = L + 1;
      }
    }
    for (int i = 0; i < cnt2; i++){
      int tv = L + 1, fv = 0;
      while (tv - fv > 1){
        int mid = (tv + fv) / 2;
        w[id[i]] = mid;
        vector<long long> d3(n, -1);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq3;
        pq3.push(make_pair(0, s));
        while (!pq3.empty()){
          long long c = pq3.top().first;
          int v2 = pq3.top().second;
          pq3.pop();
          if (d3[v2] == -1){
            d3[v2] = c;
            for (auto P : E[v2]){
              int w2 = P.second;
              if (d3[w2] == -1){
                pq3.push(make_pair(c + w[P.first], w2));
              }
            }
          }
        }
        if (d3[t] >= L){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      w[id[i]] = tv;
    }
    cout << "YES" << endl;
    for (int i = 0; i < m; i++){
      cout << u[i] << ' ' << v[i] << ' ' << w[i] << endl;
    }
  }
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dist(n, vector<int> (n, n));
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    dist[i][i] = 0;
  }
  while (m--) {
    int l;
    cin >> l;
    int last = -1;
    while (l--) {
      int x;
      cin >> x;
      --x;
      if (~last) {
        adj[last].push_back(x);
        adj[x].push_back(last);
        dist[x][last] = dist[last][x] = 1;
      }
      last = x;
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (int tt = 0; tt < n; ++tt) {
    vector<int> candidates(n);
    for (int i = 0; i < n; ++i) {
      candidates.push_back(i);
    }
    while (true) {
      int root = -1;
      int remain = n;
      for (int x = 0; x < n; ++x) {
        int most = 0;
        for (auto y : adj[x]) {
          int current = 0;
          for (auto z : candidates) {
            if (dist[x][z] > dist[y][z]) {
              ++current;
            }
          }
          most = max(most, current);
        }
        if (remain > most) {
          remain = most;
          root = x;
        }
      }
      cout << root + 1 << endl;
      string type;
      cin >> type;
      if (type == "FOUND") {
        break;
      }
      int result;
      cin >> result;
      --result;
      vector<int> new_candidates;
      for (auto x : candidates) {
        if (dist[root][x] > dist[result][x]) {
          new_candidates.push_back(x);
        }
      }
      swap(candidates, new_candidates);
    }
  }
  return 0;
}
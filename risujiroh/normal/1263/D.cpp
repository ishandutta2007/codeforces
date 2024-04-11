#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> t;
  int num;
  UnionFind(int n) : t(n, -1), num(n) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
    --num;
  }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto&& e : s) {
    cin >> e;
  }
  UnionFind uf(n);
  for (char c = 'a'; c <= 'z'; ++c) {
    vector<int> idx;
    for (int i = 0; i < n; ++i) {
      if (s[i].find(c) != string::npos) {
        idx.push_back(i);
      }
    }
    for (int i : idx) {
      uf.unite(idx[0], i);
    }
  }
  cout << uf.num << '\n';
}
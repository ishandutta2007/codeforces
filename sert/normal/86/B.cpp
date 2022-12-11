#ifndef SERT
#include <bits/stdc++.h>
#endif

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
using namespace std;

bool D = false;

constexpr int dx[4] = {0, 0, -1, 1};
constexpr int dy[4] = {-1, 1, 0, 0};

void iterate(int y, int x, int n, int m, const function<void(int, int, int, int)> &f) {
  for (int dir = 0; dir < 4; dir++) {
    int yy = y + dy[dir];
    int xx = x + dx[dir];
    if (0 <= xx && xx < m && 0 <= yy && yy < n)
      f(yy, xx, y, x);
  }
}

void del(vector<int> &v, int x) {
  bool ok = false;
  for (int i = 0; !ok && i < (int)v.size(); i++) {
    if (v[i] == x) {
      ok = true;
      swap(v[i], v.back());
    }
  }
  if (ok) v.pop_back();
}

void solve() {
  int n, m;
  cin >> n >> m;
  //n = m = 1000;
  vector<string> s(n);
  for (auto &x : s) {
    cin >> x;
    //x = string(m, '.');
  }

  vector<vector<int>> es(n * m);
  for (auto &e : es) e.reserve(4);

  vector<int> deg(n * m);
  queue<int> q, q1;  

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] != '.') continue;
      int code = i * m + j;
      if (i > 0 && s[i - 1][j] == '.') { es[code].push_back(code - m); es[code - m].push_back(code); }
      if (j > 0 && s[i][j - 1] == '.') { es[code].push_back(code - 1); es[code - 1].push_back(code); }
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int code = i * m + j;
      deg[code] = es[code].size();
      if (deg[code] == 1)
        q1.push(code);
      else if (deg[code] > 1)
        q.push(code);
      else if (s[i][j] == '.') {
        cout << "-1\n";
        return;
      }
    }

  auto decDeg = [&](int v) {
    deg[v]--;
    if (deg[v] == 1)
      q1.push(v);
    else if (deg[v] > 1)
      q.push(v);
  };

  vector<pair<int, int>> comp;
  int u[10];
  for (int i = 0; i < 10; i++) u[i] = -1;
  int kk = 0;
  auto decode = [&m](int v) { return make_pair(v / m, v % m); };
  while (!q.empty() || !q1.empty()) {
    int v = -1;
    if (!q1.empty()) { v = q1.front(); q1.pop(); }
    else { v = q.front(); q.pop(); }
    int dg = deg[v];

    if (dg == 0) continue;

    comp.clear();
    comp.push_back(decode(v));
    if (dg > 1) { comp.push_back(decode(es[v][0])); }
    else {
      int w = es[v][0];
      comp.push_back(decode(w));
      for (int x : es[w]) { 
        if (x != v && deg[x] == 1)
          comp.push_back(decode(x));
      }
    }

    kk++;

    for (auto &[y, x] : comp) {      
      iterate(y, x, n, m, [&](int yy, int xx, int y, int x) { 
        char col = s[yy][xx];
        if (col == '.') {
          int code = yy * m + xx;
          decDeg(code);
          del(es[code], y * m + x);
        }
        if ('0' <= col && col <= '9')
          u[col - '0'] = kk;
      });            
    }

    char col = '!';
    for (int i = 9; i >= 0; i--)
      if (u[i] != kk) 
        col = char('0' + i);

    for (auto &[y, x] : comp) {
      s[y][x] = col;
      int code = y * m + x;
      while (deg[code])
        decDeg(code);
    }
  }
  for (auto &row : s)
    cout << row << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef SERT
  D = true;
  for (int i = 0; i < 1; i++) {
    solve();
    cout << "\n";
  }
#else
  solve();
#endif
}
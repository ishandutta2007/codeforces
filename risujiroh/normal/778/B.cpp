#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  map<string, int> id;
  struct var {
    int type;
    bitset<1000> bs;
    int a, b;
  };
  vector<var> v(n + 1);
  for (int i = 0; i < n; ++i) {
    string name;
    cin >> name;
    id[name] = i;
    string _;
    cin >> _;
    string s;
    cin >> s;
    if (all_of(begin(s), end(s), [](char c) { return c == '0' or c == '1'; })) {
      v[i].type = 0;
      for (int j = 0; j < m; ++j) {
        v[i].bs[j] = s[j] - '0';
      }
    } else {
      if (s == "?") {
        v[i].a = n;
      } else {
        v[i].a = id[s];
      }
      string op;
      cin >> op;
      if (op == "AND") {
        v[i].type = 1;
      } else if (op == "OR") {
        v[i].type = 2;
      } else {
        assert(op == "XOR");
        v[i].type = 3;
      }
      cin >> s;
      if (s == "?") {
        v[i].b = n;
      } else {
        v[i].b = id[s];
      }
    }
  }
  string mn, mx;
  for (int j = 0; j < m; ++j) {
    int s0 = 0;
    v[n].bs[j] = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i].type == 1) {
        v[i].bs[j] = v[v[i].a].bs[j] & v[v[i].b].bs[j];
      } else if (v[i].type == 2) {
        v[i].bs[j] = v[v[i].a].bs[j] | v[v[i].b].bs[j];
      } else if (v[i].type == 3) {
        v[i].bs[j] = v[v[i].a].bs[j] ^ v[v[i].b].bs[j];
      }
      s0 += v[i].bs[j];
    }
    int s1 = 0;
    v[n].bs[j] = 1;
    for (int i = 0; i < n; ++i) {
      if (v[i].type == 1) {
        v[i].bs[j] = v[v[i].a].bs[j] & v[v[i].b].bs[j];
      } else if (v[i].type == 2) {
        v[i].bs[j] = v[v[i].a].bs[j] | v[v[i].b].bs[j];
      } else if (v[i].type == 3) {
        v[i].bs[j] = v[v[i].a].bs[j] ^ v[v[i].b].bs[j];
      }
      s1 += v[i].bs[j];
    }
    mn += '0' + (s1 < s0);
    mx += '0' + (s1 > s0);
  }
  cout << mn << '\n';
  cout << mx << '\n';
}
#include <bits/stdc++.h>
using namespace std;

char readchar() {
  static char buf[1 << 15], *ptr = buf, *end = buf;
  if (ptr == end) ptr = buf, end = buf + fread(buf, 1, 1 << 15, stdin);
  return *ptr++;
}
void writechar(char c = 0) {
  static char buf[1 << 15], *ptr = buf;
  if (ptr == end(buf) or c == 0) fwrite(buf, 1, ptr - buf, stdout), ptr = buf;
  *ptr++ = c;
}
template <class Z = int> Z getint() {
  char c = readchar();
  bool neg = c == '-';
  Z res = neg ? 0 : c - '0';
  while (isdigit(c = readchar())) res = res * 10 + (c - '0');
  return neg ? -res : res;
}
template <class Z> void putint(Z a, char delim = '\n') {
  if (a < 0) writechar('-'), a = -a;
  int d[40], i = 0;
  do d[i++] = a % 10; while (a /= 10);
  while (i--) writechar('0' + d[i]);
  writechar(delim);
}
string getstring(char delim = '\n') {
  string res;
  for (char c; (c = readchar()) != delim; ) res += c;
  return res;
}
void putstring(string s, char delim = '\n') {
  for (char c : s) writechar(c);
  writechar(delim);
}

int main() {
  int n = getint(), m = getint();
  vector<vector<int>> a(n);
  for (int v = 0; v < n; ++v) {
    int k = getint();
    a[v].resize(k);
    for (auto&& e : a[v]) {
      e = getint() - 1;
    }
  }
  vector<vector<int>> g(n);
  for (int _ = n - 1; _--; ) {
    int u = getint() - 1, v = getint() - 1;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> col(m, -1);
  auto dfs = [&](auto&& self, int v, int p) -> void {
    set<int> se;
    for (int e : a[v]) {
      if (col[e] != -1) {
        se.insert(col[e]);
      }
    }
    int cur = 0;
    for (int e : a[v]) {
      if (col[e] == -1) {
        while (se.count(cur)) {
          ++cur;
        }
        se.insert(col[e] = cur);
      }
    }
    for (int u : g[v]) {
      if (u != p) {
        self(self, u, v);
      }
    }
  };
  dfs(dfs, 0, -1);
  for (auto&& e : col) {
    e = max(e, 0);
  }
  putint(*max_element(begin(col), end(col)) + 1);
  for (int i = 0; i < m; ++i) {
    putint(col[i] + 1, " \n"[i == m - 1]);
  }
  writechar();
}
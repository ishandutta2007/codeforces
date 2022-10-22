#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;
int n;

bool query(std::vector<int>& v) {
  printf("? %d", v.size());
  for (int _i = 0; _i < v.size(); ++_i) {
    printf(" %d", v[_i]);
  }
  puts("");
  fflush(stdout);
  static char str[10];
  scanf("%s", str);
  return strcmp(str, "YES") == 0;
}

std::vector<int> merge(std::vector<int> l, std::vector<int> r) {
  l.insert(l.end(), r.begin(), r.end());
  return l;
}

std::vector<int> check(std::vector<int> v) {
  if (v.size() < 3) {
    return v;
  }
  std::vector<int> w[3];
  for (int i = 0; i < v.size(); ++i) {
    w[i % 3].emplace_back(v[i]);
  }
  if (query(w[0])) {
    if (query(w[1])) {
      return check(merge(w[0], w[1]));
    } else {
      return check(merge(w[0], w[2]));
    }
  } else {
    if (query(w[0])) {
      if (query(w[1])) {
        return check(merge(w[0], w[1]));
      } else {
        return check(merge(w[0], w[2]));
      }
    } else {
      return check(merge(w[1], w[2]));
    }
  }
}

const int W = 82;
int g[40][40];
int main() {
  scanf("%d", &n);
  std::vector<int> v;
  for (int i = 1; i <= n; ++i) {
    v.emplace_back(i);
  }
  for (auto res : check(v)) {
    printf("! %d\n", res);
    fflush(stdout);
    static char str[10];
    scanf("%s", str);
    if (strcmp(str, ":)") == 0) {
      break;
    }
  }
  return 0;
}
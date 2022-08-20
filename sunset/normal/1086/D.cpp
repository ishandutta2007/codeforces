#include <bits/stdc++.h>

using namespace std;

template<typename T> class fenwick_t {
 public:
  vector<T> fenw;
  int n;

  fenwick_t(int n):n(n) {
    fenw.resize(n);
  }

  void modify(int x, T value) {
    while (x < n) {
      fenw[x] += value;
      x |= x + 1;
    }
  }

  T query(int x) {
    T result{};
    while (x >= 0) {
      result += fenw[x];
      x = (x & x + 1) - 1;
    }
    return result;
  }

  T get(int l, int r) {
    return query(r) - query(l - 1);
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<fenwick_t<int>> fenw(3, n);
  vector<set<int>> s(3);
  auto query = [&]() {
    int answer = 0;
    for (int i = 0; i < 3; ++i) {
      if (!s[(i + 1) % 3].empty()) {
        if (!s[(i + 2) % 3].empty()) {
          int l = *s[(i + 1) % 3].begin(), r = *s[(i + 1) % 3].rbegin();
          int ll = *s[(i + 2) % 3].begin(), rr = *s[(i + 2) % 3].rbegin();
          answer += fenw[i].get(ll, rr);
          answer += fenw[i].get(0, min(l, ll));
          answer += fenw[i].get(max(r, rr), n - 1);
        }
      } else {
        answer += s[i].size();
      }
    }
    return answer;
  };
  string str;
  cin >> str;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (str[i] == 'R') {
      a[i] = 0;
    }
    if (str[i] == 'P') {
      a[i] = 1;
    }
    if (str[i] == 'S') {
      a[i] = 2;
    }
    fenw[a[i]].modify(i, 1);
    s[a[i]].insert(i);
  }
  printf("%d\n", query());
  while (m--) {
    int pos;
    string type;
    cin >> pos >> type;
    --pos;
    fenw[a[pos]].modify(pos, -1);
    s[a[pos]].erase(pos);
    if (type == "R") {
      a[pos] = 0;
    }
    if (type == "P") {
      a[pos] = 1;
    }
    if (type == "S") {
      a[pos] = 2;
    }
    fenw[a[pos]].modify(pos, 1);
    s[a[pos]].insert(pos);
    printf("%d\n", query());
  }
  return 0;
}
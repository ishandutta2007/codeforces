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

template <class Key, class T> struct radix_heap {
  static_assert(is_integral<Key>::value, "");
  array<vector<pair<Key, T>>, sizeof(Key) * 8 + 1> v;
  Key last = 0;
  size_t sz = 0, ptr = 0;
  static int lg(Key a) { return a ? __lg(a) : -1; }
  void emplace(Key key, T val) {
    assert(key >= last);
    v[lg(key ^ last) + 1].emplace_back(key, val);
    ++sz;
  }
  void pull() {
    if (ptr < v[0].size()) return;
    v[0].clear(), ptr = 0;
    int i = 1;
    while (v[i].empty()) ++i;
    last = min_element(begin(v[i]), end(v[i]), [](auto a, auto b) {
      return a.first < b.first;
    })->first;
    for (auto e : v[i]) v[lg(e.first ^ last) + 1].push_back(e);
    v[i].clear();
  }
  pair<Key, T> top() { return pull(), v[0][ptr]; }
  void pop() { pull(), --sz, ++ptr; }
  bool empty() const { return sz == 0; }
};

int main() {
  for (int _ = getint(); _--; ) {
    int h = getint(), g = getint();
    vector<int> a(1 << h);
    generate(begin(a) + 1, end(a), getint<int>);
    vector<radix_heap<int, int>> rh(1 << (g - 1));
    for (int i = 1 << (g - 1); i < 1 << h; ++i) {
      int j = i;
      while (j >= 1 << g) {
        j >>= 1;
      }
      rh[j - (1 << (g - 1))].emplace(a[i], i);
    }
    bitset<1 << 20> bs;
    vector<int> b(1 << g);
    vector<int> l(1 << g), r(1 << g);
    for (int i = 1 << g; i-- > 1; ) {
      if (i >= 1 << (g - 1)) {
        int j = i - (1 << (g - 1));
        b[i] = rh[j].top().first;
        rh[j].pop();
        bs[b[i]] = 1;
        l[i] = j, r[i] = j + 1;
      } else {
        int mx = max(b[2 * i], b[2 * i + 1]);
        l[i] = l[2 * i], r[i] = r[2 * i + 1];
        rh[l[i]].emplace(a[i], i);
        int mn = 1e9, mj = -1;
        for (int j = l[i]; j < r[i]; ++j) {
          while (not rh[j].empty() and rh[j].top().first < mx) {
            rh[j].pop();
          }
          if (not rh[j].empty() and rh[j].top().first < mn) {
            mn = rh[j].top().first;
            mj = j;
          }
        }
        assert(mj != -1);
        b[i] = rh[mj].top().first;
        rh[mj].pop();
        bs[b[i]] = 1;
      }
    }
    long long sum = 0;
    vector<int> res;
    for (int i = 1 << h; i-- > 1; ) {
      if (bs[a[i]] == 0) {
        res.push_back(i);
      } else {
        sum += a[i];
      }
    }
    putint(sum);
    int sz = res.size();
    assert(sz == (1 << h) - (1 << g));
    for (int i = 0; i < sz; ++i) {
      putint(res[i], " \n"[i == sz - 1]);
    }
  }
  writechar();
}
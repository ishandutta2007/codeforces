#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <bitset>
#include <random>
#include <chrono>
#include <unistd.h>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 1000005;
const int SIZE = 270;
const int MAX_LEN = 40005;
using v2 = bitset<SIZE>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool np[1005];
int p[170], pc = 0;

void sieve(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!np[i]) {
      p[pc++] = i;
      for (int j = i * 2; j <= n; j += i)
        np[j] = true;
    }
  }
}

vector<int> s[N];
int xs[N];
int len;
int n, c;
vector<int> P;

bitset<MAX_LEN> avail, aug;
int pre[MAX_LEN];
v2 e[20], _t[20];
vector<int> s1[MAX_LEN], s2[MAX_LEN];
bool type[40005];

pair<v2, bool> eliminate(int n) {
  v2 sol;
  static int var[20];
  bool is_uniq = true;
  memset(var, -1, sizeof(var));
  for (int i = 0, j = 0; j < n && i < len; ++j) {
    int l = -1;
    // LOG("j = %d\n", j);
    for (int k = i; k < len; ++k) {
      // LOG("k = %d\n", k);
      if (e[k].test(j)) { l = k; break; }
    }
    if (l == -1) { is_uniq = false; sol.set(j, rng() & 1); continue; }
    if (l != i) swap(e[l], e[i]);
    var[i] = j;
    for (int k = i + 1; k < len; ++k)
      if (e[k].test(j)) e[k] ^= e[i];
    ++i;
  }
  for (int i = len - 1; i >= 0; --i)
    if (~var[i]) sol.set(var[i], ((sol & e[i]).count() & 1) ^ e[i].test(n));
  return {sol, is_uniq};
}

int cnt = 0;

bool solve() {
  int sum = 0;
  vector<int> uni_s;
  memset(type, 0, sizeof(type));
  avail.reset();
  avail.set(0);
  int cnt = 0;
  for (int p : P) {
    int n = s[p].size();
    if (n == 1) {
      if (xs[p]) {
        ++sum;
        uni_s.push_back(p);
      }
      continue;
    }
    for (int b = 0; b < len; ++b) {
      for (int i = 0; i < n; ++i)
        e[b].set(i, (s[p][i] >> b) & 1);
      e[b].set(n, (xs[p] >> b) & 1);
      _t[b] = e[b];
    }
    auto [sol, uniq] = eliminate(n);
    if (uniq) {
      for (int i = 0; i < n; ++i)
        if (sol.test(i))
          ++sum, uni_s.push_back(s[p][i]);
    }
    else {
      auto to_vec = [&](const v2 &v) -> vector<int> {
        vector<int> r;
        for (int i = 0; i < n; ++i)
          if (v.test(i)) r.push_back(s[p][i]);
        return r;
      };
      s1[cnt] = to_vec(sol);
      copy_n(_t, len, e);
      s2[cnt] = to_vec(eliminate(n).first);
      if (s1[cnt].size() > s2[cnt].size()) swap(s1[cnt], s2[cnt]);
      sum += s1[cnt].size();
      if (s1[cnt].size() == s2[cnt].size()) {
        uni_s.insert(uni_s.end(), all(s1[cnt]));
        continue;
      }
      aug = (avail << (s2[cnt].size() - s1[cnt].size())) & ~avail;
      for (int i = aug._Find_first(); i != (int)aug.size(); i = aug._Find_next(i))
        pre[i] = cnt;
      avail |= aug;
      ++cnt;
    }
  }
  if (c < sum || !avail.test(c - sum)) return false;
  vector<int> res = move(uni_s);
  for (int i = c - sum; i; i -= s2[pre[i]].size() - s1[pre[i]].size()) {
    type[pre[i]] = true;
    res.insert(res.end(), all(s2[pre[i]]));
  }
  for (int i = 0; i < cnt; ++i)
    if (!type[i])
      res.insert(res.end(), all(s1[i]));
  for (int x : res)
    printf("%d ", x);
  putchar('\n');
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  sieve(1000);
  read(n, c);
  len = __lg(n) + 1;
  for (int i = 1; i <= n; ++i) {
    int r = 1;
    int num = i;
    for (int j = 0; j < pc; ++j) {
      if (num % p[j] == 0) {
        r *= p[j];
        do num /= p[j]; while (num % p[j] == 0);
      }
    }
    if (num > 1) r *= num;
    s[r].push_back(i);
  }

  for (int i = 1; i <= n; ++i)
    if (!s[i].empty()) P.push_back(i);
  printf("%d ", (int)P.size());
  for (int x : P)
    printf("%d ", x);
  putchar('\n');
  fflush(stdout);
  for (int p : P)
    read(xs[p]);
  for (int i = 2; i <= n; ++i)
    if (!s[i].empty()) xs[i] ^= xs[1];
  for (int i = n / 2; i >= 2; --i)
    if (!s[i].empty())
      for (int j = i * 2; j <= n; j += i)
        xs[j] ^= xs[i];
  for (int i = 1; i <= n; ++i)
    if (s[i].empty()) xs[i] = 0;
  for (int i = n / 2; i >= 2; --i)
    if (!s[i].empty())
      for (int j = i * 2; j <= n; j += i)
        xs[i] ^= xs[j];
  xs[1] = accumulate(xs + 1, xs + 1 + n, 0, bit_xor<>());
  assert(xs[1] == 0 || xs[1] == 1);
  while (!solve());
  return 0;
}
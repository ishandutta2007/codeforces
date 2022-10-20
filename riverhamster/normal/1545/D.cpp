#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define all(cont) begin(cont), end(cont)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }
const int N = 1005;

int a[N][N];
int d[N];
int n, m;
ll sqsum[N];

ll square_sum(int i) {
  ll sum = 0;
  for (int j = 0; j < m; ++j)
    sum += (ll)a[i][j] * a[i][j];
  return sum;
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  read(m, n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      read(a[i][j]);
  fill_n(d, n, 0);
  for (int i = 1; i < n; ++i)
    for (int j = 0; j < m; ++j)
      d[i] += a[i][j] - a[i - 1][j];
  int val = d[1];
  int cnt = 1;
  for (int i = 2; i < n; ++i)
    if (d[i] == val) ++cnt;
    else if (cnt) --cnt;
    else val = d[i], cnt = 1;
  int pos = 0;
  for (int i = 1; i < n; ++i)
    if (d[i] != val) {
      pos = i;
      break;
    }
  for (int i = 0; i < n; ++i)
    sqsum[i] = square_sum(i);
  ll v2sum_2 = 0;
  for (int i = 0; i < n; ++i)
    if (i != pos && (i + 1) != pos && (i + 2) != pos) {
      v2sum_2 = sqsum[i + 2] + sqsum[i] - 2 * sqsum[i + 1];
      break;
    }
  ll sum = accumulate(a[0], a[0] + m, 0LL) + (ll)val * pos;
  ll sp = accumulate(a[pos], a[pos] + m, 0LL);
  for (int j = 0; j < m; ++j) {
    ll v = sum - (sp - a[pos][j]);
    if (v > 1000000) continue;
    ll sqs_2 = sqsum[pos + 1] + sqsum[pos - 1] - 2 * (sqsum[pos] - (ll)a[pos][j] * a[pos][j] + (ll)v * v);
    if (sqs_2 == v2sum_2) {
      cout << (int32_t)pos << ' ' << (int64_t)v << endl;
      return 0;
    }
  }
  return 0;
}
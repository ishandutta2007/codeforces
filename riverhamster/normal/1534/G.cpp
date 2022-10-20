#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <tuple>
#include <ext/pb_ds/priority_queue.hpp>
#include <queue>
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

const int N = 800005;

struct item {
  ll pos, val;
  bool operator<(const item &rhs) const { return pos < rhs.pos; }
  bool operator>(const item &rhs) const { return pos > rhs.pos; }
};

template<class cmp>
struct tag_heap {
  __gnu_pbds::priority_queue<item, cmp> H;
  ll sum;
  ll tag;
  
  size_t size() { return H.size(); }
  item top() { return {H.top().pos + tag, H.top().val}; }
  void pop() { sum -= H.top().val; H.pop(); }
  void emplace(ll pos, ll val) { sum += val; H.push({pos - tag, val}); }
  void push(const item &i) { emplace(i.pos, i.val); }
};
tag_heap<less<item>> L;
tag_heap<greater<item>> R;

ll lpos = -1e9;
ll lval = 2e18;

struct pt {
  ll x, y;
  bool operator<(const pt &r) const { return x < r.x; }
} p[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  for (int i = 0; i < n; ++i) {
    read(p[i].x, p[i].y);
    tie(p[i].x, p[i].y) = make_pair(p[i].x + p[i].y, p[i].x - p[i].y);
  }
  sort(p, p + n);
  L.emplace(-1e9, -2e9);
  R.emplace(0, 4e9);
  ll last = 0;
  for (int i = 0; i < n; last = p[i].x, ++i) {
    if (p[i].x != last) {
      int k = p[i].x - last;
      lpos -= k;
      auto e = R.top(); R.pop();
      L.tag -= k; R.tag += k;
      if (L.sum) R.emplace(e.pos - k, -L.sum);
      if (e.val + L.sum) R.emplace(e.pos + k, e.val + L.sum);
    }
    lval += abs(lpos - p[i].y);
    L.emplace(lpos, -1);
    if (p[i].y <= L.top().pos) L.emplace(p[i].y, 2);
    else R.emplace(p[i].y, 2);
    while (L.sum >= 0)
      R.push(L.top()), L.pop();
    while (L.sum + R.top().val < 0)
      L.push(R.top()), R.pop();
  }
  ll pos = R.top().pos;
  ll res = lval;
  for (const item &i : L.H)
    res += i.val * (pos - (i.pos + L.tag));
  printf("%lld\n", res >> 1);
  return 0;
}
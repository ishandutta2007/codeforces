#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
pii p, q, r, pp, qq, rr;
multiset <pii> s;
multiset <pii> :: iterator it;

#define N 100100

map <int, int> mp;
int n, xx, a[N], b[N], cnt, x[N][3], runs;

int main() {
 // freopen("c.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) {
      scanf("%d", &xx);
      if (mp[xx]) b[mp[xx]] ++;
      else {
        mp[xx] = ++cnt, a[cnt] = xx, b[cnt] = 1;
      }
  }
  for (int i = 1; i <= cnt; i ++) {
    p.first = -b[i], p.second = a[i];
    s.insert(p);
  }
  while (!s.empty()) {
    it = s.begin();
    p = *it;
    it ++;
    if (it == s.end()) break;
    q = *it;
    it ++;
    if (it == s.end()) break;
    r = *it;
    x[runs][0] = p.second, x[runs][1] = q.second, x[runs++][2] = r.second;
    pp = p, pp.first ++;
    qq = q, qq.first ++;
    rr = r, rr.first ++;
    s.erase(p), s.erase(q), s.erase(r);
    if (pp.first) s.insert(pp);
    if (qq.first) s.insert(qq);
    if (rr.first) s.insert(rr);
  }
  printf("%d\n", runs);
  for (int i = 0; i < runs; i ++) {
    sort(x[i], x[i] + 3);
    printf("%d %d %d\n", x[i][2], x[i][1], x[i][0]);
  }
  return 0;
}
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

struct pt {
  int x, y;
  pt() : x(0), y(0) {}
  pt(int x, int y) : x(x), y(y) {}

  bool operator<(const pt &p) const {
    return false;
  }
};

int dist(pt p1, pt p2) {
  return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}


const int N = 14, M = 101;
int md[1 << N][N], mdq[1 << N][M], inf = 1e9 + 7;
int mq[M][1 << N], mt[M][1 << N], d[M][1 << N];

int getnum(int c, int ms) {
  return (c << N) + ms;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pt> a(n);
  vector<pair<int, pt>> b(m);
  rep(i, n)
    cin >> a[i].x >> a[i].y;
  rep(i, m)
    cin >> b[i].second.x >> b[i].second.y >> b[i].first;
  sort(all(b));
  int pw = 1 << n;
  rep(i, pw) {
    rep(j, n) {
      md[i][j] = inf;
      rep(k, n)
        if ((i >> k) & 1)
          md[i][j] = min(md[i][j], dist(a[j], a[k]));
    }
    rep(j, m) {
      mdq[i][j] = inf;
      rep(k, n)
        if ((i >> k) & 1)
          mdq[i][j] = min(mdq[i][j], dist(b[j].second, a[k]));
    }
  }
  priority_queue<pair<int, int>> q;
  rep(i, m + 1)
    rep(j, pw)
      mt[i][j] = inf;
  rep(i, m)
    mq[i][0] = 1;
  rep(i, n) {
    mt[0][1 << i] = 0;
    q.push({0, getnum(0, 1 << i)});
  }
  int bp = 0;
  while (!q.empty() || bp < m) {
    if (bp == m || (!q.empty() && -q.top().first < b[bp].first)) {
      int num = q.top().second;
      int c = num >> N;
      int ms = num % (1 << N);
      q.pop();
      if (d[c][ms])
        continue;
      d[c][ms] = 1;
      rep(i, m)
        if (mt[c][ms] + mdq[ms][i] <= b[i].first && mq[i][ms] < c + 1) {
          mq[i][ms] = c + 1;
          // q.push({-b[i].first, getnum(0, i, ms)});
        }
      rep(i, n) {
        if ((ms >> i) & 1)
          continue;
        int nd = mt[c][ms] + md[ms][i];
        int nm = ms | (1 << i);
        if (nd < mt[c][nm]) {
          // q.erase({mt[c][nm], getnum(1, c, nm)});
          mt[c][nm] = nd;
          q.push({-nd, getnum(c, nm)});
        }
      }
    } else {
      int c = bp++;
      rep(ms, pw) {
        if (mq[c][ms] == 0)
          continue;
        for (int i = c + 1; i < m; ++i)
          if (min(dist(b[c].second, b[i].second), mdq[ms][i]) <= b[i].first - b[c].first && mq[i][ms] < mq[c][ms] + 1) {
            mq[i][ms] = mq[c][ms] + 1;
            // q.push({-b[i].first, getnum(0, i, ms)});
          }
        rep(i, n) {
          if ((ms >> i) & 1)
            continue;
          int nd = b[c].first + min(dist(b[c].second, a[i]), md[ms][i]);
          int nm = ms | (1 << i);
          int nq = mq[c][ms];
          if (nd < mt[nq][nm]) {
            //q.erase({mt[nq][nm], getnum(1, nq, nm)});
            mt[nq][nm] = nd;
            q.push({-nd, getnum(nq, nm)});
          }
        }
      }
    }
  }
  int ans = 0;
  rep(i, m)
    rep(j, pw)
    ans = max(ans, mq[i][j]);
  rep(i, m + 1)
    rep(j, pw)
    if (mt[i][j] < inf)
      ans = max(ans, i);
  cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif

typedef pair<int, int> pii;
typedef long long ll;
const int inf = 2000 << 20;
#define fi first
#define se second
#define sz(x) int((x).size())
int main() {
   int n;
   cin >> n;
   vector<int> vx(n), vy(n);
   vector<pii> pts(n);

   auto dist = [&](pii a, pii b) -> int {
      if (a.fi == b.fi) return abs(a.se - b.se);
      if (a.se == b.se) return abs(a.fi - b.fi);
      return inf;
   };

   map<pii, int> xy, yx;
   xy[pii(-inf, -inf)] = xy[pii(inf, inf)] = -1;
   yx[pii(-inf, -inf)] = yx[pii(inf, inf)] = -1;
   for (int i = 0; i < n; ++i) {
      cin >> vx[i] >> vy[i];
      pts[i] = pii(vx[i], vy[i]);
      xy[pii(vx[i], vy[i])] = i;
      yx[pii(vy[i], vx[i])] = i;
   }
   set<int> xs(vx.begin(), vx.end()), ys(vy.begin(), vy.end());

   pp(vx, vy, pts, xs, ys);

   // 1. compute list of all cands (potential place to build)
   vector<pii> tocheck;
   // (x, y)
   for (int x: xs) {
      for (int y: ys) {
         tocheck.push_back(pii(x, y));
      }
   }

   // hor & vert midpoints
   pii prv = xy.begin()->fi;
   for (auto pp: xy) {
      pii p = pp.fi;
      if (prv != p && prv.fi == p.fi) {
         tocheck.push_back(pii(p.fi, (prv.se + p.se) / 2));
      }
      prv = p;
   }
   prv = yx.begin()->fi;
   for (auto pp: yx) {
      pii p = pp.fi;
      if (prv != p && prv.fi == p.fi) {
         tocheck.push_back(pii((prv.se + p.se) / 2, p.fi));
      }
      prv = p;
   }
   pp(tocheck);

   // 2. for each cands, compute list (up to 4) closest neighbors (dist, ids) in each dir, sort
   vector<vector<pii>> cands;

   for (pii p: tocheck) {
      vector<pii> neighbors;
      auto it = xy.lower_bound(p);
      int a = it->second, b = (--it)->second;
      it = yx.lower_bound(pii(p.se, p.fi));
      int c = it->second, d = (--it)->second;
      vector<int> v({ a, b, c, d });
      for (int i: v) {
         if (i == -1) continue;
         int d = dist(p, pts[i]);
         if (d < inf) {
            neighbors.push_back(pii(d, i));
         }
      }
      sort(neighbors.begin(), neighbors.end());
      cands.push_back(neighbors);
   }
   pp(cands);

   // 3. compute n^2 edges and sort
   vector<pair<int, pii>> edges;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         int d = dist(pts[i], pts[j]);
         if (d >= inf) continue;
         edges.emplace_back(d, pii(i, j));

      }
   }
   sort(edges.begin(), edges.end());
   pp(edges);

   // 4. check what ans would be if you have to build final guy now
   vector<int> group(n);
   for (int i = 0; i < n; ++i) group[i] = i;
   int numGroups = n;
   int ans = inf;
   int t = 0;
   auto check = [&]() -> int {
      if (numGroups > 4) return inf;
      if (numGroups == 1) return t;
      pp("Checking", numGroups, t, group);
      int ret = inf;
      for (auto &v: cands) {
         set<int> s;
         for (auto &p: v) {
            s.insert(group[p.se]);
            if (sz(s) >= numGroups) {
               pp("Found", p, v);
               ret = min(ret, max(t, p.fi));
            }
         }
      }
      return ret;
   };
   ans = min(ans, check());

   // 5. kruskal & re-check after every update
   for (auto p: edges) {
      int a = p.se.fi, b = p.se.se;
      if (group[a] == group[b]) continue;
      int ga = group[a];
      for (int &i: group) if (i == ga) i = group[b];
      --numGroups;
      t = p.fi;
      ans = min(ans, check());
   }

   if (ans == inf) ans = -1;
   cout << ans << "\n";
}
// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
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
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
// =========== Book ============ //

// ============= Solution ============= //
int main() {
   /*
    * dp state (A states): 2^n * m -- S, the subset of towers that have been visited, and q, the quest you are on (determines x, y, t)
    * dp value: the maximum number of quests you could've completed
    *
    * starting state: any tower (no quests completed, time 0), any quest (no towers visited, 1 quest completed)
    *
    *
    * given S, q, first compute for all supersets T of S, the earliest you can get to the intermediate state "visited T and on a tower"
    *
    * then given a fixed T and known time[T], compute for all quests j whether it's possible to complete quest j; t[j] <= dist[T][j] + time[T]
    *
    * visiting a node (S, q) takes total ... time
    * (number of T) * m
    * -> 3^n * m^2 = 3^14 * 100^2 = 47 billion...
    *
    *  too slow!
    *  but 470 million is not too slow... if we shave off a factor of m, maybe?
    *
    *
    * introducing more states (B states):
    * 2^n * m -- the subset of towers that have been visited (and you are on a tower), with m quests completed.
    * dpval = the min time it takes to get to that state.
    *
    * the next thing you do is always:
    * - complete a series of quests (possibly 0)
    * - then visit a tower
    *
    * so,
    * A-States: (q, T)
    * B-States: (T, cnt)
    *
    * A->B: 1 edges (q, T), d -> (T, d), time[q],
    * A->B: n edges (q, T), d -> (T + x, d), time[q] + dist(q, x)
    * A->A: m edges (q, T), d -> (q', T), d + 1, if dist(q, q') + time[q] <= time[q']
    * B->A: m edges  (T, cnt), t -> (q, T), cnt, if t + dist(T, q) <= time[q]
    * B->B: n edges  (T, cnt), t -> (T + x, cnt), t + dist(T, x)
    * 
    * total num nodes: ~4 million
    * total num edges: (n + m) * (2^n * m * 2) = 370 million
    * dijkstra will probably run in time?
    *
    * important note: process all nodes in order of TIME; for B, that's dpval[B]. for A, that's time[q]
    *
    */
   

   using node = tuple<int, int, int, int>; // (t, type, s, q/cnt)
   using PQ = priority_queue<node, vector<node>, greater<node>>;

   int n, m;
   cin >> n >> m;
   vector<int> XA(n), YA(n);
   for (int i = 0; i < n; ++i) {
      cin >> XA[i] >> YA[i];
   }
   vector<int> XB(m), YB(m), T(m);
   for (int i = 0; i < m; ++i) {
      cin >> XB[i] >> YB[i] >> T[i];
   }

   auto manhattan = [&](int x1, int y1, int x2, int y2) -> int {
      return abs(x1 - x2) + abs(y1 - y2);
   };
   int inf = 1000 << 20;
   vector<vector<int>> towersToQuest(1 << n, vector<int>(m, inf));
   vector<vector<int>> towersToTower(1 << n, vector<int>(n, inf));

   for (int i = 0; i < (1 << n); ++i) {
      for (int j = 0; j < n; ++j) {
         if (!((i >> j) & 1)) continue;
         for (int k = 0; k < m; ++k) {
            int dt = manhattan(XA[j], YA[j], XB[k], YB[k]);
            towersToQuest[i][k] = min(towersToQuest[i][k], dt);
         }
         for (int k = 0; k < n; ++k) {
            int dt = manhattan(XA[j], YA[j], XA[k], YA[k]);
            towersToTower[i][k] = min(towersToTower[i][k], dt);
         }
      }
   }

   vector<vector<int>> dp(1 << n, vector<int>(m, -inf));
   vector<vector<int>> dst(1 << n, vector<int>(m, inf));
   PQ pq;
   for (int j = 0; j < m; ++j) {
      pq.push({T[j], 1, 0, j});
   }
   auto pshB = [&](int msk, int cnt, int t) -> void {
      if (t < dst[msk][cnt]) {
         dst[msk][cnt] = t;
         pq.push({t, 2, msk, cnt});
      }
   };
   for (int i = 0; i < n; ++i) {
      pshB(1 << i, 0, 0); // spawn at tower
   }
   for (int i = 0; i < m; ++i) {
      dp[0][i] = 1; // spawn at quest
   }
   while (!pq.empty()) {
      node cur = pq.top();
      pq.pop();
      int t = get<0>(cur), type = get<1>(cur), msk = get<2>(cur);
      if (type == 1) {
         int q = get<3>(cur);
         for (msk = 0; msk < (1 << n); ++msk) {
            int cnt = dp[msk][q];
            if (cnt < 0) continue;
            pp("A", msk, q, cnt);

            // A->B (teleport to tower grid)
            pshB(msk, cnt, t);

            // A->B (walk to a tower)
            for (int i = 0; i < n; ++i) {
               if ((msk >> i) & 1) continue;
               int dt = manhattan(XA[i], YA[i], XB[q], YB[q]);
               pshB(msk | (1 << i), cnt, t + dt);
            }

            // A->A (walk to a  quest)
            for (int i = 0; i < m; ++i) {
               if (i == q) continue;
               int dt = manhattan(XB[i], YB[i], XB[q], YB[q]);
               if (t + dt <= T[i]) {
                  dp[msk][i] = max(dp[msk][i], cnt + 1);
               }
            }
         }
      } else {
         int cnt = get<3>(cur);
         if (dst[msk][cnt] < t) continue;
         pp("B", msk, cnt, t);

         // B->A (walk to a quest)
         for (int i = 0; i < m; ++i) {
            int dt = towersToQuest[msk][i];
            if (t + dt <= T[i]) {
               dp[msk][i] = max(dp[msk][i], cnt + 1);
            }
         }

         // B->B (walk to a tower)
         for (int i = 0; i < n; ++i) {
            if ((msk >> i) & 1) continue;
            int dt = towersToTower[msk][i];
            pshB(msk | (1 << i), cnt, t + dt);
         }
      }
   }

   int ans = 0;
   for (int i = 0; i < (1 << n); ++i) {
      for (int j = 0; j < m; ++j) {
         ans = max(ans, dp[i][j]);
      }
   }
   cout << ans << "\n";
}


// ============== Notes =============== //
// common bugs
// - fastio
// - int overflow (especially intermediate expressionns)
// - array bounds (indices bigger than MAXN?)
// - special cases (n=1? graph not connected?)
// - re-initialize efficiently between test cases
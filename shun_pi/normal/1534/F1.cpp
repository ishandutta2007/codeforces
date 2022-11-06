#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<int, int>;
using PL = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr lint B1 = 1532834020;
constexpr lint M1 = 2147482409;
constexpr lint B2 = 1388622299;
constexpr lint M2 = 2147478017;
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
template<class T>void chmax(T &a, const T &b) { if (a<b) a=b; }
template<class T>void chmin(T &a, const T &b) { if (b<a) a=b; }

#include <algorithm>

#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder

using namespace atcoder;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  REP(i, n) cin >> s[i];
  vector<int> a(m);
  REP(i, m) cin >> a[i];
  bool ok = true;
  REP(i, m) if(a[i] > 0) ok = false;
  if(ok) {
    cout << 0 << endl;
    return 0;
  }
  vector<set<int>> col(m);
  REP(i, n) REP(j, m) if(s[i][j] == '#') col[j].insert(i);
  scc_graph graph(n*m);
  vector<vector<int>> nbr(n*m);

  REP(i, n) REP(j, m) {
    if(s[i][j] == '.') continue;
    if(i > 0 && s[i-1][j] == '#') {
      graph.add_edge((i-1)*m+j, i*m+j);
      nbr[(i-1)*m+j].push_back(i*m+j);
    }
    auto itr = col[j].upper_bound(i);
    if(itr != col[j].end()) {
      graph.add_edge((*itr)*m+j, i*m+j);
      nbr[(*itr)*m+j].push_back(i*m+j);
    }
    if(j > 0) {
      itr = col[j-1].lower_bound(i);
      if(itr != col[j-1].end()) {
        graph.add_edge((*itr)*m+j-1, i*m+j);
        nbr[(*itr)*m+j-1].push_back(i*m+j);
      }
    }
    if(j < m-1) {
      itr = col[j+1].lower_bound(i);
      if(itr != col[j+1].end()) {
        graph.add_edge((*itr)*m+j+1, i*m+j);
        nbr[(*itr)*m+j+1].push_back(i*m+j);
      }
    }
  }
  vector<vector<int>> ret = graph.scc();
  int ans = 0;
  REP(i, ret.size()) {
    int a = ret[i][0];
    if(s[a/m][a%m] == '.') continue;
    set<int> st;
    for(int x : ret[i]) st.insert(x);
    bool ok = true;
    for(int x : ret[i]) {
      for(int y : nbr[x]) {
        if(st.find(y) == st.end()) ok = false;
      }
    }
    if(ok) ans++;
  }
  cout << ans << endl;
}
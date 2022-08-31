#include <bits/stdc++.h>

using namespace std;

template<typename T>
vector<int> suffix_array(const T &s, int n, int alpha) {
  vector<int> a(n);
  if (~alpha) {
    vector<int> bucket(alpha);
    for (int i = 0; i < n; ++i) {
      ++bucket[s[i]];
    }
    int sum = 0;
    for (int i = 0; i < alpha; ++i) {
      int add = bucket[i];
      bucket[i] = sum;
      sum += add;
    }
    for (int i = 0; i < n; ++i) {
      a[bucket[s[i]]++] = i;
    }
  } else {
    for (int i = 0; i < n; ++i) {
      a[i] = i;
    }
    sort(a.begin(), a.end(), [&](const int &x, const int &y) {
      return s[x] < s[y];
    });
  }
  vector<int> sorted_by_second(n);
  vector<int> ptr_group(n);
  vector<int> new_group(n);
  vector<int> group(n);
  group[a[0]] = 0;
  for (int i = 1; i < n; ++i) {
    group[a[i]] = group[a[i - 1]] + (s[a[i]] != s[a[i - 1]]);
  }
  int step = 1;
  while (group[a[n - 1]] < n - 1) {
    int ptr = 0;
    for (int i = n - step; i < n; ++i) {
      sorted_by_second[ptr++] = i;
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] >= step) {
        sorted_by_second[ptr++] = a[i] - step;
      }
    }
    for (int i = n - 1; ~i; --i) {
      ptr_group[group[a[i]]] = i;
    }
    for (int i = 0; i < n; ++i) {
      int x = sorted_by_second[i];
      a[ptr_group[group[x]]++] = x;
    }
    new_group[a[0]] = 0;
    for (int i = 1; i < n; ++i) {
      if (group[a[i]] != group[a[i - 1]]) {
        new_group[a[i]] = new_group[a[i - 1]] + 1;
      } else {
        int prev = a[i - 1] + step >= n ? -1 : group[a[i - 1] + step];
        int now = a[i] + step >= n ? -1 : group[a[i] + step];
        new_group[a[i]] = new_group[a[i - 1]] + (prev != now);
      }
    }
    group = new_group;
    step <<= 1;
  }
  return a;
}

template<typename T>
vector<int> build_lcp(const T &s, int n, const vector<int> &sa) {
  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[sa[i]] = i;
  }
  vector<int> lcp(n - 1);
  for (int i = 0, k = 0; i < n; ++i) {
    k = max(k - 1, 0);
    if (pos[i] == n - 1) {
      k = 0;
    } else {
      int j = sa[pos[i] + 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
        ++k;
      }
      lcp[pos[i]] = k;
    }
  }
  return lcp;
}

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int n): n(n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  inline int find(int x) {
    while (x != p[x]) {
      x = p[x] = p[p[x]];
    }
    return x;
  }

  inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    } else {
      p[x] = y;
      return true;
    }
  }
};

template<typename A, typename B>
void operator += (pair<A, B> &a, const pair<A, B> &b) {
  a.first += b.first;
  a.second += b.second;
}

template<typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int n): n(n) {
    fenw.resize(n);
  }

  void modify(int x, T value) {
    while (x < n) {
      fenw[x] += value;
      x |= x + 1;
    }
  }

  T query(int x) {
    T res{};
    while (x >= 0) {
      res += fenw[x];
      x = (x & x + 1) - 1;
    }
    return res;
  }
};

struct event {
  int type, u, v, id;

  event(int type, int u, int v, int id): type(type), u(u), v(v), id(id) {
  }

  bool operator < (const event &b) const {
    return v < b.v || (v == b.v && type < b.type);
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int m = n * 2 - 1;
  int lg = 0;
  while (1 << lg <= n) {
    ++lg;
  }
  vector<vector<int>> anc(lg, vector<int>(m, -1));
  vector<vector<int>> adj(m);
  vector<int> len(m), sz(m), pr(m, -1);
  vector<int> dfn(m), top(m), seq;
  {
    vector<int> sa = suffix_array(s, n, 256);
    vector<int> lcp = build_lcp(s, n, sa);
    vector<vector<int>> events(n);
    for (int i = 0; i < n - 1; ++i) {
      events[lcp[i]].push_back(i);
    }
    dsu p(m);
    for (int i = 0; i < n; ++i) {
      len[i] = n - i;
      sz[i] = 1;
    }
    for (int i = n - 1, j = n; ~i; --i) {
      for (auto x : events[i]) {
        int u = p.find(sa[x]), v = p.find(sa[x + 1]);
        if (sz[u] < sz[v]) {
          swap(u, v);
        }
        len[j] = i;
        pr[u] = pr[v] = j;
        sz[j] = sz[u] + sz[v] + 1;
        adj[j].push_back(u);
        adj[j].push_back(v);
        p.unite(u, j);
        p.unite(v, j);
        ++j;
      }
    }
    function<void(int, int)> hld = [&](int x, int c) {
      dfn[x] = seq.size();
      seq.push_back(x);
      top[x] = c;
      if (x >= n) {
        hld(adj[x][0], c);
        hld(adj[x][1], adj[x][1]);
      }
    };
    hld(m - 1, m - 1);
    anc[0] = pr;
    for (int i = 1; i < lg; ++i) {
      for (int j = 0; j < m; ++j) {
        if (~anc[i - 1][j]) {
          anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
      }
    }
  }
  int tt;
  cin >> tt;
  vector<int> ll(tt), rr(tt);
  vector<long long> ans(tt);
  for (int qq = 0; qq < tt; ++qq) {
    cin >> ll[qq] >> rr[qq];
    --ll[qq];
    --rr[qq];
  }
  {
    vector<vector<event>> events(m);
    for (int i = 0; i < n; ++i) {
      int x = i;
      while (~x) {
        int h = ~pr[top[x]] ? len[pr[top[x]]] : 0;
        events[top[x]].emplace_back(0, i + h, len[x] - h, -1);
        x = pr[top[x]];
      }
    }
    for (int qq = 0; qq < tt; ++qq) {
      int x = ll[qq];
      for (int i = lg - 1; ~i; --i) {
        if (~anc[i][x] && len[anc[i][x]] >= rr[qq] - ll[qq] + 1) {
          x = anc[i][x];
        }
      }
      bool first = true;
      while (~x) {
        int h = ~pr[top[x]] ? len[pr[top[x]]] : 0;
        events[top[x]].emplace_back(1, rr[qq] + 1, (first ? rr[qq] - ll[qq] + 1 : len[x]) - h, qq);
        x = pr[top[x]];
        first = false;
      }
    }
    auto solve = [&](vector<event> events) {
      sort(events.begin(), events.end());
      {
        vector<int> disc;
        for (auto p : events) {
          if (p.type) {
            disc.push_back(p.u);
          } else {
            disc.push_back(p.u);
            disc.push_back(p.u + p.v);
          }
        }
        sort(disc.begin(), disc.end());
        disc.erase(unique(disc.begin(), disc.end()), disc.end());
        fenwick<pair<int, long long>> fenw(disc.size());
        for (auto p : events) {
          int foo = lower_bound(disc.begin(), disc.end(), p.u) - disc.begin();
          if (p.type) {
            pair<int, long long> w = fenw.query(foo);
            ans[p.id] += (long long) w.first * p.u + w.second;
          } else {
            int bar = lower_bound(disc.begin(), disc.end(), p.u + p.v) - disc.begin();
            fenw.modify(foo, make_pair(1, -p.u));
            fenw.modify(bar, make_pair(-1, p.u + p.v));
          }
        }
      }
      reverse(events.begin(), events.end());
      {
        vector<int> disc;
        for (auto p : events) {
          if (p.type) {
            disc.push_back(p.u);
            if (p.u > p.v) {
              disc.push_back(p.u - p.v);
            }
          } else {
            disc.push_back(p.u);
          }
        }
        sort(disc.begin(), disc.end());
        disc.erase(unique(disc.begin(), disc.end()), disc.end());
        fenwick<pair<int, long long>> fenw(disc.size());
        for (auto p : events) {
          int foo = lower_bound(disc.begin(), disc.end(), p.u) - disc.begin();
          if (p.type) {
            if (p.u > p.v) {
              int bar = lower_bound(disc.begin(), disc.end(), p.u - p.v) - disc.begin();
              pair<int, long long> wfoo = fenw.query(foo), wbar = fenw.query(bar);
              ans[p.id] += (long long) (wfoo.first - wbar.first) * p.u + (wfoo.second - wbar.second) + (long long) wbar.first * p.v;
            } else {
              pair<int, long long> w = fenw.query(foo);
              ans[p.id] += (long long) w.first * p.u + w.second;
            }
          } else {
            fenw.modify(foo, make_pair(1, -p.u));
          }
        }
      }
    };
    for (int i = 0; i < m; ++i) {
      if (!events[i].empty()) {
        solve(events[i]);
      }
    }
  }
  {
    vector<vector<event>> events(m);
    for (int i = 0; i < n; ++i) {
      int x = i;
      while (~x) {
        int h = ~pr[top[x]] ? len[pr[top[x]]] : 0;
        events[top[x]].emplace_back(0, i, len[x] - h, -1);
        x = pr[top[x]];
      }
    }
    for (int qq = 0; qq < tt; ++qq) {
      int x = ll[qq];
      for (int i = lg - 1; ~i; --i) {
        if (~anc[i][x] && len[anc[i][x]] >= rr[qq] - ll[qq] + 1) {
          x = anc[i][x];
        }
      }
      bool first = true;
      while (~x) {
        int h = ~pr[top[x]] ? len[pr[top[x]]] : 0;
        events[top[x]].emplace_back(1, ll[qq] - 1, (first ? rr[qq] - ll[qq] + 1 : len[x]) - h, qq);
        x = pr[top[x]];
        first = false;
      }
    }
    auto solve = [&](vector<event> events) {
      sort(events.begin(), events.end());
      {
        vector<int> disc;
        for (auto p : events) {
          disc.push_back(p.u);
        }
        sort(disc.begin(), disc.end());
        disc.erase(unique(disc.begin(), disc.end()), disc.end());
        fenwick<long long> fenw(disc.size());
        for (auto p : events) {
          int foo = lower_bound(disc.begin(), disc.end(), p.u) - disc.begin();
          if (p.type) {
            ans[p.id] -= fenw.query(foo);
          } else {
            fenw.modify(foo, p.v);
          }
        }
      }
      reverse(events.begin(), events.end());
      {
        vector<int> disc;
        for (auto p : events) {
          disc.push_back(p.u);
        }
        sort(disc.begin(), disc.end());
        disc.erase(unique(disc.begin(), disc.end()), disc.end());
        fenwick<long long> fenw(disc.size());
        for (auto p : events) {
          int foo = lower_bound(disc.begin(), disc.end(), p.u) - disc.begin();
          if (p.type) {
            ans[p.id] -= (long long) p.v * fenw.query(foo);
          } else {
            fenw.modify(foo, 1);
          }
        }
      }
    };
    for (int i = 0; i < m; ++i) {
      if (!events[i].empty()) {
        solve(events[i]);
      }
    }
  }
  for (int qq = 0; qq < tt; ++qq) {
    cout << ans[qq] << "\n";
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

long long sum[N];

struct node {
  int v;

  node(int v) : v(v) {
  }

  bool operator<(const node& o) const {
    return make_pair(sum[v], v) < make_pair(sum[o.v], o.v);
  }
};

struct child {
  set<node> st;

  vector<long long> get() {
    if (st.empty()) {
      return {};
    } else if ((int) st.size() == 1) {
      return {sum[st.begin()->v]};
    } else {
      return {sum[st.begin()->v], sum[st.rbegin()->v]};
    }
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<long long> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    ++d[p[i]];
  }
  auto other = [&](int v) {
    return t[v] / (d[v] + 2);
  };
  auto self = [&](int v) {
    return t[v] - (d[v] + 1) * other(v);
  };
  vector<child> ch(n);
  for (int i = 0; i < n; ++i) {
    ch[p[i]].st.insert(i);
  }
  for (int i = 0; i < n; ++i) {
    ch[p[i]].st.erase(i);
    sum[i] = self(i);
    for (node j : ch[i].st) {
      sum[i] += other(j.v);
    }
    ch[p[i]].st.insert(i);
  }
  multiset<long long> global;
  for (int i = 0; i < n; ++i) {
    vector<long long> ws = ch[i].get();
    for (long long w : ws) {
      global.insert(w + other(i));
    }
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int v, u;
      cin >> v >> u;
      --v; --u;
      set<int> foo = {v, p[v], p[p[v]], u, p[u]};
      set<int> bar = {v, p[v], p[p[v]], p[p[p[v]]], u, p[u], p[p[u]]};
      for (int i : bar) {
        vector<long long> ws = ch[i].get();
        for (long long w : ws) {
          global.erase(global.find(w + other(i)));
        }
      }
      for (int i : foo) {
        ch[p[i]].st.erase(i);
      }
      for (int i : foo) {
        sum[i] -= self(i);
        for (int j : foo) {
          if (p[j] == i) {
            sum[i] -= other(j);
          }
        }
      }
      --d[p[v]];
      p[v] = u;
      ++d[p[v]];
      for (int i : foo) {
        sum[i] += self(i);
        for (int j : foo) {
          if (p[j] == i) {
            sum[i] += other(j);
          }
        }
      }
      for (int i : foo) {
        ch[p[i]].st.insert(i);
      }
      for (int i : bar) {
        vector<long long> ws = ch[i].get();
        for (long long w : ws) {
          global.insert(w + other(i));
        }
      }
    } else if (type == 2) {
      int v;
      cin >> v;
      --v;
      cout << sum[v] + other(p[v]) << "\n";
    } else {
      cout << *global.begin() << " " << *global.rbegin() << "\n";
    }
  }
  return 0;
}
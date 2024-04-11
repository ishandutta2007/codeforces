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

class segtree {
  vector<pair<int, int>> tree;
  int n;

  void modify(int x, int l, int r, int ll, int rr, int v) {
    if (ll <= l && r <= rr) {
      tree[x].first = tree[x].second = v;
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      if (ll <= y) {
        modify(x + 1, l, y, ll, rr, v);
      }
      if (rr > y) {
        modify(z, y + 1, r, ll, rr, v);
      }
      tree[x].first = min(tree[x].second, min(tree[x + 1].first, tree[z].first));
    }
  }

  int query(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x].first;
    } else {
      int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
      int ans = tree[x].second;
      if (ll <= y) {
        ans = min(ans, query(x + 1, l, y, ll, rr));
      }
      if (rr > y) {
        ans = min(ans, query(z, y + 1, r, ll, rr));
      }
      return ans;
    }
  }

 public:
  segtree(int n): n(n) {
    tree.assign(n * 2 - 1, make_pair(n, n));
  }

  void modify(int ll, int rr, int v) {
    modify(0, 0, n - 1, ll, rr, v);
  }

  int query(int ll, int rr) {
    return query(0, 0, n - 1, ll, rr);
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  cin >> n >> s;
  if (n == 1) {
    cout << 1 << "\n";
    return 0;
  }
  vector<int> sa = suffix_array(s, n, 256);
  vector<int> lcp = build_lcp(s, n, sa);
  vector<int> pos_in_sa(n);
  for (int i = 0; i < n; ++i) {
    pos_in_sa[sa[i]] = i;
  }
  int logn = 0;
  while (1 << logn < n) {
    ++logn;
  }
  vector<vector<int>> rmq(logn, vector<int>(n - 1));
  rmq[0] = lcp;
  for (int i = 1; i < logn; ++i) {
    for (int j = 0; j + (1 << i) < n; ++j) {
      rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
    }
  }
  segtree last(n);
  segtree parent(n);
  vector<int> ptr(n + 1);
  vector<int> depth(n);
  vector<int> len(n);
  vector<int> left(n);
  vector<int> right(n);
  for (int i = n - 1; ~i; --i) {
    int p = parent.query(pos_in_sa[i], pos_in_sa[i]);
    if (p == n) {
      depth[i] = 1;
      len[i] = 1;
    } else {
      depth[i] = depth[p] + 1;
      len[i] = last.query(left[p], right[p] - 1) + len[p] - i;
    }
    int l = pos_in_sa[i], r = pos_in_sa[i];
    for (int j = logn - 1; ~j; --j) {
      if (l - (1 << j) >= 0 && rmq[j][l - (1 << j)] >= len[i]) {
        l -= 1 << j;
      }
      if (r + (1 << j) < n && rmq[j][r] >= len[i]) {
        r += 1 << j;
      }
    }
    left[i] = ptr[p];
    right[i] = left[i] + (r - l + 1);
    ptr[i] = left[i] + 1;
    ptr[p] = right[i];
    last.modify(left[i], left[i], i);
    parent.modify(l, r, i);
  }
  cout << *max_element(depth.begin(), depth.end()) << "\n";
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int M = 10000005;

struct node_t {
  int l, r, value;
} tree[M];

int n, m, start, total, a[N], b[N], fenw[N], last[N], root[N], times[N];
long long sum[N];

void modify(int x, int value) {
  for (; x <= n; x += x & -x) {
    fenw[x] += value;
  }
}

int query(int x) {
  int result = 0;
  for (; x; x -= x & -x) {
    result += fenw[x];
  }
  return result;
}

int erase(int x) {
  int l = 1, r = n, p = n + 1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (query(mid) > x) {
      p = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  modify(p, -1);
  return p - 1;
}

pair<long long, int> check(int p, int k, int x) {
  x += times[p] - k;
  int q = upper_bound(times, times + n, x) - times;
  return make_pair((long long)x * q - sum[q], q);
}

int query_where(int x, int k) {
  int l = 1, r = n - 1, result = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid, k, 0).first <= x) {
      result = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return result;
}

int query_exact(int x, int k, int p) {
  int l = 1, r = times[p + 1] - times[p], result = 0;
  if (p == n - 1) {
    r = x / n + k + 1;
  }
  while (l <= r) {
    int mid = l + (r - l >> 1);
    if (check(p, k, mid).first <= x) {
      result = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return result;
}

void modify(int &x, int y, int l, int r, int p) {
  tree[x = ++total] = tree[y];
  ++tree[x].value;
  if (l != r) {
    int mid = l + r >> 1;
    if (p <= mid) {
      modify(tree[x].l, tree[y].l, l, mid, p);
    } else {
      modify(tree[x].r, tree[y].r, mid + 1, r, p);
    }
  }
}

int query_kth(int x, int l, int r, int k) {
  if (l == r) {
    return l;
  } else {
    int mid = l + r >> 1;
    if (k >= tree[tree[x].l].value) {
      return query_kth(tree[x].r, mid + 1, r, k - tree[tree[x].l].value);
    } else {
      return query_kth(tree[x].l, l, mid, k);
    }
  }
}

int query_sum(int x, int l, int r, int p) {
  if (r == p) {
    return tree[x].value;
  }
  int mid = l + r >> 1;
  if (p <= mid) {
    return query_sum(tree[x].l, l, mid, p);
  } else {
    return tree[tree[x].l].value + query_sum(tree[x].r, mid + 1, r, p);
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  start = a[0];
  for (int i = 0; i < n; ++i) {
    a[i] -= start;
  }
  for (int i = 1; i < n; ++i) {
    times[i] = times[i - 1] + (a[i] - last[i - 1]) / i;
    last[i] = last[i - 1] + i * (times[i] - times[i - 1]);
    sum[i + 1] = sum[i] + times[i];
  }
  for (int i = 1; i <= n; ++i) {
    modify(i, 1);
  }
  for (int i = n - 1; ~i; --i) {
    b[i] = erase(a[i] - last[i]);
  }
  for (int i = 0; i < n; ++i) {
    modify(root[i + 1], root[i], 0, n - 1, b[i]);
  }
  while (m--) {
    int x, k;
    scanf("%d %d", &x, &k);
    if (x < start) {
      printf("%d\n", x);
    } else {
      x -= start;
      int p = query_where(x, k);
      int q = query_exact(x, k, p);
      pair<long long, int> result = check(p, k, q);
      int remain = x - result.first, prefix = result.second;
      int rank = query_kth(root[prefix], 0, n - 1, remain);
      int numbers = 0;
      if (rank) {
        numbers = query_sum(root[p + 1], 0, n - 1, rank - 1);
      }
      printf("%lld\n", start + last[p] + (long long)q * (p + 1) + numbers);
    }
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 120005;

struct node_t {
  int tag, time, value, number;
  ll answer;
} tree[N << 2];

int n, m, top_max, top_min, a[N], stack_max[N], stack_min[N];
vector<pair<int, int>> queries[N];
ll answer[N];

void add_value(int x, int value) {
  tree[x].value += value;
  tree[x].tag += value;
}

void add_time(int x, int value) {
  tree[x].time += value;
  tree[x].answer += (ll)value * tree[x].number;
}

void push_up(int x) {
  tree[x].value = min(tree[x << 1].value, tree[x << 1 | 1].value);
  tree[x].answer = tree[x << 1].answer + tree[x << 1 | 1].answer;
  tree[x].number = 0;
  if (tree[x].value == tree[x << 1].value) {
    tree[x].number += tree[x << 1].number;
  }
  if (tree[x].value == tree[x << 1 | 1].value) {
    tree[x].number += tree[x << 1 | 1].number;
  }
}

void push_down(int x) {
  if (tree[x].tag) {
    add_value(x << 1, tree[x].tag);
    add_value(x << 1 | 1, tree[x].tag);
    tree[x].tag = 0;
  }
  if (tree[x].time) {
    if (tree[x].value == tree[x << 1].value) {
      add_time(x << 1, tree[x].time);
    }
    if (tree[x].value == tree[x << 1 | 1].value) {
      add_time(x << 1 | 1, tree[x].time);
    }
    tree[x].time = 0;
  }
}

void build(int x, int l, int r) {
  tree[x].value = l;
  tree[x].number = 1;
  if (l == r) {
    return;
  }
  int mid = l + r >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
}

void modify(int x, int l, int r, int ql, int qr, int value) {
  if (l == ql && r == qr) {
    add_value(x, value);
    return;
  }
  int mid = l + r >> 1;
  push_down(x);
  if (qr <= mid) {
    modify(x << 1, l, mid, ql, qr, value);
  } else if (ql > mid) {
    modify(x << 1 | 1, mid + 1, r, ql, qr, value);
  } else {
    modify(x << 1, l, mid, ql, mid, value);
    modify(x << 1 | 1, mid + 1, r, mid + 1, qr, value);
  }
  push_up(x);
}

ll query(int x, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) {
    return tree[x].answer;
  }
  int mid = l + r >> 1;
  push_down(x);
  if (qr <= mid) {
    return query(x << 1, l, mid, ql, qr);
  } else if (ql > mid) {
    return query(x << 1 | 1, mid + 1, r, ql, qr);
  } else {
    return query(x << 1, l, mid, ql, mid) + query(x << 1 | 1, mid + 1, r, mid + 1, qr);
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    queries[r].push_back(make_pair(l, i));
  }
  build(1, 1, n);
  for (int i = 1; i <= n; ++i) {
    add_value(1, -1);
    while (top_max && a[stack_max[top_max]] < a[i]) {
      modify(1, 1, n, stack_max[top_max - 1] + 1, stack_max[top_max], a[i] - a[stack_max[top_max]]);
      --top_max;
    }
    stack_max[++top_max] = i;
    while (top_min && a[stack_min[top_min]] > a[i]) {
      modify(1, 1, n, stack_min[top_min - 1] + 1, stack_min[top_min], a[stack_min[top_min]] - a[i]);
      --top_min;
    }
    stack_min[++top_min] = i;
    add_time(1, 1);
    for (auto q : queries[i]) {
      answer[q.second] = query(1, 1, n, q.first, i);
    }
  }
  for (int i = 1; i <= m; ++i) {
    printf("%lld\n", answer[i]);
  }
  return 0;
}
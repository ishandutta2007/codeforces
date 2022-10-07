#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int MAXN = 1 << 19;
const int SIZE = 1 << 20;

int N, Q;

vector<int> conn[MAXN];
int lazy[SIZE];

void down(int cur) {
  if (lazy[cur]) {
    lazy[cur * 2] = lazy[cur];
    lazy[cur * 2 + 1] = lazy[cur];
    lazy[cur] = 0;
  }
}

void set(int left, int right, int num, int cur = 1, int l = 0, int r = MAXN) {
  if (left >= r || l >= right) return;
  if (left <= l && r <= right) {
    lazy[cur] = num;
  } else {
    down(cur);
    int mid = (l + r) / 2;
    set(left, right, num, cur * 2, l, mid);
    set(left, right, num, cur * 2 + 1, mid, r);
  }
}

int query(int idx, int cur = 1, int l = 0, int r = MAXN) {
  if (lazy[cur]) return lazy[cur];
  if (l + 1 == r) return 0;
  int mid = (l + r) / 2;
  if (idx < mid) {
    return query(idx, cur * 2, l, mid);
  } else {
    return query(idx, cur * 2 + 1, mid, r);
  }
}

int SEG2[SIZE];

void set2(int idx, int val, int cur = 1, int l = 0, int r = MAXN) {
  if (l + 1 == r) {
    SEG2[cur] = val;
  } else {
    int mid = (l + r) / 2;
    if (idx < mid) set2(idx, val, cur * 2, l, mid);
    else set2(idx, val, cur * 2 + 1, mid, r);
    SEG2[cur] = max(SEG2[cur * 2], SEG2[cur * 2 + 1]);
  }
}

int query2(int left, int right, int cur = 1, int l = 0, int r = MAXN) {
  int mid = (l + r) / 2;
  if (left >= r || l >= right) return 0;
  else if (left <= l && r <= right) return SEG2[cur];
  else return max(query2(left, right, cur * 2, l, mid), 
      query2(left, right, cur * 2 + 1, mid, r));
}


int assign[MAXN];
int par[MAXN];
int up[MAXN];
int deg[MAXN];

void dfs1(int cur, int prv = 0) {
  deg[cur] = 1;
  par[cur] = prv;
  repi(i, conn[cur]) {
    if (*i != prv) {
      dfs1(*i, cur);
      deg[cur] += deg[*i];
    }
  }
}

int cnt = 0;

void dfs2(int cur, int prv = 0) {
  if (!up[cur]) up[cur] = cur;
  assign[cur] = ++cnt;

  //printf("At %d, assign = %d, up = %d\n", cur, assign[cur], up[cur]);
  int mx = -1;
  repi(i, conn[cur]) {
    if (*i != prv) {
      if (mx == -1 || deg[*i] > deg[mx]) {
        mx = *i;
      }
    }
  }

  if (mx != -1) {
    up[mx] = up[cur];
    dfs2(mx, cur);
    repi(i, conn[cur]) {
      if (*i != prv && *i != mx) {
        dfs2(*i, cur);
      }
    }
  }
}

int lastfill[MAXN];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    conn[a].push_back(b);
    conn[b].push_back(a);
  }

  dfs1(1);
  dfs2(1);

  scanf("%d", &Q);
  for(int i = 1; i <= Q; ++i) {
    int qtype, v;
    scanf("%d %d", &qtype, &v);
    if (qtype == 1) {
      set2(assign[v], i);
    } else if (qtype == 2) {
      int cur = v;
      while (cur) {
        //printf("assigning %d ... %d\n", cur, up[cur]);
        set(assign[up[cur]], assign[cur] + 1, i);
        cur = par[up[cur]];
      }
    } else if (qtype == 3) {
      int lf = 0;
      int cur = v;
      while (cur) {
        int f = query2(assign[up[cur]], assign[cur] + 1);
        if (f > lf) lf = f;
        cur = par[up[cur]];
      }
      int le = query(assign[v]);
      //printf("le = %d, lf = %d\n", le, lf);

      if (lf > le) printf("1\n");
      else printf("0\n");
    }
  }
  return 0;
}
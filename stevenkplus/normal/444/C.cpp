#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXN = 1 << 17;
const int SIZE = 1 << 18;

typedef long long ll;

int N, M;

ll lazyadd[SIZE];
int lazyrr[SIZE];
int lazyll[SIZE];
int lazycol[SIZE];
ll SEG[SIZE];

void down(int cur, int l, int r) {
  if (lazyrr[cur]) {
    lazyrr[cur*2] = lazyrr[cur];
    lazyrr[cur*2+1] = lazyrr[cur];
    lazyrr[cur] = 0;
  }

  if (lazyll[cur]) {
    lazyll[cur*2] = lazyll[cur];
    lazyll[cur*2+1] = lazyll[cur];
    lazyll[cur] = 0;
  }

  if (lazycol[cur]) {
    lazycol[cur*2] = lazycol[cur];
    lazycol[cur*2+1] = lazycol[cur];
    lazycol[cur] = 0;
  }

  if (lazyadd[cur]) {
    int mid = (l + r) / 2;
    int wdth = mid - l;
    SEG[cur*2] += lazyadd[cur] * wdth;
    SEG[cur*2+1] += lazyadd[cur] * wdth;
    lazyadd[cur*2] += lazyadd[cur];
    lazyadd[cur*2+1] += lazyadd[cur];
    lazyadd[cur] = 0;
  }
}

void inc(int lft, int rgt, ll add, int col, int ll, int rr, int cur = 1, int l = 0, int r = MAXN) {
  if (lft <= l && r <= rgt) {
    SEG[cur] += add * (r - l);
    lazyadd[cur] += add;
    lazyrr[cur] = rr;
    lazyll[cur] = ll;
    lazycol[cur] = col;
  } else if (lft >= r || l >= rgt) {
  } else {
    down(cur, l, r);
    int mid = (l + r) / 2;
    inc(lft, rgt, add, col, ll, rr, cur*2, l, mid);
    inc(lft, rgt, add, col, ll, rr, cur*2+1, mid, r);
    SEG[cur] = SEG[cur*2] + SEG[cur*2 + 1];
  }


}

ll asksum(int lft, int rgt, int cur = 1, int l = 0, int r = MAXN) {
  if (lft <= l && r <= rgt) {
    return SEG[cur];
  } else if (lft >= r || l >= rgt) {
    return 0;
  } else {
    down(cur, l, r);
    int mid = (l + r) / 2;
    ll ret = asksum(lft, rgt, cur*2, l, mid) + asksum(lft, rgt, cur*2+1, mid, r);
    return ret;
  }
}

int askrr(int pos, int cur = 1, int l = 0, int r = MAXN) {
  while (l + 1 < r) {
    down(cur, l, r);
    int mid = (l + r) / 2;
    if (pos < mid) {
      cur = cur * 2;
      r = mid;
    } else {
      cur = cur * 2 + 1;
      l = mid;
    }
  }

  return lazyrr[cur];
}

int askll(int pos, int cur = 1, int l = 0, int r = MAXN) {
  while (l + 1 < r) {
    down(cur, l, r);
    int mid = (l + r) / 2;
    if (pos < mid) {
      cur = cur * 2;
      r = mid;
    } else {
      cur = cur * 2 + 1;
      l = mid;
    }
  }

  return lazyll[cur];
}


int askcol(int pos, int cur = 1, int l = 0, int r = MAXN) {
  while (l + 1 < r) {
    down(cur, l, r);
    int mid = (l + r) / 2;
    if (pos < mid) {
      cur = cur * 2;
      r = mid;
    } else {
      cur = cur * 2 + 1;
      l = mid;
    }
  }

  return lazycol[cur];
}


int main() {
  scanf("%d %d\n", &N, &M);
  for(int i = 1; i <= N; ++i) {
    lazyrr[i + MAXN] = i + 1;
    lazyll[i + MAXN] = i;
    lazycol[i + MAXN] = i;
  }

  for(int q = 0; q < M; ++q) {
    int qtype;
    scanf("%d", &qtype);
    if (qtype == 1) {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      ++r;
//      printf("set %d %d %d\n", l, r, x);
      int cur = l;
      while (cur < r) {
        int a = askll(cur);
        int b = askrr(cur);

        int nxt = b;
        if (nxt > r) nxt = r;

        int curcol = askcol(cur);
        inc(a, cur, 0, curcol, a, cur);
        inc(nxt, b, 0, curcol, nxt, b);
        int add = abs(x - curcol);
        //printf("adding %d to (%d %d)\n", add, cur, nxt);
        inc(cur, nxt, add, x, l, r);
        cur = nxt;
      }

    } else {
      int l, r;
      scanf("%d %d", &l, &r);
//      printf("ask %d %d\n", l, r);
      ll ans = asksum(l, r + 1);
      cout << ans << "\n";
    }
  }
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
const int MAXN = 1 << 20;
const int SIZE = MAXN << 1;
const int inf = 1 << 30;

int A, B;
int N;

int ar[MAXN];
int fact[MAXN];

int SEG[SIZE];

int query(int left, int right, int cur = 1, int l = 0, int r = MAXN) {
  if (left <= l && r <= right) return SEG[cur];
  else if (left >= r || l >= right) return inf;
  else {
    int mid = (l + r) / 2;
    int a = query(left, right, cur * 2, l, mid);
    int b = query(left, right, cur * 2 + 1, mid, r);
    if (a < b) return a;
    else return b;
  }
}

void set(int idx, int val, int cur = 1, int l = 0, int r = MAXN) {
  if (val < SEG[cur]) SEG[cur] = val;
  if (l + 1 < r) {
    int mid = (l + r) / 2;
    if (mid > idx) {
      set(idx, val, cur * 2, l, mid);
    } else {
      set(idx, val, cur * 2 + 1, mid, r);
    }
  }
}
/*
int query(int left, int right) {
  int ans = inf;
  for(int i = left; i < right; ++i) {
    if (dp[i] < ans) ans = dp[i];
  }
  return ans;
}
*/
int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }
  scanf("%d %d", &B, &A);

  sort(ar, ar + N);
  for(int i = 0; i < MAXN; ++i) {
    fact[i] = 2;
  }

  for(int i = 0; i < SIZE; ++i) {
    SEG[i] = inf;
  }

  for(int i = 0; i < N; ++i) {
    if (i == 0 || ar[i] != ar[i - 1]) {
      for(int x = A / ar[i] * ar[i]; x <= B; x += ar[i]) {
        if (x >= A) {
          if (ar[i] > fact[x - A]) {
            fact[x - A] = ar[i];
          }
        }
      }
    }
  }

  int ans = 0;
  set(B - A, 0);
  for(int x = B - 1; x >= A; --x) {
    int hi = x + fact[x - A] - 1;
    if (hi > B) hi = B;
    int cur = query(x + 1 - A, hi + 1 - A) + 1;
    set(x - A, cur);
    ans = cur;
  }

  cout << ans << endl;
  return 0;
}
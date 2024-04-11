#include <cstdio>
const int MAXN = 100100;
int ar[MAXN];
int state[MAXN];
int state2[MAXN];

int w, l;
bool can(int init) {
  for(int i = 0; i < MAXN; ++i) {
    state[i] = 0;
    state2[i] = ar[i];
  }
  state[0] = init;
  state[w] = 1;
  int lo = 0;
  for(int hi = 1; hi <= w; ++hi) {
    while (state[lo] == 0) {
      ++lo;
    }
    if (lo + l < hi) {
      return false;
    }
    while (lo < hi) {
      int v = state[lo];
      if (state2[hi] < v) v = state2[hi];
      state[lo] -= v;
      state[hi] += v;
      state2[hi] -= v;
      if (state[lo] == 0) ++lo;
      else break;
    }
  }
  return true;
}

int main() {
  scanf("%d %d", &w, &l);
  for(int i = 1; i < w; ++i) {
    scanf("%d", ar + i);
  }

  int lo = 0;
  int hi = 1E9;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (can(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  printf("%d\n", lo);
}
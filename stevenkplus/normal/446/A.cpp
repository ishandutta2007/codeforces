#include <cstdio>

const int MAXN = 100100;

bool worry[MAXN];
int nxt[MAXN];
int ar[MAXN];

bool good(int l, int r) {
  int a = -3, b = -1;
  bool used = false;
  for(int i = l; i < r; i = nxt[i]) {
    int c = ar[i];
    if (c <= b) {
      if (used) return false;
      used = true;
      if (c - 1 > a) {
        b = c - 1;
      } else {
        c = b + 1;
      }
    }

    a = b;
    b = c;
  }

  return true;
}

int N;

int main() {
  scanf("%d", &N);

  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  for(int i = 0; i + 1 < N; ++i) {
    if (ar[i + 1] <= ar[i]) {
      worry[i - 1] = worry[i] = worry[i + 1] = worry[i + 2] = 1;
    }
  }

  int rt = N;
  for(int i = N - 1; i >= 0; --i) {
    nxt[i] = rt;
    if (worry[i]) rt = i;
  }

  int l = 0, r = 1;
  int ans = 1;
  while (r <= N) {
    if (good(l, r)) {
      if (r - l > ans) {
        ans = r - l;
      }
      ++r;
    } else {
      ++l;
    }
  }

  printf("%d\n", ans);
}
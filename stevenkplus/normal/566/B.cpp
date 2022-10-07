#include <cstdio>

const int MAXN = 150100;

int counts[MAXN];
int A[MAXN], B[MAXN], C[MAXN];

int order[MAXN];
bool done[MAXN];

inline bool ok(int a, int b, int c) {
  if (a == b) {
    return counts[c] + 1 <= 9;
  } else if (a == c) {
    return counts[b] + 1 <= 9;
  } else if (b == c) {
    return counts[c] + 2 <= 9;
  } else {
    return counts[b] + 1 <= 9 && counts[c] + 1 <= 9;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  n *= 4;
  for(int i = 0; i < n; ++i) {
    scanf("%d %d %d", A + i, B + i, C + i);
    ++counts[A[i]];
  }

  int cur = 0;
  while (cur < n) {
    bool find = false;
    for(int i = 0; i < n; ++i) {
      if (!done[i]) {
        if (ok(A[i], B[i], C[i])) {
          done[i] = true;
          --counts[A[i]];
          ++counts[B[i]];
          ++counts[C[i]];
          order[cur] = i;
          ++cur;
          find = true;
        }
      }
    }

    if (!find) {
      break;
    }
  }

  if (cur == n) {
    printf("YES\n");
    for(int i = 0; i < n; ++i) {
      printf("%d ", order[i] + 1);
    }
    printf("\n");
  } else {
    printf("NO\n");
  }

}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 100100;

char _A[MAXN];
char _B[MAXN];
int C[MAXN];

void simp(char *s, int len) {
  int i = len - 2;
  while (i >= 0) {
    if (s[i] == '1' && s[i + 1] == '1') {
      s[i] = s[i + 1] = '0';
      s[i + 2] = '1';
      i = i + 2;
    } else {
      --i;
    }
  }
}

int main() {
  char *A = _A, *B = _B;
  scanf("%s %s", A, B);
  int N = strlen(A), M = strlen(B);
  reverse(A, A + N);
  reverse(B, B + M);
  simp(A, N);
  simp(B, M);

  N = strlen(A);
  M = strlen(B);
  while (N > 0 && A[N - 1] == '0') --N;
  while (M > 0 && B[M - 1] == '0') --M;
  A[N] = 0;
  B[M] = 0;

  int ans = 0;
  if (N == M) {
    for(int i = 0; i < N; ++i) {
      if (A[i] > B[i]) ans = 1;
      else if (A[i] < B[i]) ans = -1;
    }
  } else {
    if (N > M) ans = 1;
    else ans = -1;
  }

  if (ans == 1) printf(">\n");
  else if (ans == 0) printf("=\n");
  else printf("<\n");
  return 0;
}
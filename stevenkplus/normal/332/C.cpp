#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int N, P, K;
int A[MAXN];
int B[MAXN];

bool cmp1(int a, int b) {
  if (B[a] == B[b]) {
    if (A[a] == A[b]) return a < b;
    return A[a] < A[b];
  }
  return B[a] > B[b];
}

bool cmp2(int a, int b) {
  if (A[a] == A[b]) return B[a] > B[b];
  return A[a] > A[b];
}


int ar[MAXN];
int rnk[MAXN];
int ans[MAXN];

int main() {
  scanf("%d %d %d", &N, &P, &K);
  for(int i = 0; i < N; ++i) {
    scanf("%d %d", A + i, B + i);
    ar[i] = i;
  }

  sort(ar, ar + N, cmp1);
  for(int i = 0; i < N; ++i) {
    rnk[ar[i]] = i;
  }
  
  sort(ar, ar + N, cmp2);
  int p = 0;
  int last = 0;
  for(int i = 0; p < K; ++i) {
    int cur = ar[i];
    if (N - rnk[cur] - 1 >= P - K) {
//      printf("Taking %d: %d\n", i, cur);
      ans[p] = cur;
      ++p;
      if (rnk[cur] > last) last = rnk[cur];
    }
  }

  sort(ar, ar + N, cmp1);
  for(int i = last + 1; p < P; ++i) {
    int cur = ar[i];
    ans[p] = cur;
    ++p;
  }

  for(int i = 0; i < P; ++i) {
    if (i) printf(" ");
    printf("%d", ans[i] + 1);
  }
  printf("\n");
  return 0;
}
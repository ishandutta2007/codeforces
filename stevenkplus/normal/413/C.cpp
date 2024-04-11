#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 111;

int A[MAXN], B[MAXN], ar[MAXN];
bool good[MAXN];
int N, M;

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }
  for(int i = 0; i < M; ++i) {
    int x;
    scanf("%d", &x);
    --x;
    good[x] = true;
  }
  int a = 0, b = 0;
  for(int i = 0; i < N; ++i) {
    if (good[i]) {
      A[a] = ar[i];
      ++a;
    } else {
      B[b] = ar[i];
      ++b;
    }
  }

  sort(A, A + a);
  //sort(B, B + b);
  ll sc = 0;
  for(int i = 0; i < b; ++i) {
    sc += B[i];
  }

  for(int i = a - 1; i >= 0; --i) {
    if (A[i] >= sc) sc += A[i];
    else sc += sc;
  }

  cout << sc << "\n";
  return 0;
}
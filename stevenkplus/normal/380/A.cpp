#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 100100;

typedef long long ll;

int ar[MAXN];
ll lens[MAXN];
int A[MAXN];
int B[MAXN];
int M, Q;

int main() {
  scanf("%d", &M);
  int pos = 0;
  for(int i = 1; i <= M; ++i) {
    int qtype;
    scanf("%d", &qtype);
    if (qtype == 1) {
      int x;
      scanf("%d", &x);
      A[i] = x;
      lens[i] = lens[i - 1] + 1;
      if (pos < MAXN) {
        ar[pos] = x;
        ++pos;
      }
    } else if (qtype == 2) {
      int l, c;
      scanf("%d %d", &l, &c);
      A[i] = l;
      B[i] = c;
      lens[i] = lens[i - 1] + l * c;
      int x = 0;
      while (pos < MAXN && c) {
        ar[pos] = ar[x];
        ++pos;
        ++x;
        if (x == l) {
          x = 0;
          --c;
        }
      }
    }
  }

  scanf("%d", &Q);
  int cur = 0;
  for(int i = 0; i < Q; ++i) {
    ll x;
    cin >> x;
    --x;
    while (lens[cur] <= x) ++cur;
    if (B[cur] == 0) printf("%d ", A[cur]);
    else {
      int p = x - lens[cur - 1];
      printf("%d ", ar[p % A[cur]]);
    }
  }
  printf("\n");

  return 0;
}
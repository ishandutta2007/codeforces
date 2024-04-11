#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 2001000;

typedef long long ll;

ll c2(ll n) {
  return n * (n - 1) / 2;
}

int n, N, M;

int ar[MAXN];
int tmp[MAXN];
ll ans[22];
ll same[22];

void prec() {
  for(int i = 1; i <= n; ++i) {
    int len = 1 << i;
    int mid = len / 2;
    ll &inv = ans[i];
    ll &sme = same[i];
    for(int j = 0; j < N; j += len) {
      int *A = ar + j;
      int *B = ar + j + mid;
      int a = 0, b = 0;
      int c = 0;
      while (a < mid && b < mid) {
        if (A[a] < B[b]) {
          tmp[c] = A[a];
          ++c;
          ++a;
          inv += b;
        } else if (A[a] == B[b]) {
          int key = A[a];
          int acnt = 0;
          int bcnt = 0;
          while (a < mid && A[a] == key) {
            tmp[c] = A[a]; ++c;
            ++a;
            ++acnt;
            inv += b;
          }
          while(b < mid && B[b] == key) {
            tmp[c] = B[b]; ++c;
            ++b;
            ++bcnt;
          }
          sme += acnt * ll(bcnt);

        } else {
          tmp[c] = B[b];
          ++c;
          ++b;
        }
      }
      while (a < mid) {
        inv += b;
        tmp[c] = A[a];
        ++c;
        ++a;
      }
      while (b < mid) {
        tmp[c] = B[b];
        ++c;
        ++b;
      }
      for(int k = 0; k < len; ++k) {
        A[k] = tmp[k];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d", &n);
  N = 1 << n;
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  ll cur = 0;
  prec();
  for(int i = 1; i <= n; ++i) {
//    printf("ans[%d] = %l d\n", i, ans[i]);
    cur += ans[i];
  }


  scanf("%d", &M);
  for(int i = 0; i < M; ++i) {
    int q;
    scanf("%d", &q);
    for(int j = 1; j <= q; ++j) {
      int segs = 1 << (n - j);
      cur -= ans[j];
      ans[j] = (1LL << (2 * (j - 1))) * segs - ans[j] - same[j];
      cur += ans[j];
    }
    cout << cur << "\n";
  }
  return 0;
}
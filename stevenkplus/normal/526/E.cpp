#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;


const int MAXN = 2001000;
ll B;

int N, Q;
int A[MAXN];
ll prf[MAXN];

ll tot = 0;
int ask(ll B) {
  if (B >= tot) {
    return 1;
  }

  int bst = 0;
  int mn = N;
  int i = 0, j = 0;
  ll sum = 0;
  while (i < N) {
    if (sum <= B) {
      sum += A[j];
      ++j;
    } else {
      if (j - i < mn) {
        mn = j - i ;
        bst = i;
      }
      sum -= A[i];
      ++i;
    }
  }

  int ans = N;
  for(int i = bst; prf[i] - prf[bst] <= B; i += 1) {
    int cnt = 0;
    int cur = i;
    while (cur < i + N) {
      int lo = cur;
      int dst = 1;
      while (lo + dst < i + N && prf[lo + dst] - prf[lo] <= B) {
        dst *= 2;
      }
      int hi = lo + dst;
      if (i + N < hi) hi = i + N;

      while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (prf[mid] - prf[cur] <= B) {
          lo = mid;
        } else {
          hi = mid - 1;
        }
      }
      cur = lo;
      ++cnt;
    }

//    printf("i = %d, cnt = %d\n", i, cnt);
    if (cnt < ans) {
      ans = cnt;
    }
  }

  return ans;
}

int main() {
  scanf("%d %d", &N, &Q);

  for(int i = 0; i < N; ++i) {
    scanf("%d", A + i);
    A[i + N] = A[i];
    tot += A[i];
  }

  for(int i = 0; i < 2 * N; ++i) {
    prf[i + 1] = prf[i] + A[i];
  }


  for(int q = 0; q < Q; ++q) {
    cin >> B;
    printf("%d\n", ask(B));
  }
}
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 101;

int N;
int ar[MAXN];
int mids[MAXN];

int main() {
  scanf("%d", &N);

  int cnt = 0;
  int A = 0, B = 0;

  for(int i = 0; i < N; ++i) {
    int len;
    scanf("%d", &len);
    for(int j = 0; j < len; ++j) {
      int nxt;
      scanf("%d", &nxt);
      if (j * 2 + 1 < len) {
        A += nxt;
      } else if (j * 2 + 1 == len) {
        mids[cnt] = nxt;
        ++cnt;
      } else {
        B += nxt;
      }
    }
  }

  sort(mids, mids + cnt);
  for(int i = 0; i < cnt; ++i) {
    if (i % 2 == 0) {
      A += mids[cnt - i - 1];
    } else {
      B += mids[cnt - i - 1];
    }
  }

  printf("%d %d\n", A, B);
  return 0;
}
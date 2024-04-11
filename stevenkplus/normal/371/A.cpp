#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

int ar[MAXN];
int N, K;
int tmp[MAXN];

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  int ans = 0;
  for(int i = 0; i < K; ++i) {
    int bst = 0;
    int cur = 0;
    for(int j = i; j < N; j += K) {
      tmp[cur] = ar[j];
      ++cur;
    }
    sort(tmp, tmp + cur);
    int run = 0;
    for(int j = 0; j < cur; ++j) {
      if (j > 0 && tmp[j] != tmp[j-1]) run = 0;
      ++run;
      if (run > bst) bst = run;
    }
    ans += cur - bst;
  }
  printf("%d\n", ans);
  return 0;
}
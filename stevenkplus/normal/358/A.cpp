#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;
const int MAXN = 10100;

int N;

int ar[MAXN];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  bool ans = false;
  for(int a = 0; a + 1 < N; ++a) {
    for(int b = 0; b + 1 < N; ++b) {
      int w = min(ar[a], ar[a + 1]), x = max(ar[a], ar[a + 1]);
      int y = min(ar[b], ar[b + 1]), z = max(ar[b], ar[b + 1]);
      if (w < y && y < x && x < z || y < w && w < z && z < x) {
        ans = true;
      }
    }
  }

  if (ans) printf("yes\n");
  else printf("no\n");
  return 0;
}
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 111;
int N;
int ar[MAXN];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d",ar + i);
  }
  sort(ar, ar + N);

  int ans = 1;
  for(int i = 0; i < N; ++i) {
    int val = (ar[i] + i + 1) / (ar[i] + 1);
    if (val > ans) ans = val;
  }


  printf("%d\n", ans);
  return 0;
}
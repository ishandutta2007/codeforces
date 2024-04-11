#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100100;
typedef pair<int, int> pii;

int N;
pii ar[MAXN];
int ceil(int x) {
  int lo = 0;
  int hi = N - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (ar[mid].first >= x) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

int DP[MAXN];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ar[i] = pii(a, b);
  }
  sort(ar, ar + N);

  int ans = N;
  DP[0] = 0;
  for(int i = 0; i < N; ++i) {
    int pp = ar[i].first - ar[i].second;
    int j = ceil(pp); // ar[j].first >= pp
    DP[i + 1] = DP[j] + i - j;
    int cand = DP[i + 1] + (N - 1 - i);
    if (cand < ans) {
      ans = cand;
    }
  }

  printf("%d\n", ans);
}
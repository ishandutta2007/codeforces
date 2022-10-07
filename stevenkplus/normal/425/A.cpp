#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 222;

int ar[MAXN];

int N, K;

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  int ans = -1000;
  for(int l = 0; l < N; ++l) {
    for(int r = l + 1; r <= N; ++r) {
      priority_queue<int> aq, bq;
      int csum = 0;
      for(int i = l; i < r; ++i) {
        csum += ar[i];
        bq.push(-ar[i]);
      }
      for(int i = 0; i < l; ++i) {
        aq.push(ar[i]);
      }
      for(int i = r; i < N; ++i) {
        aq.push(ar[i]);
      }
      for(int i = 0; i < K && !aq.empty() && !bq.empty(); ++i) {
        int bst = aq.top(); aq.pop();
        int wst = bq.top(); bq.pop();
        if (bst + wst < 0) break;
        csum += bst;
        csum += wst;
      }
      if (csum > ans) ans = csum;
    }
  }

  printf("%d\n", ans);
  return 0;
}
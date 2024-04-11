#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int MAXK = 311;

int N, M, S, E;

int A[MAXN];
int B[MAXN];

vector<int> loc[MAXN];

int srch(int num, int start) {
  vector<int>::iterator it = lower_bound(loc[num].begin(), loc[num].end(), start);
  if (it == loc[num].end()) return -1;
  return *it;
}

int DP[MAXK];

int main() {
  scanf("%d %d %d %d", &N, &M, &S, &E);

  for(int i = 1; i <= N; ++i) {
    scanf("%d", A + i);
  }
  for(int i = 1; i <= M; ++i) {
    scanf("%d", B + i);
    loc[B[i]].push_back(i);
  }

  int ans = 0;
  DP[0] = 1;
  for(int i = 1; i <= N; ++i) {
    for(int k = MAXK - 1; k >= 0; --k) {
      int s = DP[k];
      if (!s) continue;
      int nxt = srch(A[i], s);
      if (nxt != -1) {
        if (nxt + 1 < DP[k + 1] || !DP[k + 1]) {
          DP[k + 1] = nxt + 1;
        }
      }
    }
    for(int k = 1; k < MAXK; ++k) {
      if (!DP[k]) continue;
      int energy = k * E + i + DP[k] - 1;
      if (energy <= S) {
        if (k > ans) ans = k;
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
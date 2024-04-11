#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;
int a[N], cnt[N], sm[N], sc[N], mode;
int L[N], R[N];
int last[N];
vector<int> pos[N];
int _first[N * 2], *first = _first + N;
int n;

int force_solve(int x, int y) {
  first[0] = 0;
  int s = 0, res = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == x) ++s;
    if (a[i] == y) --s;
    if (first[s] != -1) res = max(res, i - first[s]);
    else first[s] = i;
  }
  fill(first - n, first + n + 1, -1);
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), ++cnt[a[i]];
  mode = max_element(cnt + 1, cnt + 1 + n) - cnt;
  fill(first - n, first + n + 1, -1);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (!cnt[i] || i == mode) continue;
    res = max(res, force_solve(mode, i));
  }
  printf("%d\n", res);
  return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5010;

char grid[MAXN][MAXN];
int lft[MAXN][MAXN];
int N, M;

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; ++i) {
    scanf("%s", grid[i]);
    for(int j = 0; j < M; ++j) {
      if (grid[i][j] == '1') {
        lft[i][j + 1] = lft[i][j];
      } else {
        lft[i][j + 1] = j + 1;
      }
    }
  }

  int ans = 0;
  for(int r = 0; r < M; ++r) {
    vector<int> v;
    for(int i = 0; i < N; ++i) {
      if (grid[i][r] == '1') {
        int x = lft[i][r];
        v.push_back(x);
      }
    }
    sort(v.begin(), v.end());

    int len = v.size();
    for(int i = 0; i < len; ++i) {
      int val = (i + 1) * (r - v[i] + 1);
      if (val > ans) ans = val;
    }
  }

  printf("%d\n", ans);
  return 0;
}
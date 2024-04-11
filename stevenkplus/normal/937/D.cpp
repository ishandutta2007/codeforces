#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;

#define repi(i, a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
vector<int> ed[MAXN];

int dp[MAXN][2];
int trace[MAXN][2];

// j = 0 -> hero's turn
int get(int i, int j) {
  vector<int> &v = ed[i];
  int &ret = dp[i][j];
  int &tr = trace[i][j];
  if (ret == -1) {
    return 1; // this is actually a draw
  }
  if (ret) return ret - 1;
  if (v.size() == 0) {
    if (j == 0) ret = 0;
    else ret = 2;
  } else {
    ret = -1;
    int best = 0;
    repi(nxt, v) {
      int val = get(*nxt, 1 - j);
      if (val > best) {
        best = val;
        tr = *nxt;
      }
    }
    ret = best;
  }
  return ret++;
}

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    int k; cin >> k;
    for(int j = 0; j < k; ++j) {
      int b;
      cin >> b;
      ed[i].push_back(b);
    }
  }

  int s;
  cin >> s;
  int ans = get(s, 0);
  if (ans == 2) {
    printf("Win\n");
    int cur = s, j = 0;
    while (cur) {
      printf("%d ", cur);
      cur = trace[cur][j];
      j = 1 - j;
    }
    printf("\n");
  } else if (ans == 1) {
    printf("Draw\n");
  } else {
    printf("Lose\n");
  }
}
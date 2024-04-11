#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 300100;
const int inf = 1000 << 20;
char buf[MAXN];

int sums[MAXN][2]; // horizontal case, where row 1 = row 3 = row 5...

int ans = inf;
vector<vector<int> > ansV;
bool ansT;

int trace[MAXN][16][3];
int dp[MAXN][16];
int costs[2][MAXN][4];
void go(vector<vector<int> > input, bool isTransposed) {
  memset(trace, 0, sizeof(trace));
  memset(dp, 0, sizeof(dp));
  memset(costs, 0, sizeof(costs));
  int n = input.size(), m = input[0].size();

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      for(int k = 0; k < 4; ++k) {
        if (k != input[i][j]) {
          ++costs[i % 2][j][k];
        }
      }
    }
  }

  for(int k = 0; k < 16; ++k) {
    dp[0][k] = inf;
  }
  dp[0][0] = 0;

  for (int i = 0; i < m; ++i) {
    for (int k = 0; k < 16; ++k) {
      dp[i + 1][k] = inf;
    }
    for(int j = 0; j < 16; ++j) {
      // printf("At %d %d:  %d\n", i, j, dp[i][j]);
      for(int a = 0; a < 4; ++a) {
        for (int b = 0; b < 4; ++b) {
          if (a == b) continue;
          int k = (1 << a) | (1 << b);
          if (j & k) continue;
          int val = dp[i][j] + costs[0][i][a] + costs[1][i][b];
          if (val < dp[i + 1][k]) {
            // printf("Setting %d %d, %d\n", i + 1, k, val);
            dp[i + 1][k] = val;
            trace[i + 1][k][0] = a;
            trace[i + 1][k][1] = b;
            trace[i + 1][k][2] = j;
          }
        }
      }
    }
  }

  int ansj = -1;
  for (int j = 0; j < 16; ++j) {
    if (dp[m][j] < ans) {
      ans = dp[m][j];
      ansj = j;
      ansT = isTransposed;
    }
  }
  if (ansj != -1) {
    int j = ansj;
    vector<vector<int> > v(2);
    for(int i = 0; i < 2; ++i) {
      v[i] = vector<int>(m);
    }
    for (int i = m - 1; i >= 0; --i) {
      int a = trace[i + 1][j][0];
      int b = trace[i + 1][j][1];
      j = trace[i + 1][j][2];
      v[0][i] = a;
      v[1][i] = b;

    }
    ansV = v;
  }
}

int main() {
  map<int, char> mmp;
  map<char, int> mp;
  mp['A'] = 0; mmp[0] = 'A';
  mp['G'] = 1; mmp[1] = 'G';
  mp['C'] = 2; mmp[2] = 'C';
  mp['T'] = 3; mmp[3] = 'T';
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int> > input(n);
  vector<vector<int> > transposedInput(m);
  for(int i = 0; i < n; ++i) {
    scanf("%s", buf);
    for(int j = 0; j < m; ++j) {
      int v = mp[buf[j]];
      input[i].push_back(v);
      transposedInput[j].push_back(v);
    }
  }
  go(input, false);
  go(transposedInput, true);

  // printf("ans = %d\n", ans);
  // printf("ansT\n", ansT);
  // printf("ansV %dx%d\n", ansV.size(), ansV[0].size());

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if (ansT) {
        buf[j] = mmp[ansV[j % 2][i]];
      } else {
        buf[j] = mmp[ansV[i % 2][j]];
      }
    }
    buf[m] = 0;
    printf("%s\n", buf);
  }
}
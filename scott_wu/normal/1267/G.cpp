#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 111;
const int MAXM = 10010;

typedef long double ld;
ld counts[MAXN][MAXM];
ld chs[MAXN][MAXN];

int main() {
  chs[0][0] = 1;
  for(int i = 0; i + 1 < MAXN; ++i) {
    for(int j = 0; j <= i; ++j) {
      chs[i + 1][j] += chs[i][j];
      chs[i + 1][j + 1] += chs[i][j];
    }
  }
  int n;
  ld x;
  cin >> n >> x;
  ld ans = 0;
  vector<int> ar;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    ans += v;
    if (v > x / 2) {
      ar.push_back(v);
    }
  }
  n = ar.size();

  counts[0][0] = 1;
  for(int k = 0; k < n; ++k) {
    for(int i = MAXN - 2; i >= 0; --i) {
      for(int j = 0; j + ar[k] < MAXM; ++j) {
        counts[i + 1][j + ar[k]] += counts[i][j];
      }
    }
  }

  for(int i = 1; i <= n; ++i) {
    for(int j = 0; j < MAXM; ++j) {
      ld p = counts[i][j] / ld(chs[n][i]);
      ld v = -ld(j) / i + x + (ld(n) / i - 1) * x / 2;
      if (v < 0) {
        ans += p * v;
      }
      if (counts[i][j] > 0) {
        // cout << i << "," << j << ":" << p << " " << v << "\n";
      }
    }
  }
  printf("%.9lf\n", double(ans));
}
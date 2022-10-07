#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(x) (int((x).size()))
const int MAXC = 30;
const int MAXN = 1001000;

int trie[MAXN][MAXC];
vector<int> A[2][MAXN];

int match[MAXN];
int matched[MAXN];
char str[MAXN];

int main() {
  int n;
  int cnt = 0;
  scanf("%d", &n);
  for(int j = 0; j < 2; ++j) {
    for(int i = 1; i <= n; ++i) {
      scanf("%s", str);
      int cur = 0;
      A[j][cur].push_back(i);
      for(int c = 0; str[c]; ++c) {
        int ch = str[c] - 'A';
        int &nxt = trie[cur][ch];
        if (!nxt) {
          nxt = ++cnt;
        }
        cur = nxt;

        A[j][cur].push_back(i);
      }
    }
  }

  int ans = 0;
  for(int i = cnt; i >= 0; --i) {
    int a = 0, b = 0;
    vector<int> &x = A[0][i], &y = A[1][i];
    if (i)
      ans += min(sz(x), sz(y));
    while (a < sz(x) && b < sz(y)) {
      if (match[x[a]]) ++a;
      else if (matched[y[b]]) ++b;
      else {
        match[x[a]] = y[b];
        matched[y[b]] = x[a];
        ++a;
        ++b;
      }
    }
  }

  printf("%d\n", ans);
  for(int i = 1; i <= n; ++i) {
    printf("%d %d\n", i, match[i]);
  }
}
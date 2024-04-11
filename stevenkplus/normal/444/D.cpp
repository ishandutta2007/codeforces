#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
typedef pair<int, int> pii;

const int MAXN = 100100;
const int MAXP = 1000100;

int A[MAXN];
int B[MAXN];

vector<int> occ[MAXP];

int Q;
char str[MAXN];
char a[MAXN], b[MAXN];

map<pii, int> dp;

int conv(char *s, int l) {
  int ret = 0;
  for(int i = 0; i < l; ++i) {
    ret = ret * 27 + s[i] - 'a' + 1;
  }

  return ret;
}

int N;

int go(vector<int> &a, vector<int> &b, int x, int y) {
  int ans = -1;
  repi(i, a) {
    int l = *i;
    int r = *i + x;

    int p = int(lower_bound(b.begin(), b.end(), l) - b.begin()); // b[p] >= l
    if (p < b.size()) {
      int rr = b[p] + y;
      if (r > rr) rr = r;
      int len = rr - l;
      if (len < ans || ans == -1) ans = len;
    }
    --p; // b[p] < l
    if (p >= 0) {
      int rr = p + y;
      if (r > rr) rr = r;
      int len = rr - b[p];
      if (len < ans || ans == -1) ans = len;
    }
  }
  return ans;
}

int main() {
  scanf("%s", str);
  N = strlen(str);
  scanf("%d", &Q);

  for(int i = 0; i < N; ++i) {
    for(int j = i + 1; j <= N && j <= i + 4; ++j) {
      int k = conv(str + i, j - i);
      occ[k].push_back(i);
    }
  }

  for(int q = 0; q < Q; ++q) {
    scanf("%s %s", a, b);
    int l1 = strlen(a), l2 = strlen(b);
    int x = conv(a, l1);
    int y = conv(b, l2);
    if (occ[x].size() > occ[y].size() || (occ[x].size() == occ[y].size() && x > y)) {
      swap(x, y);
      swap(l1, l2);
    }

    int &ans = dp[pii(x, y)];
    if (!ans) ans = go(occ[x], occ[y], l1, l2);
    printf("%d\n", ans);
  }

}
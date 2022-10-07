#include <cstdio>

const int MAXC = 26;
const int MAXN = 50100;

int str[MAXN];
char buf[MAXN];
int N;

int DP[MAXN][55];
bool vis[MAXN][55];
int trace[MAXN][55];
int lst[MAXN][MAXC];

char ans[MAXN];

int getdp(int n, int l) {
  if (n < 0) return -1;
  if (l <= 0) {
    return N;
  }
  int &ret = DP[n][l];
  if (vis[n][l]) return ret;
  int a = getdp(n - 1, l);
  int b = getdp(n - 1, l - 1);
  if (b != -1) {
    b = lst[b - 1][str[n - 1]];
  }

  if (b > a) {
    a = b;
    trace[n][l] = 2;
  } else {
    trace[n][l] = 1;
  }
  if (a < n) a = -1;
  vis[n][l] = true;
  return ret = a;
}

int main(){ 
  scanf("%s", buf);
  N = 0;
  while (buf[N]) {
    str[N] = buf[N] - 'a';
    ++N;
  }

  for(int i = 0; i < N; ++i) {
    DP[i][0] = N;
  }
  for(int i = 0; i < MAXC; ++i) {
    int cur = -1;
    for(int j = 0; j <= N; ++j) {
      if (str[j] == i) cur = j;
      lst[j][i] = cur;
    }
  }

  int bst = 0;
  for(int i = 0; i <= 50; ++i) {
    bool good = false;
    for(int j = 0; j < N; ++j) {
      if (getdp(j, i) != -1) {
        good = true;
        break;
      }
    }
    if (!good) {
      bst = i - 1;
      break;
    } else if (i == 50) {
      bst = 50;
    }
  }

  int st = -1;
  bool odd = false;
  for(int i = 0; i < N; ++i) {
    int k = getdp(i, bst);
    if (k != -1) {
      st = i;
      if (k > i) {
        odd = true;
        break;
      }
    }
  }

  int cur = st;
  int k = bst;
  int pos = 0;
  while (k > 0) {
    int t = trace[cur][k];
    if (t == 1) {
      --cur;
    } else {
      --cur;
      ans[pos] = str[cur] + 'a';
      ++pos;
      --k;
    }
  }

  if (odd && bst == 50) odd = false;
  for(int i = bst - 1; i >= 0; --i) {
    printf("%c", ans[i]);
  }
  if (odd) printf("%c", str[st] + 'a');
  for(int i = 0; i < bst; ++i) {
    printf("%c", ans[i]);
  }
  printf("\n");
  return 0;
}
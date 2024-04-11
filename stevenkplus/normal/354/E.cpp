#include <cstdio>
#include <cstring>

const int MAXN = 20;

int N;
int T;
bool vis[MAXN][10];
int ans[6][MAXN];
int digs[MAXN];
bool can[10][10];
int make[6][10][10];
char str[MAXN];

void prec() {
  for(int a = 0; a <= 6; ++a) {
    for(int b = 0; b + a <= 6; ++b) {
      int c = 6 - (b + a);
      int val = c * 7 + b * 4;
      int t = val / 10;
      int o = val % 10;
      can[o][t] = true;
      for(int i = 0; i < 6; ++i) {
        int &m = make[i][o][t];
        if (i < a) {
          m = 0;
        } else if (i < a + b) {
          m = 4;
        } else {
          m = 7;
        }
      }
    }
  }
}

bool go(int pos, int dig) {
  if (pos == -1) {
    if (dig == 0) return true;
    else return false;
  }

  if (vis[pos][dig]) return false;
  vis[pos][dig] = true;
  dig = digs[pos] - dig;
  int subtr = 0;
  if (dig < 0) {
    ++subtr;
    dig += 10;
  }

  for(int i = 0; i < 10; ++i) {
    if (can[dig][i]) {
      if (go(pos - 1, i + subtr)) {
        for(int j = 0; j < 6; ++j) {
          ans[j][pos] = make[j][dig][i];
        }
        return true;
      }
    }
  }

  return false;
}

void disp(int x) {
  bool first = true;
  for(int i = 0; i < N; ++i) {
    if (ans[x][i] == 0 && first) continue;
    else {
      first = false;
      printf("%d", ans[x][i]);
    }
  }
  if (first) printf("0");
}

int main() {
  prec();
  scanf("%d", &T);
  for(int t = 0; t < T; ++t) {
    memset(vis, 0, sizeof(vis));
    scanf("%s", str);
    for(int i = 0; str[i]; ++i) {
      digs[i] = str[i] - '0';
      N = i + 1;
    }

    if (go(N - 1, 0)) {
      for(int i = 0; i < 6; ++i) {
        if (i) printf(" ");
        disp(i);
      }
      printf("\n");
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
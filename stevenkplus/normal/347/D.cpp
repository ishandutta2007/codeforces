#include <cstdio>

const int MAXN = 110;

int dp[MAXN][MAXN][MAXN];
int choice[MAXN][MAXN][MAXN];
char A[MAXN];
char B[MAXN];
char C[MAXN];
int fail[MAXN];

bool mx(int &a, int b) {
  if (b > a) {
    a = b;
    return true;
  } else return false;
}

int get(int a, int b, int c) {
  if (C[c] == 0) return -1;
  if (A[a] == 0 || B[b] == 0) return 0;
  int &ans = dp[a][b][c];
  int &ch = choice[a][b][c];
  if (ans) return ans - 2;

  if (A[a] == B[b]) {
    int d = c;
    while (d >= 0 && C[d] != A[a]) d = fail[d];
    ++d;
    if(mx(ans, 1 + get(a + 1, b + 1, d))) {
      ch = 1;
    }
  }
  if(mx(ans, get(a + 1, b, c))) {
    ch = 2;
  }
  if(mx(ans, get(a, b + 1, c))) {
    ch = 3;
  }
  ans += 2;
  return ans - 2;
}

void trc(int a, int b, int c) {
  while (true) {
    int ch = choice[a][b][c];
    if (ch == 1) {
      printf("%c", A[a]);
      while (c >= 0 && C[c] != A[a]) c = fail[c];
      ++c;
      ++a;
      ++b;
    } else if (ch == 2) {
      ++a;
    } else if (ch == 3) {
      ++b;
    } else {
      printf("\n");
      return;
    }
  }
}

int main() {
  scanf("%s %s %s", A, B, C);

  fail[0] = -1;
  fail[1] = 0;
  for(int i = 1; C[i]; ++i) {
    int cur = fail[i];
    while (cur >= 0 && C[cur] != C[i]) {
      cur = fail[cur];
    }
    ++cur;
    fail[i + 1] = cur;
  }

  int ans = get(0, 0, 0);
  //printf("%d\n", ans);
  if (ans)
    trc(0, 0, 0);
  else printf("0\n");
  return 0;
}
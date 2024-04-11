#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int T, n;
char s[51], ans[50][51];

int main() {
  scanf("%d", &T);
  while (T--)
    [] {
      scanf("%d%s", &n, s);
      if (count(s, s + n, '2') == 1 || count(s, s + n, '2') == 2) {
        printf("NO\n");
        return;
      }
      memset(ans, 0, sizeof(ans));
      rep(i, n) rep(j, n) if (s[i] == '1' || s[j] == '1') ans[i][j] = '=';
      rep(i, n) ans[i][i] = 'X';
      rep(i, n) if (s[i] == '2') {
        bool found = false;
        rep(j, n) {
          if (ans[i][j] == 0)
            ans[i][j] = found ? '-' : '+', ans[j][i] = ans[i][j] ^ '+' ^ '-';
          found |= ans[i][j] == '+';
        }
        assert(find(ans[i], ans[i + 1], '+') != ans[i + 1]);
      }
      printf("YES\n");
      rep(i, n) printf("%s\n", ans[i]);
    }();
}
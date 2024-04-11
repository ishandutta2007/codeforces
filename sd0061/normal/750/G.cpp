#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 128;

LL f[2][N][2];
LL cal(int lx , int ly , int one , LL sum) {
  memset(f , 0 , sizeof(f));
  f[0][0][0] = 1;
  int cur = 0 , nxt = 1;
  for (int i = 0 ; (sum >> i) ; ++ i) {
    memset(f[nxt] , 0 , sizeof(f[nxt]));
    for (int dx = 0 ; dx < 2 ; ++ dx) {
      for (int dy = 0 ; dy < 2 ; ++ dy) {
        if (i >= lx && dx) continue;
        if (i >= ly && dy) continue;
        for (int j = 0 ; j < 2 ; ++ j) {
          int num = dx + dy + j;
          if ((sum >> i & 1) != (num & 1)) continue;
          for (int k = 0 ; k + dx + dy <= one ; ++ k) {
            f[nxt][k + dx + dy][num >> 1] += f[cur][k][j];
          }
        }
      }
    }
    swap(cur , nxt);
  }
  return f[cur][one][0];
}

int main() {
  LL s;
  cin >> s;
  LL res = 0;
  for (int a = 0 ; a <= 60 ; ++ a) {
    for (int b = 0 ; b <= 60 ; ++ b) {
      LL coff = (1LL << a + 1) + (1LL << b + 1) - 3;
      LL lca = s / coff , rem = s % coff - (1LL << b) + 1;
      if (lca < 1) continue;
      // 2(x + y) == rem + popcount(x) + popcount(y)
      // x < 2^{a-1} , y < 2^{b-1}
      for (int c = 0 ; c <= 120 ; ++ c) {
        LL sum = rem + c;
        if (sum < 0 || sum % 2 == 1) continue;
        sum >>= 1;
        res += cal(max(0 , a - 1) , max(0 , b - 1) , c , sum);
      }
    }
  }
  cout << res << endl;
}
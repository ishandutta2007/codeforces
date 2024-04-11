#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int n , m, a[N][N];

int main() {
  int T;
  scanf("%d" , &T);
  while (T --) {
    scanf("%d%d" , &n , &m);
    bool flag = 0;
    for (int i = 0 ; i < n  ; ++ i) {
      for (int j = 0 ; j < m ; ++ j) {
        scanf("%d" , &a[i][j]);
        int deg = 0;
        if (i) ++ deg;
        if (i + 1 < n) ++ deg;
        if (j) ++ deg;
        if (j + 1 < m) ++ deg;
        if (a[i][j] > deg) {
          flag = 1;
        }
        a[i][j] = deg;
      }
    }
    if (flag) {
      puts("NO");
    } else {
      puts("YES");
      for (int i = 0 ; i < n ;  ++ i) {
        for (int j= 0 ; j < m ; ++ j) {
          printf("%d%c" , a[i][j]  , " \n"[j + 1 == m]);
        }
      }
    }
  }
}
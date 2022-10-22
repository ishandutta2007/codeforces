#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int main() {
  int T;
  scanf("%d" , &T);
  while (T --) {
    int n;
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
      int x;
      scanf("%d" , &x);
      x = abs(x);
      if (i & 1) {
        x = -x;
      }
      printf("%d%c" , x , " \n"[i + 1 == n]);
    }
  }
}
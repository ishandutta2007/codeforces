#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n , m, a[N];

int main() {
  int T;
  scanf("%d" , &T);
  while (T --) {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
      scanf("%d" , &a[i]);
    }
    puts(a[0] < a[n - 1] ? "YES" : "NO");
  }
}
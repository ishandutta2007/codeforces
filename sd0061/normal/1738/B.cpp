#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

int n , K , s[N];
int64  a[N];

void work() {
  scanf("%d%d", &n, &K);
  for (int i = n - K + 1; i <= n ; ++ i) {
    scanf("%d", &s[i]);
  }
  if (K == 1) {
    puts("Yes");
  } else {
    std::vector<int> b;
    for (int i = n - K + 2 ; i <= n ; ++ i) {
      int x = s[i] - s[i - 1];
      b.emplace_back(x);
    }
    for (int i = 0 ; i + 1 < b.size() ; ++ i) {
      if (b[i] > b[i + 1]) {
        puts("No");
        return;
      }
    }
    int d = b[0]; // d >= s[n - K + 1] / 
    if (1LL * d * (n - K + 1) < s[n - K + 1]) {
      puts("No");
    } else {
      puts("Yes");
    }
  }
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T --) {
    work();
  }
  return 0;
}
#include <cstdio>
#include <cmath>

int n, ans, t, q;

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++)
    for (int j = i; j < n; j++) {
      t = i * i + j * j;
      if (t > n * n) 
        continue;
      q = sqrt(t);
      if (t == q * q) 
        ans++;
    }
  printf("%d\n", ans); 
}
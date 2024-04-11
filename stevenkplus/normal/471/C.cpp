#include <cstdio>
#include <iostream>
using namespace std;

long long go(long long x) {
  long long houses = x * (x + 1) / 2;
  return houses * 3 - x;
}

int main() {
  long long n;
  cin >> n;
  int ans = 0;
  for(int h = 1; h < 1000000; ++h) {
    long long need = go(h);
    if (need <= n) ans = h;
  }
  int x = n % 3; // x = 2 -> 1, 0 -> 3, 1 -> 2
  if (x == 0) {
    printf("%d\n", (ans) / 3);
  } else if (x == 1) {
    printf("%d\n", (ans + 1) / 3);
  } else {
    printf("%d\n", (ans + 2) / 3);
  }
}
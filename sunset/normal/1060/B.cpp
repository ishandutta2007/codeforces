#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  long long n;
  cin >> n;
  int answer = 0;
  long long current = 0;
  while (n >= current * 10 + 9) {
    current = current * 10 + 9;
    answer += 9;
  }
  n -= current;
  while (n) {
    answer += n % 10;
    n /= 10;
  }
  printf("%d\n", answer);
  return 0;
}
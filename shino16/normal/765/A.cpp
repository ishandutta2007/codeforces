#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int n; scanf("%d", &n);
  printf("%s\n", n % 2 ? "contest" : "home");
}
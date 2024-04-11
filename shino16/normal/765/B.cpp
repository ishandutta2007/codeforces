#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

char s[501];
int main() {
  scanf("%s", s);
  bool fail = s[0] != 'a';
  int n = strlen(s);
  char maxi = 'a';
  rep(i, n) {
    fail |= s[i] > maxi + 1;
    maxi = max(maxi, s[i]);
  }
  printf("%s\n", fail ? "NO" : "YES");
}
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n, m, len, x;
  scanf("%d%d", &n, &m);
  bool u[200]; for (int i = 0; i < 199; i++) u[i] = false;
  for (int i = 0; i < n; i++) {
    scanf("%d", &len);
    for (int j = 0; j < len; j++) {
      scanf("%d", &x); u[x] = true;
    }
  }
  for (int i = 1; i <= m; i++)
    if (!u[i]) {cout << "NO"; return 0;}
  cout << "YES";
  return 0;
}
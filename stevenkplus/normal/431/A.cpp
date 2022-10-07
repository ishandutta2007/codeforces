#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 100100;

int N, M;
int ar[MAXN];
char str[MAXN];

int main() {
  for(int i = 0; i < 4; ++i) {
    scanf("%d", ar + i);
  }

  int ans = 0;
  scanf("%s", str);
  for(int i = 0; str[i]; ++i) {
    ans += ar[str[i] - '1'];
  }

  printf("%d\n", ans);
}
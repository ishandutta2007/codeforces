#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200200;
int _ar[MAXN];
int n, k;
int _main() {
  _ar[0] = 1;
  int *ar = _ar + 1;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) {
    scanf("%d", ar + i);
  }
  sort(ar, ar + n);
  if (ar[k - 1] == ar[k]) return -1;
  else return ar[k-1];
}

int main() {
  printf("%d\n", _main());
}
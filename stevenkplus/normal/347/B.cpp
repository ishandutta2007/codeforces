#include <cstdio>

const int MAXN = 100100;

int N;
int ar[MAXN];

int main() {
  scanf("%d", &N);
  int cnt = 0;
  bool found = false;
  bool found2 = false;
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
    if (ar[i] < i) {
      if (ar[ar[i]] == i) {
        found = true;
      } else {
        found2 = true;
      }
    } else if (ar[i] == i) {
      ++cnt;
    }
  }

  if (found) cnt += 2;
  else if (found2) cnt += 1;
  printf("%d\n", cnt);
  return 0;
}
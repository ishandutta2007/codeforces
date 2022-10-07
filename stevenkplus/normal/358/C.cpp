#include <cstdio>
#include <algorithm>

const int MAXN = 100100;
using namespace std;

typedef pair<int, int> pii;

pii ar[MAXN];

int N;
int main() {
  scanf("%d", &N);

  int cnt = 0;
  for(int i = 0; i < N; ++i) {
    int tmp;
    scanf("%d", &tmp);
    ar[cnt] = pii(-tmp, cnt);
    if (tmp == 0) {
      sort(ar, ar + cnt);
      for(int j = 0; j < cnt; ++j) {
        if (j == ar[0].second) printf("pushStack\n");
        else if (j == ar[1].second) printf("pushQueue\n");
        else if (j == ar[2].second) printf("pushFront\n");
        else printf("pushBack\n");
      }

      int take = 3;
      if (cnt < take) take = cnt;

      printf("%d", take);
      if (take >= 1) printf(" popStack");
      if (take >= 2) printf(" popQueue");
      if (take >= 3) printf(" popFront");
      printf("\n");

      cnt = 0;
    } else {
      ++cnt;
    }
  }
  for(int i = 0; i < cnt; ++i) {
    printf("pushStack\n");
  }

  return 0;
}
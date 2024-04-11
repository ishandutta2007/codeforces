#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100100;

int ar[MAXN];
int N;

int main() {
  int sum = 0;
  for(int i = 0; i < 6; ++i) {
    scanf("%d", ar + i);
    sum ^= ar[i];
  }
  sort(ar, ar + 6);
  if (ar[0] != ar[3] && ar[1] != ar[4] && ar[2] != ar[5]) {
    printf("Alien\n");
  } else if (sum) {
    printf("Bear\n");
  } else {
    printf("Elephant\n");
  }
}
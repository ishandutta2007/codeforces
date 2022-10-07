#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 110;

int ar[MAXN];
int N;

int main() { 
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }
  sort(ar, ar + N);
  swap(ar[0], ar[N - 1]);
  for(int i = 0; i < N; ++i) {
    if(i) printf(" ");
    printf("%d", ar[i]);
  } 

  printf("\n");
  return 0;
}
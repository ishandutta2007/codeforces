#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1111;
typedef pair<int, int> pii;

pii ar[MAXN];

int N, S;
int main() {
  scanf("%d %d", &N, &S);
  S = 1000000 - S;
  for(int i = 0; i < N; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    ar[i] = pii(a*a+b*b, c);
  }
  sort(ar, ar + N);

  int prv = 0;
  int i = 0, cnt = 0;
  while (i < N && cnt < S) {
    prv = ar[i].first;
    cnt += ar[i].second;
    ++i;
  }

  if (cnt < S) {
    printf("-1\n");
  } else {
    printf("%.10lf\n", sqrt(prv));
  }

  return 0;
}
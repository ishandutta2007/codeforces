#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long double ld;

const int MAXN = 300100;
int ar[MAXN];
int A[MAXN];
int B[MAXN];
pii arr[MAXN];

int N;

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) {
    scanf("%d", ar + i);
    arr[i - 1] = pii(ar[i], i);
  }

  for(int i = 1; i <= N; ++i) {
    A[i] = i - 1;
    B[i] = i + 1;
  }


  ld ans = 0;
  sort(arr, arr + N);
  for(int i = 0; i < N; ++i) {
    int x = arr[i].second;
    int a = A[x], b = B[x];
    B[a] = b;
    A[b] = a;

    ld lft = 0, rgt = 0;
    int cur = x;
    ld scal = 1;
    for(int j = 0; j < 40; ++j) {
      if (cur) {
        lft += (cur - A[cur]) * scal;
        cur = A[cur];
        scal /= 2;
      } else break;
    }

    cur = x;
    scal = 1;
    for(int j = 0; j < 40; ++j) {
      if (cur <= N) {
        rgt += (B[cur] - cur) * scal;
        cur = B[cur];
        scal /= 2;
      } else break;
    }

//    printf("At %d, lft = %lf, rgt = %lf\n", i, double(lft), double(rgt));
    ans += lft * rgt * ar[x] / 2;
  }

  cout << setprecision(10) << (ans / N / N) << "\n";
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 7;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    vector<int> a(N);
    int n;
    scanf("%d", &n);
    int each = 0;
    for (int i = 0; i < N; ++i) {
      scanf("%d", &a[i]);
      each += a[i];
    }
    int week = (n - 1) / each;
    int answer = N;
    for (int i = 0; i < N; ++i) {
      int remain = n - week * each;
      for (int j = 1; j <= N; ++j) {
        if (a[(i + j) % N]) {
          --remain;
          if (!remain) {
            answer = min(answer, j);
            break;
          }
        }
      }
    }
    printf("%d\n", week * N + answer);
  }
  return 0;
}
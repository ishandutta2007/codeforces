#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 8005;
int n, a[N + 20];
bool cnt[N * 10];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      // a[i] = rand() % n + 1;
    }
    memset(cnt, 0, sizeof(cnt));
    int t = n;
    for (int i = 0; i < t; ++i) {
      int j = i + 1, sum = a[i];
      for (; j < n && sum < N;) {
        sum += a[j++];
        cnt[sum] = 1;
      }
    }
    int res = 0;
    for (int i = 0; i < t; ++i) {
      if (cnt[a[i]]) {
        ++res;
        // cout << i << ' ' << a[i] << " ???" << endl;
      }
    }
    printf("%d\n", res);
  }
}
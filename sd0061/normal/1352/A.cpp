#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    vector<int> v;
    int m = 1;
    while (n) {
      if (n % 10) {
        v.push_back(m * (n % 10));
      }
      m *= 10;
      n /= 10;
    }
    printf("%d\n", v.size());
    for (auto &x : v) {
      printf("%d ", x);
    }
    puts("");
  }
}
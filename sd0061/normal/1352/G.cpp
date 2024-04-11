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
    if (n < 4) {
      puts("-1");
    } else {
      deque<int> q;
      q.push_back(3);
      q.push_back(1);
      q.push_back(4);
      q.push_back(2);
      for (int x = 5; x <= n; ++x) {
        if (x & 1) {
          q.push_back(x);
        } else {
          q.push_front(x);
        }
      }
      while (!q.empty()) {
        printf("%d ", q.front());
        q.pop_front();
      }
      puts("");
    }
  }
}
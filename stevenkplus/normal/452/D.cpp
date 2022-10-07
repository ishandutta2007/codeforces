#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int> > pq;
int k, n1, n2, n3, t1, t2, t3;

int pp(pq &p) {
  int ret = p.top(); p.pop();
  return ret;
}

int max(int a, int b, int c) {
  if (b > a) a = b;
  if (c > a) a = c;
  return a;
}

int main() {
  scanf("%d %d %d %d %d %d %d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
  pq a, b, c;
  for(int i = 0; i < n1; ++i) {
    a.push(t1 + t2 + t3);
  }
  for(int i = 0; i < n2; ++i) {
    b.push(t2 + t3);
  }
  for(int i = 0; i < n3; ++i) {
    c.push(t3);
  }

  int ans = 0;
  for(int i = 0; i < k; ++i) {
    int x = pp(a), y = pp(b), z = pp(c);
    ans = max(x, y, z);
    a.push(ans + t1);
    b.push(ans + t2);
    c.push(ans + t3);
  }

  printf("%d\n", ans);
}
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 100;

typedef long long ll;

int ans[MAXN];
int N;
ll M;

int main() {
  cin >> N >> M;
  --M;

  int a = 0, b = N - 1;
  int cnt = 1;
  for(int i = N - 2; i >= 0; --i) {
    if (M & (1LL << i)) {
      ans[b] = cnt;
      --b;
    } else {
      ans[a] = cnt;
      ++a;
    }
    ++cnt;
  }
  ans[a] = N;

  for(int i = 0; i < N; ++i) {
    printf("%d ", ans[i]);
  }

  printf("\n");
  return 0;
}
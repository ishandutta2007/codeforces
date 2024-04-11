#include <cstdio>
#include <iostream>

using namespace std;

int N;
int main() {
  scanf("%d", &N);
  int cnt = 0;
  long long ans = 0;

  for(int i = 0; i < N; ++i) {
    int nxt;
    scanf("%d", &nxt);
    if (nxt == 0) {
      ans += cnt;
    } else {
      ++cnt;
    }
  }

  cout << ans << "\n";
  return 0;
}
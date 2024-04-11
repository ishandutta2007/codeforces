#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i != (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(x) begin(x), end(x)

int t, n, a[100000];
int cnt[100001];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    rep(i, n) scanf("%d", a+i);
    fill(cnt, cnt+n, 0);
    bool fail = false;
    rep(i, n) {
      for (int j = i+1; j--;) if (a[i] % (j+2) != 0) {
        cnt[i-j]++;
        goto done;
      }
      fail = true;
      done: ;
    }
    int done = 0;
    rep(i, n) {
      if (cnt[i] && done < i) fail = true;
      done += cnt[i];
    }
    if (!fail) printf("YES\n");
    else printf("NO\n");
  }
}
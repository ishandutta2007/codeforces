#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 100100;
int par[MAXN];
int s[MAXN]; // if -1, s[i] = max(s[j] for j in children[i])

ll go() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    scanf("%d", par + i);
  }
  for(int i = 1; i <= n; ++i) {
    scanf("%d", s + i);
    if (s[i] != -1) {
      if (i > 1) {
        if (s[par[i]] == -1 || s[par[i]] > s[i]) s[par[i]] = s[i];
      }
    }
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i) {
    if (s[i] == -1) continue;
    int a = s[i] - s[par[i]];
    ans += a;
    if (a < 0) return -1;
    // cout << i << ":" << par[i] << "," << s[i] << "," << a << "\n";
  }
  return ans;
}
int main() {
  cout << go() << "\n";
}
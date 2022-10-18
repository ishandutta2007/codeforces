#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(x) begin(x), end(x)

int t, n, a[100];
vector<int> ans;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    rep(i, n) scanf("%d", a+i);
    int sum = accumulate(a, a+n, 0);
    bool prime = true;
    for (int y = 2; y * y <= sum; y++) if (sum % y == 0) {
      prime = false;
      break;
    }
    ans.clear();
    rep(i, n) {
      if (a[i] % 2 && prime) {prime = false; continue;}
      ans.push_back(i+1);
    }
    assert(!prime);
    printf("%zd\n", ans.size());
    rep(i, ans.size()) printf("%d%c", ans[i], " \n"[i==ans.size()-1]);
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
#define M 200010

vector <PII> a, b, ans;
int n, m, X, Y;

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d %d %d", &n, &m, &X, &Y);
  int x;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x); a.push_back(PII(x, i));
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &x); b.push_back(PII(x, i));
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int cur = 0;
  for (int i = 0; i < n; i++) {
    while (cur < m && b[cur].first < a[i].first - X) cur++;
    if (cur < m && b[cur].first <= a[i].first + Y) {
      ans.push_back(PII(a[i].second, b[cur].second)); cur++;
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
}
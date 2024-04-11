#include <bits/stdc++.h>
using namespace std;
#define M 1010

int c[M], t[M], n, m, cnt;

__int64 tot;

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; i++) {
    scanf("%d %d", c + i, t + i);
    if (t[i] == 1) cnt++;
  }
  vector <vector <int> > ans;
  if (cnt < m) {
    for (int i = 1; i <= n; i++) {
      if (t[i] == 1) {
        vector <int> v;
        v.push_back(i); tot += c[i];
        ans.push_back(v);
      }
    }
    vector <int> u;
    int sz = 0;
    for (int i = 1; i <= n; i++) {
      if (t[i] == 2) {
        if (sz < m - cnt - 1) {
          vector <int> v;
          v.push_back(i);
          ans.push_back(v);
        }
        else {
          u.push_back(i);
        }
        sz++; tot += 2 * c[i];
      }
    }
    if (u.size()) ans.push_back(u);
  }
  else {
    vector <pair <int, int> > u;
    for (int i = 1; i <= n; i++) {
      if (t[i] == 1) u.push_back(make_pair(c[i], i));
    }
    sort(u.begin(), u.end());
    for (int i = cnt - m + 1; i < cnt; i++) {
      vector <int> v;
      v.push_back(u[i].second); tot += u[i].first;
      ans.push_back(v);
    }
    vector <int> v;
    int mn = u[0].first;
    for (int i = 0; i <= cnt - m; i++) {
      v.push_back(u[i].second); tot += 2 * u[i].first;
    }
    for (int i = 1; i <= n; i++) {
      if (t[i] == 2) {
        v.push_back(i), tot += 2 * c[i];
        mn = min(mn, c[i]);
      }
    }
    ans.push_back(v);
    tot -= mn;
  }
  printf("%.1lf\n", 1. * tot / 2);
  for (int i = 0; i < m; i++) {
    printf("%d ", ans[i].size());
    for (int j = 0; j < ans[i].size(); j++) printf("%d ", ans[i][j]); puts("");
  }
}
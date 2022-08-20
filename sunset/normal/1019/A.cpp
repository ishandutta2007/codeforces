#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3005;

int n, m, first, p[N], c[N];
vector<int> a[N];
ll answer;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  answer = 1ll << 60;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &p[i], &c[i]);
    if (p[i] == 1) {
      ++first;
    }
    a[p[i]].push_back(c[i]);
  }
  for (int i = 1; i <= m; ++i) {
    sort(a[i].begin(), a[i].end());
  }
  for (int i = max(first, 1); i <= n; ++i) {
    ll result = 0;
    vector<int> all;
    for (int j = 2; j <= m; ++j) {
      if (a[j].size() < i) {
        for (auto x : a[j]) {
          all.push_back(x);
        }
      } else {
        for (int k = 0; k <= a[j].size() - i; ++k) {
          result += a[j][k];
          all.push_back(0);
        }
        for (int k = a[j].size() - i + 1; k < a[j].size(); ++k) {
          all.push_back(a[j][k]);
        }
      }
    }
    sort(all.begin(), all.end());
    for (int j = 0; j < i - first; ++j) {
      result += all[j];
    }
    answer = min(answer, result);
  }
  printf("%lld\n", answer);
  return 0;
}
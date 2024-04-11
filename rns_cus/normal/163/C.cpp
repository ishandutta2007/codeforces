#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
#define M 1000010
#define ep 1e-9

double a[M], cnt[M];
int n, l, v1, v2;

vector <pair <double, int> > v;

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d %d %d", &n, &l, &v1, &v2);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  double d = 1. * l * v2 / (v1 + v2);
  for (int i = 0; i < n; i++) v.push_back(make_pair(a[i], -1)), v.push_back(make_pair(a[i] - d, 1)), v.push_back(make_pair(a[i] - d + 2 * l, 1));

  v.push_back(make_pair(0, 0));
  v.push_back(make_pair(2 * l, 0));

  sort(v.begin(), v.end());

  int cur = 0;

  for (int i = 0; i < v.size(); i++) {
    if (v[i].first > 2 * l) break;
    if (v[i].first > 0) cnt[cur] += (v[i].first - v[i - 1].first);
    cur += v[i].second;
  }

  for (int i = 0; i <= n; i++) {
    printf("%.20lf\n", 1. * cnt[i] / 2 / l);
  }
}
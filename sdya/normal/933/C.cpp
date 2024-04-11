#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>

using namespace std;

const int maxN = 510;
const double eps = 1e-9;
const double pi = 2 * acos(0.0);
const double eps1 = 1e-12;
const double eps2 = 1e-9;

int n;
double x[maxN], y[maxN], r[maxN];
int g[maxN][maxN];
int whatcmp[maxN];

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int check(int i, int j) {
  double d = dist(x[i], y[i], x[j], y[j]);
  if (fabs(d - r[i] - r[j]) < eps) return 1;
  if (d < r[i] + r[j] - eps &&
      d + r[i] - eps > r[j] &&
      d + r[j] - eps > r[i]) return 1;
  if (fabs(d + r[i] - r[j]) < eps) return 2;
  if (fabs(d + r[j] - r[i]) < eps) return 2;
  return 0;
}

void dfs(int v, int cmp) {
  if (whatcmp[v] != -1) return;
  whatcmp[v] = cmp;
  for (int i = 0; i < n; ++i) {
    if (g[v][i]) {
      dfs(i, cmp);
    }
  }
}

int edges[maxN];
int vertices[maxN];
vector <pair<double, double> > v[maxN];
int used[maxN][maxN];

void update(vector <double>& ang, int i, int j) {
  double d = dist(x[i], y[i], x[j], y[j]);
  if (g[i][j] == 2) {
    double curang = atan2(y[j] - y[i], x[j] - x[i]);
    if (r[i] < r[j]) {
      curang -= pi;
    }
    ang.push_back(curang);
    if (!used[i][j])
    v[whatcmp[i]].push_back(make_pair(x[i] + r[i] * cos(curang), y[i] + r[i] * sin(curang)));
    used[i][j] = used[j][i] = 1;
    return;
  }
  double value = (r[i] * r[i] + d * d - r[j] * r[j]) / 2 / r[i] / d;
  if (value > 1) value = 1;
  if (value < -1) value = -1;
  value = acos(value);
  double curang = atan2(y[j] - y[i], x[j] - x[i]);
  ang.push_back(curang + value);
  ang.push_back(curang - value);
  if (!used[i][j]) v[whatcmp[i]].push_back(make_pair(x[i] + r[i] * cos(curang + value), y[i] + r[i] * sin(curang + value)));
  if (!used[i][j]) v[whatcmp[i]].push_back(make_pair(x[i] + r[i] * cos(curang - value), y[i] + r[i] * sin(curang - value)));
  used[i][j] = used[j][i] = 1;
}

struct st {
  double a, b, c;
};

int cmp(st a, st b) {
  if (fabs(a.a - b.a) < eps) {
    if (fabs(a.b - b.b) < eps) {
      return a.c < b.c;
    } else
      return a.b < b.b;
  } else 
    return a.a < b.a;
}

int cmp2(pair<double, double>& a, pair<double, double>& b) {
  if (fabs(a.first - b.first) < eps2) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}

st tk[maxN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
    tk[i].a = x[i], tk[i].b = y[i], tk[i].c = r[i];
  }

  sort(tk, tk + n, cmp);

  if (n == 0) {
    printf("1\n");
    return 0;
  }

  int amount = 1;
  x[0] = tk[0].a, y[0] = tk[0].b, r[0] = tk[0].c;
  for (int i = 1; i < n; ++i) {
    if (fabs(tk[i].a - tk[i - 1].a) < eps && fabs(tk[i].b - tk[i - 1].b) < eps &&
      fabs(tk[i].c - tk[i - 1].c) < eps) {
        continue;
    } else {
      x[amount] = tk[i].a, y[amount] = tk[i].b, r[amount] = tk[i].c;
      ++amount;
    }
  }
  n = amount;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      g[j][i] = g[i][j] = check(i, j);
    }
  }

  memset(whatcmp, -1, sizeof(whatcmp));
  int numcmp = 0;
  for (int i = 0; i < n; ++i) {
    if (whatcmp[i] == -1) {
      dfs(i, numcmp);
      ++numcmp;
    }
  }

  for (int i = 0; i < n; ++i) {
    vector <double> ang;
    for (int j = 0; j < n; ++j) {
      if (g[i][j]) {
        update(ang, i, j);
      }
    }
    for (int i = 0; i < ang.size(); ++i) {
      while (ang[i] < -pi) ang[i] += 2 * pi;
      while (ang[i] > pi) ang[i] -= 2 * pi;
      if (fabs(ang[i] - pi) < eps1) ang[i] = -pi;
    }
    sort(ang.begin(), ang.end());
    if (ang.size() == 0) continue;
    int cnt = 1;
    for (int j = 1; j < ang.size(); ++j) {
      if (fabs(ang[j] - ang[j - 1]) > eps1) {
        ++cnt;
      }
    }
    edges[whatcmp[i]] += cnt;
  }

  for (int i = 0; i < numcmp; ++i) {
    sort(v[i].begin(), v[i].end(), cmp2);
    if (v[i].size() == 0) continue;
    int cnt = 1;
    for (int j = 1; j < v[i].size(); ++j) {
      if (fabs(v[i][j].first - v[i][j - 1].first) < eps2 &&
        fabs(v[i][j].second - v[i][j - 1].second) < eps2) {
          continue;
      } else {
        ++cnt;
      }
    }
    vertices[i] += cnt;
  }

  int result = 0;
  for (int i = 0; i < numcmp; ++i) {
    result += 2 - vertices[i] + edges[i];
  }
  result -= (numcmp - 1);
  printf("%d\n", result);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define M 510
#define ep 1e-9

typedef pair <int, int> PII;

char s[M][M];

int n, a[M][M], id[M * M];

int dx[] = {-1, -1, 0, 0};
int dy[] = {-1, 0, -1, 0};

double ang[M * M];

vector <PII> v;

PII con[M * M];

PII operator - (PII a, PII b) {
  return PII(a.first - b.first, a.second - b.second);
}

int operator ^ (PII a, PII b) {
  return a.first * b.second - a.second * b.first;
}

int dist(PII a) {
  return a.first * a.first + a.second * a.second;
}

bool cmp(int i, int j) {
  if (fabs(ang[i] - ang[j]) > ep) {
    return ang[i] > ang[j];
  }
  return dist(v[i] - v[0]) < dist(v[j] - v[0]);
}

int main() {
  //freopen("in.txt", "r", stdin);
  while (scanf("%d", &n) && n) {
    for (int i = n; i; i--) {
      scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) a[i][j] = s[i][j] - '0';
    }
    v.clear();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i][j] && a[i][j - 1] && a[i - 1][j - 1] && a[i - 1][j])
          v.push_back(PII(j - 1, i - 1));
      }
    }
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    int sz = v.size();
    id[0] = 0;
    for (int i = 1; i < sz; i++) id[i] = i, ang[i] = atan2(v[i].second - v[0].second, v[i].first - v[0].first);
    sort(id + 1, id + sz, cmp);
    int k = 0;
    for (int i = 0; i < v.size(); i++) {
      while (k > 1 && ((con[k - 1] - con[k - 2]) ^ (v[id[i]] - con[k - 2])) >= 0) k--;
      con[k++] = v[id[i]];
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
      printf("%d %d\n", con[i].first, con[i].second);
    }
  }
}
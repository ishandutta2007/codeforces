#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define M 1010
#define ep 1e-9

typedef pair <LL, LL> PII;

int n, m, id[M * M];

int dx[] = {-1, -1, 0, 0};
int dy[] = {-1, 0, -1, 0};

double ang[M * M];

vector <PII> v, in;

PII con[M * M];

PII operator - (PII a, PII b) {
  return PII(a.first - b.first, a.second - b.second);
}

LL operator ^ (PII a, PII b) {
  return a.first * b.second - a.second * b.first;
}

LL dist(PII a) {
  return a.first * a.first + a.second * a.second;
}

bool cmp(int i, int j) {
  if (fabs(ang[i] - ang[j]) > ep) {
    return ang[i] > ang[j];
  }
  return dist(v[i] - v[0]) < dist(v[j] - v[0]);
}

map <PII, bool> mp;

int main() {
  //freopen("in.txt", "r", stdin);
  int x, y;
  while (scanf("%d %d", &n, &m) && n) {
    in.clear(); v.clear(); mp.clear();
    int minx = n + 1, maxx = -1, miny, maxy;
    for (int i = 0; i < m; i++) {
      scanf("%d %d", &x, &y); in.push_back(PII(x, y));
      mp[PII(x, y)] = 1;
      if (minx > x || (minx == x && miny < y)) {
        minx = x; miny = y;
      }
      if (maxx < x || (maxx == x && maxy > y)) {
        maxx = x; maxy = y;
      }
    }

    PII lft = PII(minx, miny - 1);
    PII rgt = PII(maxx - 1, maxy);

    //printf("%d %d\n", lft.first, lft.second); printf("%d %d\n", rgt.first, rgt.second); puts("----");

    v.push_back(lft); v.push_back(rgt);

    for (int i = 0; i < m; i++) {
      for (int k = 0; k < 4; k++) {
        x = in[i].first + dx[k], y = in[i].second + dy[k];
        PII cur = PII(x, y);
        if (((cur - lft) ^ (rgt - lft)) > 0) {
          if (mp.count(cur) && mp.count(PII(cur.first + 1, cur.second))) {
            v.push_back(cur);
          }
        }
        else {
          if (mp.count(PII(cur.first, cur.second + 1)) && mp.count(PII(cur.first + 1, cur.second + 1))) {
            v.push_back(cur);
          }
        }
      }
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int sz = v.size();
    id[0] = 0;
    for (int i = 1; i < sz; i++)
      id[i] = i, ang[i] = atan2(v[i].second - v[0].second, v[i].first - v[0].first);
    sort(id + 1, id + sz, cmp);
    int k = 0;
    for (int i = 0; i < sz; i++) {
      while (k > 1 && ((con[k - 1] - con[k - 2]) ^ (v[id[i]] - con[k - 2])) >= 0) k--;
      con[k++] = v[id[i]];
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
      printf("%I64d %I64d\n", con[i].first, con[i].second);
    }
  }
}
#include <bits/stdc++.h>

using namespace std;

#define N 200100

typedef pair<int, int> pii;

vector <int> v[N], u[N];
vector <pii> vv[N], uu[N];
map <pii, bool> vis[4], mp;

int dx[] = {-1, -1, 1, 1};
int dy[] = {1, -1, 1, -1};

int n, m, k;

void ins(int x, int y) {
  mp[pii(x, y)] = true;
  v[x + y].push_back(x);
  u[x - y + m].push_back(x);
}

char tmp[10];

void dfs(int x, int y, int d) {
  vis[d][pii(x,y)] = true;
  int xx, yy, dd;
  if(d == 0) {
    int t = lower_bound(v[x + y].begin(), v[x + y].end(), x) - v[x + y].begin() - 1;
    xx = v[x + y][t] + 1; yy = x + y - xx;
    vv[x + y].push_back(pii(xx, x));
    if(mp.count(pii(xx - 1, yy))) {
      if(mp.count(pii(xx, yy + 1))) {
        dd = 3;
      } else {
        dd = 2; yy ++;
      }
    } else {
      if(mp.count(pii(xx, yy + 1))) {
        dd = 1; xx --;
      } else {
        dd = 3;
      }
    }
  } else if(d == 1) {
    int t = lower_bound(u[x - y + m].begin(), u[x - y + m].end(), x) - u[x - y + m].begin() - 1;
    xx = u[x - y + m][t] + 1; yy = xx - x + y;
    uu[x - y + m].push_back(pii(xx, x));
    if(mp.count(pii(xx - 1, yy))) {
      if(mp.count(pii(xx, yy - 1))) {
        dd = 2;
      } else {
        dd = 3; yy --;
      }
    } else {
      if(mp.count(pii(xx, yy - 1))) {
        dd = 0; xx --;
      } else {
        dd = 2;
      }
    }
  } else if(d == 2) {
    int t = lower_bound(u[x - y + m].begin(), u[x - y + m].end(), x) - u[x - y + m].begin();
    xx = u[x - y + m][t] - 1; yy = xx - x + y;
    uu[x - y + m].push_back(pii(x, xx));
    if(mp.count(pii(xx + 1, yy))) {
      if(mp.count(pii(xx, yy + 1))) {
        dd = 1;
      } else {
        dd = 0; yy ++;
      }
    } else {
      if(mp.count(pii(xx, yy + 1))) {
        dd = 3; xx ++;
      } else {
        dd = 1;
      }
    }
  } else {
    int t = lower_bound(v[x + y].begin(), v[x + y].end(), x) - v[x + y].begin();
    xx = v[x + y][t] - 1; yy = x + y - xx;
    vv[x + y].push_back(pii(x, xx));
    if(mp.count(pii(xx + 1, yy))) {
      if(mp.count(pii(xx, yy - 1))) {
        dd = 0;
      } else {
        dd = 1; yy --;
      }
    } else {
      if(mp.count(pii(xx, yy - 1))) {
        dd = 2; xx ++;
      } else {
        dd = 0;
      }
    }
  }
  if(vis[dd].count(pii(xx, yy))) return;
  dfs(xx, yy, dd);
}

bool ok(pii x, pii y) {
  if(x.first <= y.first && y.second <= x.second) return 1;
  if(y.first <= x.first && x.second <= y.second) return 1;
  return 0;
}

void run() {
  int x, y, d;
  scanf("%d%d%s", &x, &y, tmp);
  if(!strcmp(tmp, "NE")) d = 0;
  if(!strcmp(tmp, "NW")) d = 1;
  if(!strcmp(tmp, "SE")) d = 2;
  if(!strcmp(tmp, "SW")) d = 3;
  dfs(x, y, d);
  long long ans = 0;
  for(int i = 0; i <= n + m; i ++) {
    if((int)uu[i].size()) {
      sort(uu[i].begin(), uu[i].end());
      int tp = 0;
      int sz = (int)uu[i].size();
      for(int j = 0; j < sz; j ++) {
        tp = max(tp, uu[i][j].second - uu[i][j].first + 1);
        if(j < sz - 1 && ok(uu[i][j], uu[i][j+1])) continue;
        ans += tp;
        tp = 0;
      }
    }
    if((int)vv[i].size()) {
      sort(vv[i].begin(), vv[i].end());
      int tp = 0;
      int sz = (int)vv[i].size();
      for(int j = 0; j < sz; j ++) {
        tp = max(tp, vv[i][j].second - vv[i][j].first + 1);
        if(j < sz - 1 && ok(vv[i][j], vv[i][j+1])) continue;
        ans += tp;
        tp = 0;
      }
    }
  }
  printf("%I64d\n", ans);
}

int main() {
//  freopen("in.txt", "r", stdin);
  scanf("%d%d%d", &n, &m, &k);
  n ++; m ++;
  for(int i = 0; i <= n; i ++) {
    ins(i, 0); ins(i, m);
  }
  for(int i = 1; i < m; i ++) {
    ins(0, i); ins(n, i);
  }
  for(int i = 0; i < k; i ++) {
    int x, y;
    scanf("%d%d", &x, &y); ins(x, y);
  }
  for(int i = 0; i <= n + m; i ++) {
    if((int)u[i].size()) sort(u[i].begin(), u[i].end());
    if((int)v[i].size()) sort(v[i].begin(), v[i].end());
  }
  run();
  return 0;
}
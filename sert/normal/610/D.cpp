#include <bits/stdc++.h>
using namespace std;

const int N = (int)2.5e7;
int cnt = 0;
typedef long long ll;

int sum[N], lft[N];

inline int nw(int x = 0) {  
  sum[cnt] = x;
  lft[cnt] = -1;
  return cnt++;
}

const int INF = (int)1e9 + 41;

void add(int v, int l, int r, int pos, int x) {
  if (l + 1 == r) {
    // cout << "set " << x << " to " << l << endl;
    sum[v] += x;
    return;
  }
  int m = (l + r) / 2;
  if (lft[v] == -1) {
    lft[v] = nw(0);
    nw(0);
  }

  if (pos < m)
    add(lft[v], l, m, pos, x);
  else
    add(lft[v] + 1, m, r, pos, x);
  sum[v] = sum[lft[v]] + sum[lft[v] + 1];  
}

ll getSum(int v, int l, int r, int L, int R) {    
  if (L <= l && r <= R) {    
    return sum[v];
  }
  if (L >= r || l >= R || lft[v] == -1) return 0;  
  int m = (l + r) / 2;  
  return getSum(lft[v], l, m, L, R) + getSum(lft[v] + 1, m, r, L, R);
}

vector<pair<int, int>> cntU(const vector<pair<int, int>> &v) {
  vector<pair<int, int>> e;
  for (const auto &p : v) {
    e.emplace_back(p.first, 1);
    e.emplace_back(p.second + 1, -1);
  }
  sort(e.begin(), e.end());
  int bal = 1;  
  vector<pair<int, int>> u;
  int beg = e[0].first;
  for (int i = 1; i < (int)e.size(); i++) {
    bal += e[i].second;
    if (bal == 0) u.emplace_back(beg, e[i].first);
    if (bal == 1 && e[i].second == 1) beg = e[i].first;
  }
  return u;
}

ll solve(const vector<vector<int>> &w = {}) {
  cnt = 0;
  int n;
  if (w.empty()) cin >> n;
  else n = w.size();
  int x1, y1, x2, y2;

  vector<pair<int, pair<int, int>>> e;  

  map<int, vector<pair<int, int>>> hor, vert;

  for (int i = 0; i < n; i++) {
    if (w.empty()) cin >> x1 >> y1 >> x2 >> y2;
    else {
      x1 = w[i][0];
      y1 = w[i][1];
      x2 = w[i][2];
      y2 = w[i][3];
    }
    if (x1 > x2 || y1 > y2) {
      swap(x1, x2);
      swap(y1, y2);
    }
    if (x1 == x2) {
      vert[x1].emplace_back(y1, y2);      
    } else {
      hor[y1].emplace_back(x1, x2);      
    }
  }

  ll sum = 0;
  for (const auto &it : hor) {
    auto u = cntU(it.second);
    int y = it.first;
    for (const auto &[x1, x2] : u) {
      sum += x2 - x1;
      e.push_back(make_pair(x1, make_pair(-INF, y)));
      e.push_back(make_pair(x2 - 1, make_pair(INF, y)));
    }
  }  

  for (const auto &it : vert) {
    auto u = cntU(it.second);
    int x = it.first;
    for (const auto &[y1, y2] : u) {
      sum += y2 - y1;
      e.push_back(make_pair(x, make_pair(y1, y2)));
    }
  }  

  int root = nw(0);  
  sort(e.begin(), e.end());

  for (const auto &ev : e) {
    int a = ev.second.first;
    int b = ev.second.second;

    //cout << ev.first << " " << a << " " << b << endl;

    if (a == -INF) {      
      add(root, -INF, INF, b, 1);
    } else if (a == INF) {
      add(root, -INF, INF, b, -1);
    } else {
      int k = getSum(root, -INF, INF, a, b);
      sum -= k;
      // cout << "k = " << k << endl;
    }
  }

  if (w.empty())
    cout << sum << endl;  
  return sum;
}

ll kek(const vector<vector<int>> &w) {
  set<pair<int, int>> s;
  for (const auto &v : w) {
    int x1 = v[0], y1 = v[1], x2 = v[2], y2 = v[3];
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    for (int i = y1; i <= y2; i++) {
      for (int j = x1; j <= x2; j++)
        s.insert(make_pair(j, i));
    }
  }
  return s.size();
}

void test(int n, int md, int nn) {
  vector<vector<int>> w;
  for (int i = 0; i < n; i++) {
    w.emplace_back();
    for (int j = 0; j < 4; j++) {
      w.back().push_back(rand() % md);
    }
    if (rand() % 2) w.back()[0] = w.back()[2];
    else w.back()[1] = w.back()[3];
  }

  ll a1 = kek(w);
  ll a2 = solve(w);

  if (a1 != a2) {
    cout << "test: " << nn << endl;
    for (auto v : w) {
      for (int x : v) cout << x << " ";
      cout << "\n";
    }
    cout << "kek: " << a1 << "\n";
    cout << "sol: " << a2 << "\n";
    exit(0);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
  for (int i = 0; i < 10000; i++) {
    test(10, 7, i);
  }
}
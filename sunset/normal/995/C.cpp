#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll limit = 1000000000000;

struct point_t {
  int x, y;

  point_t(int x = 0, int y = 0):x(x), y(y) {
  }

  point_t operator + (const point_t &b) const {
    return point_t(x + b.x, y + b.y);
  }
  
  point_t operator - (const point_t &b) const {
    return point_t(x - b.x, y - b.y);
  }

  ll length() {
    return (ll)x * x + (ll)y * y;
  }
};

void dfs(int x, vector<pair<pair<int, int>, pair<int, int>>> &parent, vector<int> &answer) {
  if (parent[x] == make_pair(make_pair(-1, -1), make_pair(-1, -1))) {
    return;
  }
  pair<int, int> p;
  p = parent[x].first;
  answer[p.first] = answer[x] * p.second;
  dfs(p.first, parent, answer);
  p = parent[x].second;
  answer[p.first] = answer[x] * p.second;
  dfs(p.first, parent, answer);
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  if (n == 1) {
    puts("1");
    return 0;
  }
  vector<pair<pair<int, int>, pair<int, int>>> parent(n);
  vector<point_t> p(n);
  vector<int> current(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i].x, &p[i].y);
    parent[i] = make_pair(make_pair(-1, -1), make_pair(-1, -1));
    current[i] = i;
  }
  while (current.size() > 2) {
    vector<int> temp(3);
    for (int i = 0; i < 3; ++i) {
      temp[i] = current.back();
      current.pop_back();
    }
    bool flag = true;
    for (int i = 0; i < 3 && flag; ++i) {
      for (int j = 0; j < i && flag; ++j) {
        point_t q;
        q = p[temp[i]] + p[temp[j]];
        if (q.length() <= limit) {
          p.push_back(q);
          parent.push_back(make_pair(make_pair(temp[i], 1), make_pair(temp[j], 1)));
          current.push_back(p.size() - 1);
          current.push_back(temp[3 - i - j]);
          flag = false;
          continue;
        }
        q = p[temp[i]] - p[temp[j]];
        if (q.length() <= limit) {
          p.push_back(q);
          parent.push_back(make_pair(make_pair(temp[i], 1), make_pair(temp[j], -1)));
          current.push_back(p.size() - 1);
          current.push_back(temp[3 - i - j]);
          flag = false;
          continue;
        }
      }
    }
  }
  vector<int> answer(p.size());
  point_t q = p[current[0]] + p[current[1]];
  if (q.length() <= 2 * limit) {
    answer[current[0]] = 1;
    answer[current[1]] = 1;
  } else {
    answer[current[0]] = 1;
    answer[current[1]] = -1;
  }
  dfs(current[0], parent, answer);
  dfs(current[1], parent, answer);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", answer[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
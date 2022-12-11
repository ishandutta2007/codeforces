#include <vector>
#include <iostream>
#include <utility>
using namespace std;

#ifdef SERT
  bool D = true;
#else
  bool D = false;
#endif

struct pt {
  int x, y;
  pt(int x = 0, int y = 0): x(x), y(y) {}
  pt operator-(const pt &a) const { return pt(x - a.x, y - a.y); }
  bool operator==(const pt &a) const { return x == a.x && y == a.y; }
  bool operator<(const pt &a) const { return x < a.x || (x == a.x && y < a.y); }
  int len() const { return abs(x) + abs(y); }
};

pt P1, P2;
int n, m;

vector<pair<pt, int>> q;

void init() {
  q.clear();
  if (D) {
    n = rand() % 15 + 2;
    m = rand() % 15 + 2;
    P1 = pt(rand() % m + 1, rand() % n + 1);
    P2 = P1;
    while (P1 == P2) {
      P2 = pt(rand() % m + 1, rand() % n + 1);
    }
  } else {
    cin >> n >> m;
  }
}

bool check(const pt &p) {
  if (D) {
    return (p == P1 || p == P2);
  } else {
    cout << "DIG " << p.y << " " << p.x << endl;
    int res;
    cin >> res;
    return res;
  }
}

int getDist(const pt &p) {
  int ans = 0;
  if (D) {
    ans = (p - P1).len() + (p - P2).len();
  } else {
    cout << "SCAN " << p.y << " " << p.x << endl;
    int res;
    cin >> res;
    ans = res;
  }
  q.emplace_back(p, ans);
  return ans;
}

void solve() {
  init();
  int sumAll = getDist(pt(1, 1)) + 4;
  int sumDif = getDist(pt(1, n)) + 2 - 2 * n;
  int sumX = (sumAll + sumDif) / 2;
  int sumY = (sumAll - sumDif) / 2;

  getDist({sumX / 2, 1});
  getDist({1, sumY / 2});

  vector<pair<pt, pt>> candidates;
  vector<pt> points;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      points.push_back(pt(j, i));
  for (int i = 0; i < (int)points.size(); i++) {
    for (int j = i + 1; j < (int)points.size(); j++) {
      auto p1 = points[i];
      auto p2 = points[j];
      bool ok = true;
      for (auto &[p, sum] : q) {
        ok &= ((p - p1).len() + (p - p2).len() == sum);
      }
      if (ok) {
        candidates.emplace_back(p1, p2);
      }
    }
  }

  if (candidates.size() > 2 || candidates.empty()) {
    cout << "candidates size is " << candidates.size() << endl;
    exit(11);
  }

  for (const auto &[p1, p2] : candidates) {
    if (!check(p1)) continue;
    if (!check(p2)) {
      cout << "2nd point didnt match" << endl;
      exit(12);
    }
    return;
  }
  cout << "no pair matches" << endl;
  exit(13);
}

int main() {
  int t;
  if (D) t = 10000;
  else cin >> t;
  while (t--) {
    solve();
  }
  if (D) cout << "all is ok\n";
}
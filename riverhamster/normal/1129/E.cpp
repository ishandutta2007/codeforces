#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int N = 505;
pair<int, int> p[N];
vector<pair<int, int> > res;
set<int> s;
int sz[N];

int find_child(int x) {
  int L = 1, R = s.size(), M;
  while (L < R) {
    M = (L + R) >> 1;
    int cnt = 0;
    cout << "1\n1\n";
    cout << M << '\n';
    for (int x : s) {
      ++cnt;
      cout << x << ' ';
      if (cnt == M) break;
    }
    cout << '\n';
    cout << x << endl;
    int rep;
    cin >> rep;
    if (rep == 0) L = M + 1;
    else R = M;
  }
  L = *next(s.begin(), L - 1);
  res.emplace_back(L, x);
  s.erase(L);
  return sz[L];
}

int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    cout << "1\n1\n";
    cout << n - 1 << "\n";
    for (int i = 2; i <= n; ++i) cout << i << ' ';
    cout << '\n';
    cout << i << endl;
    cin >> p[i].first;
    sz[i] = p[i].first;
    p[i].second = i;
  }
  p[1] = {n, 1}; sz[1] = n;
  sort(p + 1, p + 1 + n);
  for (int i = 1; i < n; ++i) {
    int sz = p[i].first;
    while (sz != 1) sz -= find_child(p[i].second);
    s.insert(p[i].second);
  }
  for (int x : s)
    res.emplace_back(1, x);
  cout << "ANSWER\n";
  for (const auto &p : res)
    cout << p.first << ' ' << p.second << '\n';
  cout << flush;
  return 0;
}
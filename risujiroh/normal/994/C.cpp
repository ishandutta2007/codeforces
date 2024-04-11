#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using P = pair<int, int>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  vector<P> s1(4), s2(4);
  for (int i = 0; i < 4; i++) {
    int x, y; cin >> x >> y;
    s1[i] = P(x + 100, y + 100);
  }
  for (int i = 0; i < 4; i++) {
    int x, y; cin >> x >> y;
    s2[i] = P(x + 100, y + 100);
  }
  sort(s1.begin(), s1.end());
  int l = s1[0].first, r = s1[3].first;
  sort(s1.begin(), s1.end(), [](auto a, auto b) { return a.second < b.second; });
  int d = s1[0].second, u = s1[3].second;
  auto in1 = [&](int i, int j) {
    return (l <= i and i <= r and d <= j and j <= u);
  };
  sort(s2.begin(), s2.end(), [](auto a, auto b) { return a.first + a.second < b.first + b.second; });
  int ld = s2[0].first + s2[0].second, ru = s2[3].first + s2[3].second;
  sort(s2.begin(), s2.end(), [](auto a, auto b) { return a.second - a.first < b.second - b.first; });
  int rd = s2[0].second - s2[0].first, lu = s2[3].second - s2[3].first;
  auto in2 = [&](int i, int j) {
    return (ld <= i + j and i + j <= ru and rd <= j - i and j - i <= lu);
  };
  bool f = false;
  for (int i = 0; i < 201; i++) {
    for (int j = 0; j < 201; j++) {
      if (in1(i, j) and in2(i, j)) f = true;
    }
  }
  cout << (f ? "YES" : "NO") << '\n';
  return 0;
}
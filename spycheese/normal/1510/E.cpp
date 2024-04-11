#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef pair<int, int> ipair;

int n;
double cx, cy;
map<ipair, int> d1[20][327];

void go1(int len, int bal, int mask, int w, int sx, int sy) {
  if (len == n / 2) {
    d1[bal][w][{sx, sy}] = mask;
    return;
  }
  go1(len + 1, bal + 1, mask | (1 << len), w + bal * 2 + 1,
      sx + 3 * (2 * len + 1) * bal + (3 * len + 2),
      sy + 3 * 2 * bal * bal / 2 + (3 * bal + 1));
  if (bal == 0) return;
  go1(len + 1, bal - 1, mask, w + bal * 2 - 1,
      sx + 3 * (2 * len + 1) * bal - (3 * len + 2),
      sy + 3 * 2 * bal * bal / 2 - (3 * bal - 1));
}

int gmask1, gmask2;
double best = 1e9;

void go2(int len, int bal, int mask, int w, int sx, int sy) {
  if (len == n / 2) {
    sx = w * 3 * n - sx;
    for (int w1 = w % 2; w1 < 327; w1 += 2) {
      if (w1 == 0) continue;
      double dsx1 = cx * (w + w1) - sx;
      int sx1 = round(dsx1);
      double cur = abs(sx1 - dsx1);
      double dsy1 = cy * (w + w1) - sy;
      int sy1 = round(dsy1);
      cur = max(cur, abs(sy1 - dsy1));
      auto it = d1[bal][w1].find({sx1, sy1});
      if (it == d1[bal][w1].end()) continue;
      int mask1 = it->second;
      if (best > cur) {
        best = cur;
        gmask1 = mask1;
        gmask2 = mask;
      }
    }
    return;
  }
  go2(len + 1, bal + 1, mask | (1 << len), w + bal * 2 + 1,
      sx + 3 * (2 * len + 1) * bal + (3 * len + 2),
      sy + 3 * 2 * bal * bal / 2 + (3 * bal + 1));
  if (bal == 0) return;
  go2(len + 1, bal - 1, mask, w + bal * 2 - 1,
      sx + 3 * (2 * len + 1) * bal - (3 * len + 2),
      sy + 3 * 2 * bal * bal / 2 - (3 * bal - 1));
}

int main() {
  cin >> n >> cx >> cy;
  cx *= 3;
  cy *= 3;
  assert(n % 2 == 0);

  go1(0, 0, 0, 0, 0, 0);
  go2(0, 0, 0, 0, 0, 0);

  for (int i = 0; i < n / 2; ++i)
    cout << ")("[!!(gmask1 & (1 << i))];
  for (int i = 0; i < n / 2; ++i)
    cout << "()"[!!(gmask2 & (1 << (n / 2 - 1 - i)))];
  cout << "\n";
}
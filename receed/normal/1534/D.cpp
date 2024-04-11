#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 2003;
int d[N], dd[N], s[2];
set<pair<int, int>> e;
int n;

void q(int r) {
  cout << "? " << r + 1 << endl;
  rep(i, n) {
    cin >> d[i];
    if (d[i] == 1)
      e.insert({min(i, r), max(i, r)});
  }
}

int main() {
  cin >> n;
  q(0);
  for (int i = 1; i < n; ++i) {
    dd[i] = d[i];
    s[d[i] % 2]++;
  }
  int x = s[0] < s[1] ? 0 : 1;
  for (int i = 1; i < n; ++i)
    if (dd[i] % 2 == x)
      q(i);
  cout << "!" << endl;
  for (auto &pp : e)
    cout << pp.first + 1 << ' ' << pp.second + 1 << endl;
}
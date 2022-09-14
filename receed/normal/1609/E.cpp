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

struct f {
  int a = 0, b = 0, c = 0, ab = 0, bc = 0, abc = 0;
};

const int N = 1 << 17;
f tr[N * 2];

f operator+(f x, f y) {
  return {x.a + y.a, x.b + y.b, x.c + y.c, min(x.a + y.ab, x.ab + y.b), min(x.b + y.bc, x.bc + y.c), min(min(x.a + y.abc, x.ab + y.bc), x.abc + y.c)};
}

void setc(int v, char c) {
  tr[N + v] = f();
  if (c == 'a')
    tr[N + v].a = 1;
  else if (c == 'b')
    tr[N + v].b = 1;
  else if (c == 'c')
    tr[N + v].c = 1;
  for (int i = (N + v) / 2; i; i /= 2)
    tr[i] = tr[i * 2] + tr[i * 2 + 1];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  rep(i, n)
    setc(i, s[i]);
  rep(i, q) {
    int pos;
    char c;
    cin >> pos >> c;
    setc(pos - 1, c);
    cout << tr[1].abc << '\n';
  }
}
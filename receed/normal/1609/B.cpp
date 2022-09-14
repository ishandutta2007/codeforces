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

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  string s, t = "abc";
  cin >> n >> q >> s;
  int k = 0;
  rep(i, n - 2)
    if (s.substr(i, 3) == t)
      k++;
  rep(z, q) {
    int pos;
    char c;
    cin >> pos >> c;
    pos--;
    for (int i = max(pos - 2, 0); i < min(n - 2, pos + 1); i++)
      if (s.substr(i, 3) == t)
        k--;
    s[pos] = c;
    for (int i = max(pos - 2, 0); i < min(n - 2, pos + 1); i++)
      if (s.substr(i, 3) == t)
        k++;
    cout << k << '\n';
  }
}
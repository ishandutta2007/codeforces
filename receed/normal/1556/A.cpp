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
  ll t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a == 0 && b == 0)
      cout << "0\n";
    else if (a == b && a > 0 || a == -b)
      cout << "1\n";
    else if (a + b > 0 && (a + b) % 2 == 0)
      cout << "2\n";
    else
      cout << "-1\n";
  }
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int x = (2 * n + 1) / 3;
  int r = (2 * n + 1) % 3;
  cout << x << '\n';
  if (n == 1) {
    cout << "1 1\n";
    exit(0);
  }
  if (r == 2) {
    cout << x << ' ' << x << '\n';
    int a = 1, b = 2;
    for (int _ = 0; _ < (x - 1) / 2; _++) {
      cout << a << ' ' << b << '\n';
      a++;
      b += 2;
    }
    a = (x - 1) / 2 + 1;
    b = 1;
    for (int _ = 0; _ < (x - 1) / 2; _++) {
      cout << a << ' ' << b << '\n';
      a++;
      b += 2;
    }
  } else if (r == 1) {
    cout << x - 1 << ' ' << x - 1 << '\n';
    cout << x << ' ' << x << '\n';
    int a = 1, b = 2;
    for (int _ = 0; _ < (x - 2) / 2; _++) {
      cout << a << ' ' << b << '\n';
      a++;
      b += 2;
    }
    a = (x - 2) / 2 + 1;
    b = 1;
    for (int _ = 0; _ < (x - 2) / 2; _++) {
      cout << a << ' ' << b << '\n';
      a++;
      b += 2;
    }
  } else {
    cout << x - 2 << ' ' << x - 2 << '\n';
    cout << x - 1 << ' ' << x - 1 << '\n';
    cout << x << ' ' << x << '\n';
    int a = 1, b = 2;
    for (int _ = 0; _ < (x - 3) / 2; _++) {
      cout << a << ' ' << b << '\n';
      a++;
      b += 2;
    }
    a = (x - 1) / 2;
    b = 1;
    for (int _ = 0; _ < (x - 3) / 2; _++) {
      cout << a << ' ' << b << '\n';
      a++;
      b += 2;
    }
  }
}
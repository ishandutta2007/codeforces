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

int q(int x) {
  cout << "? " << x << endl;
  int r;
  cin >> r;
  return r;
}

int main() {
  int n;
  cin >> n;
  int l = 1, r = n, m;
  while (l != r) {
    m = (l + r) / 2;
    int x = q(m), y = q(m + 1);
    if (x < y)
      r = m;
    else
      l = m + 1;
  }
  cout << "! " << l << endl;
}
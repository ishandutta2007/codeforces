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

const int MOD = 998244353;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  vector<ll> d(n + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; j += i)
      d[j]++;
  ll cd = 0, cs = 0;
  for (int i = 1; i <= n; ++i) {
    cd = (cs + d[i]) % MOD;
    cs = (cs + cd) % MOD;
  }
  cout << cd;
}
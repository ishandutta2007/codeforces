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
  ll t, n, m, x, y;
  cin >> t;
  rep(z, t) {
    cin >> n >> m >> x;
    vector<ll> s(m);
    set<pair<ll, ll>> q;
    rep(i, m)
      q.insert({s[i], i});
    cout << "YES\n";
    rep(i, n) {
      cin >> y;
      int v = q.begin()->second;
      q.erase(q.begin());
      cout << v + 1 << ' ';
      s[v] += y;
      q.insert({s[v], v});
    }
    cout << '\n';
  }
}
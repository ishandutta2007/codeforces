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

const int N = 1001;
int p[N], sz[N];

void merge(int u, int v) {
  if (p[u] == p[v])
    return;
  sz[p[v]] += sz[p[u]];
  p[p[u]] = p[v];
}

int getp(int v) {
  if (p[v] != v)
    p[v] = getp(p[v]);
  return p[v];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  multiset<int> ms;
  rep(i, n + 1) {
    sz[i] = 1;
    p[i] = i;
    ms.insert(1);
  }
  int odd = 0;
  rep(i, d) {
    int x, y;
    cin >> x >> y;
    x = getp(x);
    y = getp(y);
    if (x == y)
      odd++;
    else {
      ms.erase(ms.find(sz[x]));
      ms.erase(ms.find(sz[y]));
      ms.insert(sz[x] + sz[y]);
      merge(x, y);
    }
    ll ans = 0, co = odd + 1;
    for (auto it = ms.rbegin(); it != ms.rend(); ++it) {
      if (co == 0)
        break;
      ans += *it;
      co--;
    }
    cout << ans - 1<< '\n';
  }
}
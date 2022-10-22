#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

set<pair<int, int>> edges;

int main(){
  int n;
  cin >> n;

  cout << "? 1" << endl;

  vector <pair <int, int>> d;
  int odd = 0, even = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 0) {
      continue;
    }
    if (x % 2) {
      ++odd;
    } else {
      ++even;
    }
    d.pb({x, i});
  }
  sort(all(d));

  vector<bool> used(n, false);
  used[0] = true;
  vector <int> order;

  bool ud = false;
  if (odd > even) {
    ud = true;
  }

  for (int i = 0; i < n - 1; ++i) {
    if (d[i].x == 1) {
      edges.insert({0, d[i].y});
      used[d[i].y] = true;
    }
    if (d[i].x % 2 && odd < even) {
      order.pb(d[i].y);
    } else if (d[i].x % 2 == 0 && even <= odd) {
      order.pb(d[i].y);
    }
  }
  assert(order.size() == min(odd, even));

  for (int v : order) {
    cout << "? " << v + 1 << endl;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x != 1) continue;
        edges.insert({min(v, i), max(v, i)});
        used[i] = true;
    }
    used[v] = true;
  }

  cout << "!" << endl;
  assert(edges.size() == n - 1);
  for (auto [v, u] : edges) {
    cout << v + 1 << " " << u + 1 << endl;
  }

}
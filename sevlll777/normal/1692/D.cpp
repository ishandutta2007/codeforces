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
// #define int long long
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

bool pal(string a) {
  string b = a;
  reverse(all(b));
  return (a == b);
}

string inc(string a) {
  if (a[4] != '9') {
    a[4]++;
    return a;
  }
  if (a[3] != '5') {
    a[3]++;
    a[4] = '0';
    return a;
  }
  if (a[0] == '2' && a[1] == '3') {
    return "00:00";
  } else if (a[1] != '9') {
    a[1]++;
    a[3] = '0';
    a[4] = '0';
    return a;
  } else {
    a[0]++;
    a[1] = '0';
    a[3] = '0';
    a[4] = '0';
    return a;
  }
}

void solve() {
  string s;
  int x;
  cin >> s >> x;
  vector<string> kek = {s};
  string t = s;
  s = inc(s);
  while (s != t) {
    kek.pb(s);
    s = inc(s);
  }
  int cr = 0;
  s = kek[cr];
  int ans = 0;
  while (true) {
    cr += x;
    cr %= kek.size();
    s = kek[cr];
    if (pal(s)) {
      ans++;
    }
    if (s == t) break;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
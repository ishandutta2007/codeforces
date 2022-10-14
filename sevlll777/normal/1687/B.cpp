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
  int n, m;
  cin >> n >> m;
  vector<int> w(m);
  for (int i = 0; i < m; i++) {
    string s = "";
    for (int _ = 0; _ < m; _++) s += '0';
    s[i] = '1';
    cout << "? " << s << endl;
    cin >> w[i];
  }
  vector<pair<int, int>> pw;
  for (int i = 0; i < m; i++) {
    pw.pb({w[i], i});
  }
  sort(all(pw));
  int ans = 0;
  string s = "";
  for (int _ = 0; _ < m; _++) s += '0';
  int lst = 0;
  for (int i = 0; i < m; i++) {
    s[pw[i].second] = '1';
    cout << "? " << s << endl;
    int l2;
    cin >> l2;
    int dif = l2 - lst;
    if (dif == pw[i].first) {
      lst = l2;
      ans += pw[i].first;
    } else {
      s[pw[i].second] = '0';
    }
  }
  cout << "! " << ans << endl;
}
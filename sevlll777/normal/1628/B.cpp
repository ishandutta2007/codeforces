#include <iostream>
#include <iomanip>
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
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define ld long double
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < n; i++) {
    if (S[i].size() == 1) {
      cout << "YES\n";
      return;
    }
  }
  set<string> s2, s3;
  for (int i = 0; i < n; i++) {
    if (S[i].size() == 3) {
      string s1 = S[i];
      reverse(all(s1));
      if (s3.find(s1) != s3.end()) {
        cout << "YES\n";
        return;
      }
      string s0 = "";
      s0 += S[i][2];
      s0 += S[i][1];
      if (s2.find(s0) != s2.end()) {
        cout << "YES\n";
        return;
      }
      s3.insert(S[i]);
    } else if (S[i].size() == 2) {
      string s1 = S[i];
      reverse(all(s1));
      if (s2.find(s1) != s2.end()) {
        cout << "YES\n";
        return;
      }
      s2.insert(S[i]);
    }
  }
  s2 = {};
  s3 = {};
  reverse(all(S));
  for (int i = 0; i < n; i++) {
    if (S[i].size() == 3) {
      string s1 = S[i];
      reverse(all(s1));
      if (s3.find(s1) != s3.end()) {
        cout << "YES\n";
        return;
      }
      string s0 = "";
      s0 += S[i][1];
      s0 += S[i][0];
      if (s2.find(s0) != s2.end()) {
        cout << "YES\n";
        return;
      }
      s3.insert(S[i]);
    } else if (S[i].size() == 2) {
      s2.insert(S[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    string s1 = S[i];
    reverse(all(s1));
    if (s1 == S[i]) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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
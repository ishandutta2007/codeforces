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
  int t, n;
  cin >> t;
  while (t--) {
    string s;
    cin >> n >> s;
    int p = 0;
    if (s.size() == 1 || s[0] == s[1]) {
      cout << s[0] << s[0] << '\n';
    } else {
      while (p + 1 < s.size() && s[p] >= s[p + 1])
        p++;
      s = s.substr(0, p + 1);
      cout << s;
      reverse(all(s));
      cout << s << '\n';
    }
  }
}
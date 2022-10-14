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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = (int) s.size();
  sort(all(s));
  if (s[0] == s.back()) {
    cout << s << '\n';
    return;
  }
  vector<int> cnt(26);
  for (auto c : s) {
    cnt[c - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] == 1) {
      cout << (char) ('a' + i);
      for (auto c : s) {
        if (c - 'a' != i) {
          cout << c;
        }
      }
      cout << '\n';
      return;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (((n - 2) / 2) + 2 >= cnt[i] && cnt[i] != 0) {
      string s2;
      for (auto x : s) {
        if (x - 'a' != i) {
          s2 += x;
        }
      }
      sort(all(s2));
      string ans;
      char c = (char) ('a' + i);
      ans += c;
      ans += c;
      for (int _ = 0; _ < cnt[i] - 2; _++) {
        ans += s2[_];
        ans += c;
      }
      for (int _ = cnt[i] - 2; _ < (int) s2.size(); _++) {
        ans += s2[_];
      }
      cout << ans << '\n';
      return;
    } else if (cnt[i] != 0) {
      break;
    }
  }
  int dif = 0;
  for (int i = 0; i < 26; i++) {
    dif += (cnt[i] > 0);
  }
  if (dif == 2) {
    char c1, c2;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] != 0) {
        if (cnt1 == 0) {
          c1 = (char) ('a' + i);
          cnt1 = cnt[i];
        } else if (cnt2 == 0) {
          c2 = (char) ('a' + i);
          cnt2 = cnt[i];
        }
      }
    }
    string ans;
    ans += c1;
    for (int _ = 0; _ < cnt2; _++) ans += c2;
    for (int _ = 0; _ < cnt1 - 1; _++) ans += c1;
    cout << ans << '\n';
  } else {
    char c1, c2, c3;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] != 0) {
        if (cnt1 == 0) {
          c1 = (char) ('a' + i);
          cnt1 = cnt[i];
        } else if (cnt2 == 0) {
          c2 = (char) ('a' + i);
          cnt2 = cnt[i];
        } else if (cnt3 == 0) {
          c3 = (char) ('a' + i);
          cnt3 = cnt[i];
        }
      }
    }
    string ans;
    ans += c1;
    cnt[c1 - 'a']--;
    ans += c2;
    cnt[c2 - 'a']--;
    for (int _ = 0; _ < cnt[c1 - 'a']; _++) {
      ans += c1;
    }
    cnt[c1 - 'a'] = 0;
    ans += c3;
    cnt[c3 - 'a']--;
    string ss;
    for (int i = 0; i < 26; i++) {
      for (int _ = 0; _ < cnt[i]; _++) {
        ss += (char) ('a' + i);
      }
    }
    sort(all(ss));
    cout << ans << ss << '\n';
  }

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
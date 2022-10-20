#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  long long k;
  cin >> n >> k;
  map<int, int> mp;
  while (n--) {
    int a;
    cin >> a;
    ++mp[a];
  }
  while (k) {
    if (mp.size() == 1) {
      break;
    }
    if (begin(mp)->second < rbegin(mp)->second) {
      long long d = next(begin(mp))->first - begin(mp)->first;
      if (d * begin(mp)->second > k) {
        int x = k / begin(mp)->second;
        if (x) {
          mp[begin(mp)->first + x] += begin(mp)->second;
          mp.erase(begin(mp));
        }
        break;
      } else {
        k -= d * begin(mp)->second;
        mp[next(begin(mp))->first] += begin(mp)->second;
        mp.erase(begin(mp));
      }
    } else {
      long long d = rbegin(mp)->first - next(rbegin(mp))->first;
      if (d * rbegin(mp)->second > k) {
        int x = k / rbegin(mp)->second;
        if (x) {
          mp[rbegin(mp)->first - x] += rbegin(mp)->second;
          mp.erase(rbegin(mp)->first);
        }
        break;
      } else {
        k -= d * rbegin(mp)->second;
        mp[next(rbegin(mp))->first] += rbegin(mp)->second;
        mp.erase(rbegin(mp)->first);
      }
    }
  }
  int res = rbegin(mp)->first - begin(mp)->first;
  cout << res << '\n';
}
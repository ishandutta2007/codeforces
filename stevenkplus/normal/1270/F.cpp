#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;

const int MAXN = 200100;
const int RT = 100;
int buf[MAXN * RT];
int *mp = buf + MAXN;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  ll ans = 0;
  for(int r = 1; r < RT; ++r) {
    // weights: 0: -1, 1 -> r-1
    int sum = 0;
    ++mp[0];
    for(int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        sum -= 1;
      } else {
        sum += r - 1;
      }
      ans += mp[sum];
      ++mp[sum];
    }

    sum = 0;
    --mp[0];
    for(int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        sum -= 1;
      } else {
        sum += r - 1;
      }
      --mp[sum];
    }
  }
  vector<int> pos;
  for(int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      pos.push_back(i);
    }
  }
  for(int c = 1; c <= n; ++c) {
    if (c * RT > n) {
      break;
    }
    for(int i = 0; i + c <= pos.size(); i += 1) {
      int l1 = i > 0 ? pos[i - 1] + 1 : 0;
      int l2 = pos[i] + 1;
      int r1 = pos[i + c - 1] + 1;
      int r2 = i + c < pos.size() ? pos[i + c] + 1 : n + 1;
      // count multiples of c that are >= c * RT
      for(int j = l1; j < l2; ++j) {
        int r = max(j + c * RT, r1 + (c + (j - r1) % c) % c);
        ans += max(0, (r2 - r + c - 1) / c);
      }
    }
  }
  cout << ans << "\n";
}
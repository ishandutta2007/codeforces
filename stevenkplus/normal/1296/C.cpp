#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, int> pii;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int N;
    string s;
    cin >> N;
    cin >> s;
    map<pii, int> mp;
    pii cur(0, 0);
    mp[cur] = 0;
    pii ans(-1, 0);
    for (int i = 0; i < N; ++i) {
      if (s[i] == 'L') --cur.first;
      if (s[i] == 'R') ++cur.first;
      if (s[i] == 'U') ++cur.second;
      if (s[i] == 'D') --cur.second;
      if (mp.find(cur) != mp.end()) {
        pii v(i + 1 - mp[cur], i + 1);
        if (ans.first == -1 || v < ans) ans = v;
      }
      mp[cur] = i + 1;
    }
    if (ans.first == -1) {
      cout << "-1\n";
    } else {
      cout << ans.second - ans.first + 1 << " " << ans.second << "\n";
    }
  }
}
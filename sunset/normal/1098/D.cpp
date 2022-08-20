#include <bits/stdc++.h>

using namespace std;

const int LOG = 32;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<multiset<int>> s(LOG);
  vector<long long> sum(LOG);
  vector<int> mins(LOG);
  int cur = 0;
  int n;
  cin >> n;
  while (n--) {
    string type;
    int x;
    cin >> type >> x;
    int high = LOG - 1;
    while (!(x >> high & 1)) {
      --high;
    }
    if (type == "+") {
      s[high].insert(x);
      sum[high] += x;
      ++cur;
      mins[high] = s[high].empty() ? 0 : *s[high].begin();
    } else {
      s[high].erase(s[high].find(x));
      sum[high] -= x;
      --cur;
      mins[high] = s[high].empty() ? 0 : *s[high].begin();
    }
    if (!cur) {
      cout << 0 << "\n";
    } else {
      int ans = cur - 1;
      long long small = 0;
      for (int i = 0; i + 1 < LOG; ++i) {
        small += sum[i];
        if (small && !s[i + 1].empty() && mins[i + 1] > small * 2) {
          --ans;
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
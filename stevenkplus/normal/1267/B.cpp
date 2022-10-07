#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 300100;
pii ar[MAXN];
int main() {
  string s;
  cin >> s;
  int stk = 0;
  ar[0].first = s[0];
  for(int i = 0; i < s.size(); ++i) {
    if (s[i] != ar[stk].first) {
      ++stk;
    }
    ar[stk].first = s[i];
    ar[stk].second += 1;
  }
  vector<int> v;
  int ans = 0;
  if (stk % 2 == 0) {
    int k = stk / 2;
    for(int i = 0; i <= stk; ++i) {
      if (i == k) continue;
      if (!v.empty() && ar[v.back()].first == ar[i].first && ar[v.back()].second + ar[i].second >= 3) {
        v.pop_back();
      } else {
        v.push_back(i);
      }
    }

    if (v.size() == 0) {
      if (ar[k].second >= 2) {
        ans = ar[k].second + 1;
      }
    }
  }
  cout << ans << "\n";
}
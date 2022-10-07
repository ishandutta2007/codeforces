#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400100;
int ar[MAXN];
int tmp[MAXN];

typedef long long ll;
typedef pair<int, int> pii;
ll cnt;
vector<pii> flags;

void push(int a, int b) {
  flags.push_back(pii(a, 1));
  flags.push_back(pii(b, -1));
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> ar[i];
  }

  int ans = 0;
  for(int i = 0; i < 28; ++i) {
    int mask = (1 << (i + 1)) - 1;
    for (int j = 0; j < n; ++j) {
      tmp[j] = ar[j] & mask;
    }
    int bit = 1 << i;
    sort(tmp, tmp + n);
    cnt = 0;
    flags.clear();
    for (int j = 0; j < n; ++j) {
      int min = bit - tmp[j];
      if (min < 0) min += 2 * bit;
      int max = min + bit;
      if (max > 2 * bit) max -= 2 * bit;
      if (min > max) {
        push(min, 2 * bit);
        push(0, max);
      } else {
        push(min, max);
      }
      if ((2 * tmp[j]) & bit) cnt -= 1;
    }
    sort(flags.begin(), flags.end());
    int idx = 0;
    int run = 0;
    for (int j = 0; j < n; ++j) {
      while (idx < flags.size() && flags[idx].first <= tmp[j]) {
        run += flags[idx].second;
        ++idx;
      }
      cnt += run;
    }

    if ((cnt / 2) & 1) {
      ans |= bit;
    }
  }
  cout << ans << "\n";
}
#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 41;

void solve() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > 0)
      v.push_back(x);
  }
  sort(v.begin(), v.end());
  int tot4 = count(v.begin(), v.end(), 4);

  vector<int> sum(v.size() + 1, 0);
  for (int i = 0; i < (int)v.size(); i++)
    sum[i + 1] = sum[i] + v[i];
  
  int ans = INF;
  int nonEmpty = v.size();
  int tot = accumulate(v.begin(), v.end(), 0);

  for (int num4 = 0; num4 <= n; num4++) {
    if (num4 * 4 > tot || (tot - num4 * 4) % 3) continue;
    int num3 = (tot - num4 * 4) / 3;

    int moveR = sum[max(0, nonEmpty - num3 - num4)];
    int moveL = max(0, tot4 - num4);

    ans = min(ans, moveL + moveR);

    //cout << num3 << " " << num4 << " " << moveL << " " << moveR << endl;
  }

  if (ans == INF)
    cout << "-1\n";
  else
    cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

#ifdef SERT
  t = 3;
#endif

  for (int i = 0; i < t; i++)
    solve();
}
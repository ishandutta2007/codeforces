#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int sum = 0, cnt = 0;
  ld orig_sum = 0;
  for (int i = 0; i < 2 * n; ++i) {
    string s;
    cin >> s;
    ld val = stold(s);
    int down = floor(val);
    sum += down;
    orig_sum += val;
    if (val == down) {
      ++cnt;
    }
  }
  ld ans = numeric_limits<ld>::max();
  for (int i = 0; i <= min(n, cnt); ++i) {
    int cur_sum = sum + n - i;
    ld delta = fabsl(orig_sum - cur_sum);
    ans = fminl(ans, delta);
  }
  cout << setprecision(3) << fixed << ans;
  return 0;
}
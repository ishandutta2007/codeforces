#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const ll inf = 1e12;
const ll mod = 1e9 + 7;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }

long long dp[200001][10];
vector<long long> turns[200000][4];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;
  for (int i=0; i<n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int c, d;
      cin >> c >> d;
      turns[i][c].push_back(d);
    }
    for (int k=1; k<=3; k++)
      sort(turns[i][k].begin(), turns[i][k].end());
  }

  memset(dp, 128, sizeof(dp));

  dp[0][0] = 0;
  for (int i=0; i<n; i++)
    for (int j=0; j<10; j++) {
      // case 1: 1 card
      long long mx = LLONG_MIN;
      for (int k=1; k<=3; k++) {
        if (!turns[i][k].empty())
          mx = max(mx, turns[i][k].back());
      }
      if (mx != LLONG_MIN) {
        dp[i+1][(j+1)%10] = max(dp[i+1][(j+1)%10], dp[i][j] + (j == 9 ? 2 : 1) * mx);
      }

      // case 2: 2 cards
      mx = LLONG_MIN;
      for (int k=1; k<=2; k++)
        for (int l=1; l+k<=3; l++) {
          if (turns[i][k].empty() || turns[i][l].empty())
            continue;
          if (k == l) { // same bucket
            if (turns[i][k].size() < 2)
              continue;
            if (j >= 8) {
              mx = max(mx, 2 * turns[i][k].back() + turns[i][k][turns[i][k].size()-2]);
            } else {
              mx = max(mx, turns[i][k].back() + turns[i][k][turns[i][k].size()-2]);
            }
          } else {  // different buckets
            if (j >= 8) {
              mx = max(mx, turns[i][k].back() + turns[i][l].back() + max(turns[i][k].back(), turns[i][l].back()));
            } else {
              mx = max(mx, turns[i][k].back() + turns[i][l].back());
            }
          }
        }
      if (mx != LLONG_MIN) {
        dp[i+1][(j+2)%10] = max(dp[i+1][(j+2)%10], dp[i][j] + mx);
      }

      // case 3: 3 cards
      ll beegle = 0;
      ll big = LLONG_MIN;
      if (turns[i][1].size() >= 3) {
        for (int k=1; k<=3; k++) {
          big = max(big, turns[i][1][turns[i][1].size()-k]);
          beegle += turns[i][1][turns[i][1].size()-k];
        }
        if (j >= 7)
          beegle += big;
        dp[i+1][(j+3)%10] = max(dp[i+1][(j+3)%10], dp[i][j] + beegle);
      }

      // case 4: 0 cards
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    }

  ll ret = 0;
  for (int j=0; j<10; j++)
    ret = max(ret, dp[n][j]);

  cout << ret << "\n";
}
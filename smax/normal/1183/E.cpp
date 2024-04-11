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

ll dp[105][105];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll n, k; cin >> n >> k;
  string s; cin >> s;

  ll arr[26];

  f0r(i, 26) {
    arr[i] = -1;
  }

  ms(dp, 0);

  dp[0][1] = 1;
  arr[s[0] - 'a'] = 0;

  for (ll i = 1; i < n; i++) {
    for (ll j = 1; j < n+1; j++) {
      //cout << i << " " << j << " " <<  dp[i-1][j-1] << " " << dp[i-1][j] << endl;
      dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + (arr[s[i] - 'a'] == -1 && j == 1);
      //cout << dp[i][j] << endl;
      if (arr[s[i] - 'a'] > 0) {
        //cout << "yo:" << arr[s[i] - 'a'] << endl;
        dp[i][j] -= dp[arr[s[i] - 'a'] - 1][j - 1];
      }
      dp[i][j] = min(k + 1, dp[i][j]);

    }
    arr[s[i] - 'a'] = i;
  }

  /*f0r(i, n) {
    ao(dp[i], n+1);
  }*/

  ll ret = 0;

  ll length = n;
  dp[n-1][0] = 1;
  while (k > 0 && length >= 0) {
    ret += min(dp[n-1][length], k) * (n - length);

    k -= dp[n-1][length];
    length--;
    //cout << k << " " << dp[n-1][length + 1] << " " << length + 1 << endl;
  }

  if (k > 0) {
    cout << -1 << endl;
  } else {
    cout << ret << endl;
  }







}
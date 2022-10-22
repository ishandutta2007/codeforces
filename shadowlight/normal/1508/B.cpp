#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const ll INF = (ll) 2e18 + 7;
const int N = 1e5 + 7;

ll cnt[N];

void init() {
  cnt[0] = 1;
  ll sum = 1;
  for (int i = 1; i < N; ++i) {
      cnt[i] = sum;
      sum += cnt[i];
      if (sum >= INF) {
        sum = INF;
      }
  }
}

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  if (cnt[n] < k) {
    cout << "-1\n";
    return;
  }
  --k;

  vector <int> res;
  while (res.size() < n) {
    int rem = n - res.size();
    for (int len = 1; len <= rem; len++) {
      if (cnt[rem - len] > k) {
        int l = res.size() + 1;
        int r = res.size() + len;
        while (r >= l) {
          res.pb(r--);
        }
        break;
      }
      k -= cnt[rem - len];
    }
  }
  for (int x : res) {
    cout << x << " ";
  }
  cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}
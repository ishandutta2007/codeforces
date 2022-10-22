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

const int N = 1e6 + 7;
int d[N];
vector <int> ps;
void sieve() {
  fill_n(d, N, -1);
  for (int i = 2; i < N; ++i) {
    if (d[i] == -1) {
      ps.pb(i);
      d[i] = ps.size() - 1;
    }
    for (int j = 0; j <= d[i]; ++j) {
      if (ps[j] * (ll) i >= N ) break;
      d[ps[j] * i] = j;
    }
  }
}

const ll INF = (ll) 1e18 + 7;


int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  sieve();

  ll n, x, y;
  cin >> n >> x >> y;

  vector <int> zero(ps.size(), 0);
  vector <int> one(ps.size(), 0);
  vector <int> a(n, 0);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[i] = x;

    int w = x;
    int pr = -1;
    while (w != 1) {
      int id = d[w];
      if (pr != id) {
        ++zero[id];
        pr = id;
      }
      w /= ps[id];
    }

    pr = -1;
    w = x + 1;
    while (w != 1) {
      int id = d[w];
      if (pr != id) {
        ++one[id];
        pr = id;
      }
      w /= ps[id];
    }
  }
  ll res = INF;

  for (int i = 0; i < (int) ps.size(); ++i) {
    if (x < y) {
      res = min(res, (n - zero[i]) * x);
    } else if (x < 2 * y) {
      res = min(res, one[i] * y + (n - zero[i] - one[i]) * x);
    } else if (!i || zero[i] + one[i] >= (n + 1) / 2) {
      ll nowk = 0;
      for (int j = 0; j < n; ++j) {
        int now = (ps[i] - a[j] % ps[i]) % ps[i];
        nowk += min(now * y, x);
      }
      //cout << ps[i] << " " << now << endl;
      res = min(res, nowk);
    }
  }

  cout << res << "\n";
}
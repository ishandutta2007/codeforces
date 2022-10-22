#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

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
int res[N];
int d[N];
vector <int> p;

void sieve() {
  fill_n(d, N, -1);
  for (int i = 2; i < N; ++i) {
    if (d[i] == -1) {
      p.pb(i);
      d[i] = p.size() - 1;
    }
    for (int j = 0; j <= d[i]; ++j) {
      if (p[j] * (ll) i >= N) break;
      d[p[j] * i] = j;
    }
  }
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  sieve();

  int n;
  cin >> n;
  vector <int> res(n + 1, 0);
  vector <int> sums(n + 1, 0);
  res[0] = 1;
  sums[0] = 1;

  for (int i = 1; i <= n; ++i) {
    int cnt = 1;
    int x = i;
    int pr = -1, now = 0;

    while (x != 1) {
      int pp = p[d[x]];
      x /= pp;
      if (pp == pr) {
        ++now;
      } else {
        cnt = mult(cnt, now + 1); 
        now = 1;
        pr = pp;
      }
    }
    cnt = mult(cnt, now + 1);
    res[i] = cnt - 1;

    add(res[i], sums[i - 1]);
    add(sums[i], sums[i - 1]);
    add(sums[i], res[i]);
  }
  cout << res[n] << "\n";
}
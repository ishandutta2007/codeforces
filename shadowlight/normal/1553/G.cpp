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
      if ((ll) ps[j] * i >= N) break;
      d[ps[j] * i] = j;
    }
  }
}

vector <int> factorize(int x) {
  vector <int> a;
  while (x != 1) {
    if (!a.size() || a.back() != d[x]) {
      a.pb(d[x]);
    }
    int p = ps[d[x]];
    x /= p;
  }
  return a;
}

struct DSU {
  int n;
  vector <int> par;
  vector <int> rk;

  DSU(int n) : n(n), rk(n), par(n) {
    iota(all(par), 0);
  }

  int get(int v) {
    return (par[v] == v ? v : par[v] = get(par[v]));
  }

  void uni(int v, int u) {
    v = get(v);
    u = get(u);
    if (v == u) return;
    if (rk[v] > rk[u]) {
      swap(v, u);
    }
    if (rk[v] == rk[u]) {
      ++rk[u];
    }
    par[v] = u;
  }
};

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  sieve();

  int n, q;
  cin >> n >> q;

  int P = ps.size();

  DSU dsu(P);

  vector <set<int>> have(P);

  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];

    auto fact = factorize(a[i]);
    for (int i = 1; i < (int) fact.size(); ++i) {
      dsu.uni(fact[i], fact[i - 1]);
    }
  }

  for (int i = 0; i < n; ++i) {
    auto fact = factorize(a[i] + 1);

    int x = dsu.get(d[a[i]]);
    for (int &y : fact) {
      y = dsu.get(y);
      if (x != y) {
        have[min(x, y)].insert(max(x, y));
      }
    }
    for (int i = 0; i < (int) fact.size(); ++i) {
      for (int j = i + 1; j < (int) fact.size(); ++j) {
        if (fact[i] == fact[j]) continue;
        int x = fact[i], y = fact[j];
        have[min(x, y)].insert(max(x, y));
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    int s, t;
    cin >> s >> t;
    --s, --t;

    int v = d[a[s]], u = d[a[t]];
    v = dsu.get(v);
    u = dsu.get(u);
    if (v > u) {
      swap(v, u);
    }

    if (v == u) {
      cout << "0\n";
    } else if (have[v].find(u) != have[v].end()) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }

}
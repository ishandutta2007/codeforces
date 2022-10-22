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

vector <int> vals;
void get_vals(vector<pair<int, int>>& a, int now = 0, int mlt = 1) {
  if (now == a.size()) {
    vals.pb(mlt);
    return;
  }
  for (int i = 0; i <= a[now].y; ++i) {
    get_vals(a, now + 1, mlt);
    mlt *= a[now].x;
  }
}

const int SQ = 4e4 + 7;

int mex(vector<int>& a) {
  int n = a.size();
  vector<bool> was(n, 0);
  for (int x : a) {
    if (x >= n) continue;
    was[x] = true;
  }
  for (int i = 0; i < n; ++i) {
    if (!was[i]) {
      return i;
    }
  }
  return n;
}

const int LOGN = 30;
const int BITS = 18;

map <int, int> resw;
vector <int> grundy;

int rec(int mask) {
  if (mask < grundy.size()) {
    return grundy[mask];
  }
  if (resw.count(mask)) {
    return resw[mask];
  }

  vector <int> vec;
  for (int p = 1; p <= LOGN; ++p) {
    int nmask = (1 << p) - 1;
    int xmask = mask & ~nmask;
    int nxt = (mask & (nmask >> 1)) | (xmask >> p);

    if (nxt != mask) {
      vec.pb(rec(nxt));
    }
  }

  return resw[mask] = mex(vec);
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  sieve();

  int n;
  cin >> n;
  vector <int> a(n);

  int res = 0;

  vector <int> have(ps.size(), 0);

  set <int> q;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    vector <pair<int, int>> f;

    for (int j = 2; j < SQ; ++j) {
      int cnt = 0;
      while (a[i] % j == 0) {
        ++cnt;
        a[i] /= j;
      }
      if (cnt) {
        have[d[j]] |= (1 << (cnt - 1));
      }
    }
    if (a[i] != 1) {
      q.insert(a[i]);
    }
  }

  res = q.size() % 2;

  grundy.resize(1 << BITS, 0);
  for (int mask = 0; mask < grundy.size(); ++mask) {
    vector <int> vec;

    for (int p = 1; p <= BITS; ++p) {
      int nmask = (1 << p) - 1;
      int xmask = mask & ~nmask;
      int nxt = (mask & (nmask >> 1)) | (xmask >> p);

      if (nxt != mask) {
        vec.pb(grundy[nxt]);
      }
    }

    grundy[mask] = mex(vec);
  }

  for (int i = 0; i < (int) ps.size(); ++i) {
    int mask = have[i];
    res ^= rec(mask);
  }

  if (!res) {
    cout << "Arpa\n";
  } else {
    cout << "Mojtaba\n";
  }

}
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

int inv(int a) {
  return bp(a, mod - 2);
}

const int INF = 1e9 + 3e5;

const int N = 2e5 + 7;
int f[N];
int rf[N];

void init() {
  f[0] = 1;
  rf[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(f[i - 1], i);
    rf[i] = inv(f[i]);
  }
}

void upd(pair<int, int>& a, pair<int, int> b) {
  a.x = max(a.x, b.x);
  a.y = min(a.y, b.y);
}

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mult(f[n], mult(rf[n - k], rf[k])); 
}

void solve() {
  int n, l, r;
  cin >> n >> l >> r;

  int a = n / 2, b = n - a;

  vector <pair <int, int>> vals;
  for (int i = 0; i < n; ++i) {
    vals.pb({l - i - 1, r - i - 1});
  }
  vector <pair <int, int>> prefix_segs(n);
  for (int i = 0; i < n; ++i) {
    prefix_segs[i] = vals[i];
    if (i) {
      upd(prefix_segs[i], prefix_segs[i - 1]);
    }
  }

  vector <pair<int, int>> suffix_segs(n);
  for (int i = n - 1; i >= 0; --i) {
    suffix_segs[i] = vals[i];
    if (i != n - 1) {
      upd(suffix_segs[i], suffix_segs[i + 1]);
    }
  }

  int res = 0;

  for (int it = 0; it < 2; ++it) {
    int L = -INF, R = INF;
    for (auto [lt, rt] : vals) {
      //cout << lt << " " << rt << endl;
      L = max(lt, L);
      R = min(rt, R);
    }
    //cout << "LR: " << L << " " << R << endl;

    int N = max(min(-L, R), 0);
    add(res, mult(N, C(n, a)));

    int r = n - 1;
    int l = 0;

    while (l < n && r >= 0) {
      //cout << l << " " << r << " " << prefix_segs[l].y << " " << -suffix_segs[r].x << endl;
      if (r >= 0 && prefix_segs[r].y <= N) {
        --r;
        continue;
      }
      if (l < n && -suffix_segs[l].x <= N) {
        ++l;
        continue;
      }


      int NN = min(prefix_segs[r].y, -suffix_segs[l].x);

      int items = a;
      items -= l;

      //cout << N << " " << NN << " " << l << " " << r << " " << items << " " << a << endl;

      add(res, mult(NN - N, C(r - l + 1, items)));
      N = NN;
    }

    if (a != b) {
      swap(a, b);
    } else {
      break;
    }
  }

  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
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
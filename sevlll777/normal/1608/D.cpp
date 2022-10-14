#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define range(i, n) for (int i = 0; i < (n); ++i)
#define ld long double
using namespace std;
const int M = 998244353;
typedef long long ll;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 3e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


inline int add(const int &a, const int &b) {
  return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
  return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
  return (1ll * a * b) % md;
}

int binpow(int a, int b) {
  if (b <= 0) return 1;
  if (b % 2) return mul(a, binpow(a, b - 1));
  int m = binpow(a, b / 2);
  return mul(m, m);
}

int rev(int a) {
  return binpow(a, md - 2);
}

const int maxF = 3e5 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
  fact[0] = 1;
  for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
  rfact[maxF - 1] = rev(fact[maxF - 1]);
  for (int i = maxF - 1; i >= 1; --i) {
    rfact[i - 1] = mul(rfact[i], i);
  }
}

int C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int psq[maxN];

void initFFT() {
  int s = 31;
  for (int i = (1 << 23); i >= 1; i /= 2, s = mul(s, s)) {
    if (i < maxN) psq[i] = s;
  }
}

void fft(vector<int> &s, vector<int> &res, int n, int x, int ss = 0, int step = 1, int rs = 0) {
  if (n == 1) {
    res[rs] = s[ss];
    return;
  }
  fft(s, res, n / 2, mul(x, x), ss, step * 2, rs);
  fft(s, res, n / 2, mul(x, x), ss + step, step * 2, rs + n / 2);
  int c = 1;
  for (int i = rs; i < rs + n / 2; ++i) {
    auto a = res[i], b = res[i + n / 2];
    res[i] = add(a, mul(b, c));
    res[i + n / 2] = sub(a, mul(b, c));
    c = mul(c, x);
  }
}

vector<int> multiply(vector<int> &a, vector<int> &b) {
  vector<int> as(all(a)), bs(all(b));
  int n = 1;
  while (n < a.size() || n < b.size()) n *= 2;
  n *= 2;
  as.resize(n);
  bs.resize(n);
  int t = psq[n];
  vector<int> resa(n), resb(n);
  fft(as, resa, n, t);
  fft(bs, resb, n, t);
  range(i, n)resa[i] = mul(resa[i], resb[i]);
  t = rev(t);
  fft(resa, as, n, t);
  int rn = rev(n);
  range(i, n)as[i] = mul(as[i], rn);
  return as;
}

const int N = 100500;
vector<int> keka[N];

vector<int> aboba(int l, int r) {
  if (l >= r) return {1};
  if (l + 1 == r) {
    return keka[l];
  }
  int m = (l + r + 1) / 2;
  vector<int> a1 = aboba(l, m), a2 = aboba(m, r);
  vector<int> a3 = multiply(a1, a2);
  while ((int) a3.size() > 1 && a3.back() == 0) {
    a3.pop_back();
  }
  return a3;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  bool bw = true, wb = true;
  for (int i = 0; i < n; i++) {
    if (S[i][0] == 'W' || S[i][1] == 'B') {
      bw = false;
    }
    if (S[i][0] == 'B' || S[i][1] == 'W') {
      wb = false;
    }
  }
  int ans = wb + bw;
  int a = 0, y = 0, z = 0;
  int dif = 0;
  for (auto s : S) {
    if (s == "??") {
      a++;
    } else if (s == "BB") {
      dif++;
    } else if (s == "WW") {
      dif--;
    } else if (s != "BW" && s != "WB") {
      if (s[0] == 'B' || s[1] == 'B') {
        y++;
      } else {
        z++;
      }
    }
  }
  dif = -dif;
  for (int d = 0; d < y + z; d++) {
    keka[d] = {1, 1};
  }
  for (int d = y + z; d < a + y + z; d++) {
    keka[d] = {1, 2, 1};
  }
  init();
  initFFT();
  vector<int> kekis = aboba(0, a + y + z);
  int v = dif + a + z;
  if (v < 0 || v >= (int) kekis.size()) {
    cout << ans << '\n';
  } else {
    if (dif == 0) {
      int c1 = 1;
      for (int i = 0; i < n; i++) {
        if (S[i] == "??") {
          c1 *= 2;
          c1 %= M;
        } else if (S[i] == "BB" || S[i] == "WW") {
          c1 = 0;
          break;
        }
      }
      c1 += (M - ans);
      c1 %= M;
      kekis[v] += (M - c1);
      kekis[v] %= M;
    }
    cout << kekis[v] << '\n';
  }


}
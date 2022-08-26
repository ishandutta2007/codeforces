#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ipair;
typedef pair <ll, ll> lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = numeric_limits<double>::infinity();
const double EPS = 1e-9;
const double PI = acos((double)-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

template<typename T> istream& operator >> (istream& in, vector<T>& a) { for (T& x : a) in >> x; return in; }
template<typename T> ostream& operator << (ostream& out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) out << " ";
    f = false;
    out << x;
  }
  return out;
}

template<typename A, typename B> istream& operator >> (istream& in, pair<A, B>& p) { return in >> p.X >> p.Y; }
template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> const& p) { return out << p.X << " " << p.Y; }

template<typename T>
T pw(T a, ll b) {
  T r = T(1);
  for (; b; b >>= 1) {
    if (b & 1) r *= a;
    a *= a;
  }
  return r;
}

template<int M>
struct mint_t {
  int v;
  
  mint_t() : v(0) {}
  mint_t(int v) : v(v % M) { if (v < 0) v += M; }
  mint_t(ll v) : v(v % M) { if (v < 0) v += M; }
  mint_t(mint_t<M> const& b) : v(b.v) {}

  mint_t& operator = (mint_t b) { v = b.v; return *this; }

  mint_t& operator += (mint_t b) { v += b.v; if (v >= M) v -= M; return *this; }
  mint_t& operator -= (mint_t b) { v -= b.v; if (v < 0) v += M; return *this; }
  mint_t& operator *= (mint_t b) { v = 1LL * v * b.v % M; return *this; }
  mint_t& operator /= (mint_t b) { return *this *= pw(b, M - 2);}

  mint_t operator - () const { return mint_t(v == 0 ? 0 : M - v); }

  mint_t& operator ++() { if (++v == M) v = 0; return *this; }
  mint_t& operator --() { if (v == 0) v = M - 1; else --v; return *this; }
  mint_t operator ++(int) { mint_t a = *this; ++*this; return a; }
  mint_t operator --(int) { mint_t a = *this; --*this; return a; }
};

template<int M> mint_t<M> operator + (mint_t<M> a, mint_t<M> b) { return a += b; }
template<int M> mint_t<M> operator - (mint_t<M> a, mint_t<M> b) { return a -= b; }
template<int M> mint_t<M> operator * (mint_t<M> a, mint_t<M> b) { return a *= b; }
template<int M> mint_t<M> operator / (mint_t<M> a, mint_t<M> b) { return a /= b; }

template<int M> mint_t<M> operator + (mint_t<M> a, int b) { return a += b; }
template<int M> mint_t<M> operator - (mint_t<M> a, int b) { return a -= b; }
template<int M> mint_t<M> operator * (mint_t<M> a, int b) { return a *= b; }
template<int M> mint_t<M> operator / (mint_t<M> a, int b) { return a /= b; }

template<int M> mint_t<M> operator + (int a, mint_t<M> b) { mint_t<M> aa = a; return aa += b; }
template<int M> mint_t<M> operator - (int a, mint_t<M> b) { mint_t<M> aa = a; return aa -= b; }
template<int M> mint_t<M> operator * (int a, mint_t<M> b) { mint_t<M> aa = a; return aa *= b; }
template<int M> mint_t<M> operator / (int a, mint_t<M> b) { mint_t<M> aa = a; return aa /= b; }

template<int M> bool operator == (mint_t<M> a, mint_t<M> b) { return a.v == b.v; }
template<int M> bool operator != (mint_t<M> a, mint_t<M> b) { return a.v != b.v; }
template<int M> bool operator < (mint_t<M> a, mint_t<M> b) { return a.v < b.v; }
template<int M> bool operator > (mint_t<M> a, mint_t<M> b) { return a.v > b.v; }
template<int M> bool operator <= (mint_t<M> a, mint_t<M> b) { return a.v <= b.v; }
template<int M> bool operator >= (mint_t<M> a, mint_t<M> b) { return a.v >= b.v; }
template<int M> bool operator == (mint_t<M> a, int b) { return a == mint_t<M>(b); }
template<int M> bool operator != (mint_t<M> a, int b) { return a != mint_t<M>(b); }
template<int M> bool operator == (int a, mint_t<M> b) { return b == mint_t<M>(a); }
template<int M> bool operator != (int a, mint_t<M> b) { return b != mint_t<M>(a); }

template<int M>
istream& operator >> (istream &in, mint_t<M> &a) {
  int x;
  in >> x;
  a = x;
  return in;
}

template<int M>
ostream& operator << (ostream &out, mint_t<M> a) {
  return out << a.v;
}

const int MOD = 998244353;
typedef mint_t<MOD> mint;

const int N = 103;

bool its(__int128_t a, __int128_t b) {
  auto c = a & b;
  return a != c && b != c && c;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> sets;
  set<__int128_t> swas;
  vector<__int128_t> setm;
  for (int i = -1; i < m; ++i) {
    int k;
    vector<int> s;
    if (i == -1) k = n; else {
      cin >> k;
    }
    __int128_t mask = 0;
    for (int j = 0; j < k; ++j) {
      int s1;
      if (i == -1) s1 = j; else {
        cin >> s1; --s1;
      }
      s.push_back(s1);
      mask |= (__int128_t)1 << s1;
    }
    if (swas.count(mask)) continue;
    swas.insert(mask);
    setm.push_back(mask);
    sets.push_back(s);
  }
  m = sz(sets);

  mint ans = 1;
  vector<char> vis(m, 0);

  vector<pair<__int128_t, int>> keks, keks2;

  for (int s0 = 0; s0 < m; ++s0) {
    if (vis[s0]) continue;
    vis[s0] = 1;
    vector<int> rank(n, -1);
    int mrank = 0;
    for (int x : sets[s0]) rank[x] = 0;
    set<int> q;
    for (int i = 0; i < m; ++i)
      if (!vis[i] && its(setm[i], setm[s0]))
        q.insert(i);
    vector<int> qq = {s0};
    while (!q.empty()) {
      int s = *q.begin();
      qq.push_back(s);
      q.erase(s);
      vis[s] = 1;
      for (int i = 0; i < m; ++i)
        if (!vis[i] && its(setm[i], setm[s]))
          q.insert(i);
      int cl = IINF, cr = -IINF;
      int wasMR = 0;
      for (int i = 0; i < n; ++i)
        if (rank[i] == mrank)
          ++wasMR;
      for (int v : sets[s]) {
        if (rank[v] == -1) rank[v] = mrank + 1;
        if (rank[v] == mrank) wasMR--;
        cl = min(rank[v], cl);
        cr = max(rank[v], cr);
      }
      if (cr == mrank + 1 && wasMR && cl != mrank) {
        for (int v = 0; v < n; ++v)
          if (rank[v] == mrank + 1)
            rank[v] = 0;
          else if (rank[v] != -1)
            rank[v] += 2;
        for (int v : sets[s])
          if (rank[v] != 0)
            --rank[v];
        mrank = *max_element(all(rank));
        continue;
      }
      for (int v = 0; v < n; ++v)
        if (rank[v] >= cr)
          rank[v] += 2;
      for (int v : sets[s]) {
        if (rank[v] == cr + 2)
          --rank[v];
        else
          ++rank[v];
      }
      mrank = *max_element(all(rank));
    }
    for (int s : qq) {
      int cl = IINF, cr = -IINF;
      for (int v : sets[s]) {
        cl = min(rank[v], cl);
        cr = max(rank[v], cr);
      }
      int cnt = sz(sets[s]);
      for (int i = 0; i < n; ++i)
        if (cl <= rank[i] && rank[i] <= cr)
          --cnt;
      if (cnt != 0 || (cl == cr && sz(qq) != 1)) {
        cout << "0\n";
        return;
      }
    }
    if (sz(qq) > 1)
      ans *= 2;

    map<int, __int128_t> skeks;
    __int128_t kek = 0;
    for (int i = 0; i < n; ++i) {
      if (rank[i] != -1) {
        skeks[rank[i]] |= (__int128_t)1 << i;
        kek |= (__int128_t)1 << i;
      }
    }
    keks2.push_back({kek, s0});
    for (auto p : skeks)
      keks.push_back({p.Y, s0});
  }

  for (auto kk : keks) {
    auto mask = kk.X;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      cnt += ((mask >> i) & 1);
    for (auto kk2 : keks2) {
      auto mask2 = kk2.X;
      if ((mask2 & mask) != mask2 || kk2.Y == kk.Y) continue;
      bool ok = true;
      for (auto kk3 : keks2) {
        auto mask3 = kk3.X;
        if ((mask3 & mask) != mask3 || kk3.Y == kk.Y || kk3.Y == kk2.Y) continue;
        if ((mask3 & mask2) == mask2 && (mask3 != mask2 || kk3.Y < kk2.Y)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ++cnt;
        for (int i = 0; i < n; ++i)
          cnt -= ((mask2 >> i) & 1);
      }
    }
    for (int i = 1; i <= cnt; ++i)
      ans *= i;
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
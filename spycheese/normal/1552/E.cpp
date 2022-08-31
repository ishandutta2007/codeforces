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


void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> cs(n * k);
  cin >> cs;
  vector<vector<int>> arr(n);
  for (int i = 0; i < n*k; ++i)
    arr[cs[i] - 1].push_back(i);
  
  vector<char> done(n, 0);
  vector<ipair> ans(n);
  for (int i0 = 0; i0 < n; i0 += k - 1) {
    int i1 = min(n, i0 + k - 1);
    for (int iter = 0; iter < i1 - i0; ++iter) {
      int x = -1;
      for (int i = i0; i < i1; ++i)
        if (!done[i] && (x == -1 || arr[i].back() > arr[x].back()))
          x = i;
      assert(x != -1);
      while (true) {
        int nx = -1;
        int nxr = -1;
        int cl = arr[x][sz(arr[x]) - 2];
        for (int i = i0; i < i1; ++i) {
          if (done[i] || i == x) continue;
          int nl = arr[i][sz(arr[i]) - 2];
          int nr = arr[i][sz(arr[i]) - 1];
          if (nl > cl && nr > nxr) {
            nxr = nr;
            nx = i;
          }
        }
        if (nx == -1) break;
        x = nx;
      }
      int cl = arr[x][sz(arr[x]) - 2];
      ans[x] = {cl + 1, arr[x][sz(arr[x]) - 1] + 1};
      done[x] = 1;
      for (int i = i0; i < i1; ++i)
        if (!done[i])
          while (arr[i].back() > cl)
            arr[i].pop_back();
    }
  }
  for (ipair p : ans) cout << p.X << " " << p.Y << "\n";
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
#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
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
vector<int> ps;

void sieve() {
  fill_n(d, N, -1);
  for (int i = 2; i < N; ++i) {
    if (d[i] == -1) {
      ps.pb(i);
      d[i] = ps.size() - 1;
    }
    for (int j = 0; j <= d[i]; ++j) {
      if (i * (ll) ps[j] >= N) break;
      d[i * ps[j]] = j;
    }
  }
}

const int LOGN = 20;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  sieve();

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<bool> primes(ps.size(), false);
  vector<int> lst(n, -1);

  int r = 0;
  for (int l = 0; l < n; ++l) {
    while (r < n) {
      int x = a[r];
      bool good = true;
      while (x != 1) {
        int p = ps[d[x]];
        if (primes[d[x]]) {
          good = false;
          break;
        }
        while (x % p == 0) x /= p;
      }
      if (!good) break;
      x = a[r];
      while (x != 1) {
        int p = ps[d[x]];
        primes[d[x]] = true;
        while (x % p == 0) x /= p;
      }
      ++r;
    }  
    lst[l] = r;

    int x = a[l];
    while (x != 1) {
      int p = ps[d[x]];
      primes[d[x]] = false;
      while (x % p == 0) x /= p;
    }
  }

  vector <vector<int>> binup(n, vector<int>(LOGN, n));
  for (int i = n - 1; i >= 0; --i) {
    binup[i][0] = lst[i];
    for (int j = 1; j < LOGN; ++j) {
      if (binup[i][j - 1] == n) break;
      binup[i][j] = binup[binup[i][j - 1]][j - 1];
    }
  }

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int res = 0;
    for (int j = LOGN - 1; j >= 0; --j) {
      if (binup[l][j] <= r) {
        res += (1 << j);
        l = binup[l][j];
      }
    }
    cout << res + 1 << "\n";
  }
}
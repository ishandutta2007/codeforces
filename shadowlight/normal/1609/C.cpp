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
vector<bool> prime;

void sieve() {
  prime.resize(N, true);
  for (int i = 2; i < N; ++i) {
    if (!prime[i]) continue;
    for (int j = 2 * i; j < N; j += i) {
      prime[j] = false;
    }
  }
}

void solve() {
  int n, e;
  cin >> n >> e;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ll res = 0;

  for (int i = 0; i < e; ++i) {
    int pr = -1;
    int now = 0;

    for (int j = i; j < n; j += e) {
      //cout << a[j] << " ";
      if (a[j] == 1) {
        ++now;
      } else {
        if (pr != -1) {
          res += pr * (ll) (now + 1) + now;
        }
        if (prime[a[j]]) {
          pr = now, now = 0;
        } else {
          pr = -1, now = 0;
        }
      }
    }
    if (pr != -1) {
      res += pr * (ll) (now + 1) + now;
    }
    //cout << "\n";
    //per(pr, now);
  }
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  sieve();

  /*for (int i = 2; i <= 10; ++i) {
    if (prime[i]) per(i);
  }*/

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}
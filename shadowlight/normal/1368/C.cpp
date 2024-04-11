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

const int LOGN = 20;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  int cnt = 2 * n - 1;

  vector <pair <int, int>> res;
  vector <pair<int, int>> freex;

  for (int i = 0; i < n; ++i) {
    res.pb({2 * i, 0});
    if (i != n - 1) {
      res.pb({2 * i + 1, 0});
    }
    if (!i) {
      freex.pb({-1, 0});
    }
    freex.pb({2 * i, 1});
    if (i == n - 1) {
      freex.pb({2 * i + 1, 0});
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    freex.pb({2 * i, -1});
  }
  assert(freex.size() % 2 == 0);

  for (int it = 0; it < (int) freex.size(); it += 2) {
    auto A = freex[it], B = freex[it + 1];
    res.pb(A);
    res.pb(B);
    if (A.y == B.y) {
      if (A.x > B.x) swap(A, B);
      if (A.y == 1) {
        res.pb({A.x, A.y + 1});
        res.pb({A.x + 1, A.y + 1});
        res.pb({A.x + 2, A.y + 1});
      } else {
        res.pb({A.x, A.y - 1});
        res.pb({A.x + 1, A.y - 1});
        res.pb({A.x + 2, A.y - 1});
      }
    } else {
      if (!it) {
        res.pb({-1, 1});
      } else if (A.y == 1) {
        res.pb({2 * n - 1, 1});
      } else {
        res.pb({2 * n - 1, -1});
      }
    } 
  } 
  cout << res.size() << "\n";
  for (auto t : res) {
    cout << t.x << " " << t.y << "\n";
  }
}
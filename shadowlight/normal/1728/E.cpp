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

ll gcd (ll a, ll b, ll &x, ll &y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  ll x1, y1;
  ll  d = gcd (b%a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<int> b(n);
  ll suma = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x >> b[i];
    b[i] -= x;
    suma += x;
  }

  vector<ll> ans(n + 1, 0);
  sort(all(b));
  reverse(all(b));
  ans[0] = suma;
  for (int i = 1; i <= n; ++i) {
    ans[i] = ans[i - 1] + b[i - 1];
  }

  int pos = 0;
  for (int i = 1; i <= n; ++i) {
    if (ans[i] > ans[pos]) pos = i;
  }
  
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;

    int g = __gcd(x, y);
    if (n % g) {
      cout << "-1\n";
      continue;
    }
    int z = n / g;
    x /= g, y /= g;

    ll cx, cy;
    gcd(x, y, cx, cy);
    cx *= z, cy *= z;

    ll res = 0;

    if (cx < 0) {
      ll k = (-cx - 1) / y + 1;
      cx += k * y, cy -= k * x;
    }
    if (cy < 0) {
      ll k = (-cy - 1) / x + 1;
      cx -= k * y, cy += k * x;
    }
    if (cx < 0 || cy < 0) {
      cout << "-1\n";
      continue;
    }
    ll k = cx / y;
    cx -= k * y, cy += k * x;
    int R = cy * y * g;

    k = cy / x;
    cx += k * y, cy -= k * x;
    int L = cy * y * g;

    int step = x * y * g;

    //per(L, R, step, ans);

    assert((R - L) % step == 0);

    if (pos <= L) {
      res = ans[L];
    } else if (pos >= R) {
      res = ans[R];
    } else {
      int dd = pos % step;
      int ee = L % step;
      if (dd < ee) {
        res = max(ans[pos + ee - dd], ans[pos + ee - dd - step]);
      } else {
        res = max(ans[pos + ee - dd], ans[pos + ee - dd + step]);
      }
    }

    cout << res << "\n";

    //per(x, y, cx, cy, z);
  }

}
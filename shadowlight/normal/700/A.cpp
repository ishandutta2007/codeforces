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

int n, k;
db l, v1, v2;


bool check(db tm) {
  int n = ::n, k = ::k;
  db l = ::l;
  while (n) {
    n -= min(n, k);
    
    db a = (v1 * v2 * tm - l * v2) / (v1 - v2);
    if (v2 * tm < l) {
      return false;
    }
    if (v1 * tm > l) {
      return true;
    }

    if (!n) break;
    db t = a / v2;
    tm -= t;
    l -= v1 * t;
    a -= v1 * t;

    t = a / (v1 + v2);
    //cout << a << " " << (v1 + v2) << " " << t << endl;
    tm -= t;
    l -= v1 * t;

    //cout << a << " " << tm << " " << l << " " << v2 * tm << endl;
    
    if (tm < 0) {
      return false;
    }
  }
  return true;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> l >> v1 >> v2 >> k;

  db lt = 0, rt = l;
  for (int it = 0; it < 500; ++it) {
    db mt = (lt + rt) / 2;
    //cout << mt << " " << check(mt) << endl;
    if (check(mt)) {
      rt = mt;
    } else {
      lt = mt;
    }
  }

  cout.precision(20);
  cout << fixed << rt << "\n";
}
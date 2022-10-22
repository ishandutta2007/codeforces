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


int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector <int> a(n), b(n);
  ll suma = 0, sumb = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    suma += a[i];
    sumb += b[i];
  }
  ll total = (suma / k) + (sumb / k);
  int A = suma % k, B = sumb % k;
  if (A + B < k) {
    cout << total << "\n";
    return 0;
  }
  for (int it = 0; it < 2; ++it) {
    vector <bool> can(2 * k, false);
    can[0] = true;
    //  (k - B)

    for (int i = 0; i < n; ++i) {
      for (int g = k - 1; g >= 0; --g) {
        if (!can[g]) continue;

        for (int t = 0; t <= k; ++t) {
          if (t > a[i] || k - t > b[i]) continue;
          can[(g + t) % k] = true;
        }
      }
    }
    if (can[k - B]) {
      cout << total + 1 << "\n";
      return 0;
    }

    swap(suma, sumb);
    swap(a, b);
    swap(A, B);
  }
  cout << total << "\n";
}
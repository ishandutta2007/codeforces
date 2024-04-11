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

const int mod = 998244353;

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

const int N = 3007;
int ways[N][N];
int suffix[N][2];

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  for (int i = 0; i < m; ++i) {
    ways[i][i] = 1;
  }

  int res = 0;
  int uk = 0;
  int total = 1;
  for (int len = 1; len <= n; ++len) {
    char c = s[len - 1];
    for (int i = 0; i <= m; ++i) {
      suffix[i][uk ^ 1] = 0;
    }
    suffix[0][uk] = total;
    total = mult(total, 2);
    for (int l = 0; l <= m; ++l) {
      int r = min(l + len - 1, m);
      int upd = (r == m ? suffix[m - l][uk] : ways[l][r]);
      if (l && c == t[l - 1]) {
        if (r == m) {
          add(suffix[m - l + 1][uk ^ 1], upd);
        } else {
          add(ways[l - 1][r], upd);
        }
      }
      if (r == m || c == t[r]) {
        if (r + 1 >= m) {
          add(suffix[m - l][uk ^ 1], upd);
        } else {
          add(ways[l][r + 1], upd);
        }
      }
    }
    //per(len, suffix[m][uk ^ 1]);
    add(res, suffix[m][uk ^ 1]);
    uk ^= 1;
  }
  cout << res << "\n";
}
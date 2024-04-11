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

const int K = 2 * sqrt(1e5 + 7);
const int INF = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  reverse(all(a));
  vector <ll> pref(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + a[i];
  }


  vector<vector<int>> res(K);
  res[0] = vector<int>(K, -1);
  res[0][0] = INF;

  for (int i = 0; i < n; ++i) {
    vector <int> vals(K, -1);
    vals[0] = INF;
    for (int j = 1; j < K; ++j) {
      //per(i, j, res[i].size());
      uax(vals[j], res[i % K][j]);
      if (i + 1 < j) break;


      ll sum = pref[i + 1] - pref[i - j + 1];
      if (sum < res[(i + 1 - j + K) % K][j - 1]) {
        uax(vals[j], (int)sum);
      }
    }
    res[(i + 1) % K] = vals;
    if (i == n - 1) {
      for (int j = K - 1; j >= 0; --j) {
        if (vals[j] != -1) {
          cout << j << "\n";
          return; 
        }
      }
    }
  }
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}
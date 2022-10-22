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

int inv(int a) {
  return bp(a, mod - 2);
}

const int N = 207;

int f[N];
int rf[N];
int rv[N];

void init() {
  f[0] = rf[0] = rv[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(i, f[i - 1]);
    rf[i] = inv(f[i]);
    rv[i] = inv(i);
  }
}

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  assert(k <= N);
  int res = 1;
  for (int i = n; i > n - k; --i) {
    res = mult(res, i);
  }
  return mult(res, rv[k]);
}

int counts[2 * N][N];

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();

  int n, k;
  cin >> n >> k;
  counts[0][0] = 1;

  for (int d = 2; d <= k + 1; ++d) {
    vector<int> values(2 * N, 1);
    for (int chosen = 2 * N - 1; chosen >= 0; --chosen) {
      for (int cnt = 1; cnt * (d - 1) <= k; ++cnt) {
        int nops = cnt * (d - 1);
        int elems = cnt * d;

          if (n - chosen - elems + d < 0) continue;
          values[chosen] = mult(values[chosen], C(n - chosen - elems + d, d));
          values[chosen] = mult(values[chosen], rv[cnt]);

          if (!values[chosen]) continue;
          //per(n - chosen, d, cnt, values[chosen]);

          for (int op = k - 1; op >= 0; --op) {
            if (!counts[chosen][op] || op + nops > k) continue;  
            //per(chosen, op, d, cnt, counts[chosen][op], values[chosen]);
            add(counts[chosen + elems][op + nops], mult(counts[chosen][op], values[chosen]));
             
          }
        }
      }
  }

  vector <int> res(k + 1, 0);
  res[2] = 1;
  for (int elems = 0; elems < 2 * N; ++elems) {
    for (int op = 0; op <= k; ++op) {
      add(res[op], counts[elems][op]);
    }
  }

  for (int i = 1; i <= k; ++i) {
    cout << res[i] << " ";
    if (i + 2 <= k) add(res[i + 2], res[i]);
  }
}
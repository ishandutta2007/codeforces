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
const int N = (1 << (LOGN + 2));

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i + 1];
  }
  a[0] = 0;
  ++n;


  int res = 0;
  vector<int> vals(n);
  for (int i = 0; i < n; ++i) {
    vals[i] = i % 2;
  }
  for (int i = LOGN - 1; i >= 0; --i) {
    vector<vector<int>> pos(N);
    vector<int> lpos(N, 0);
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      cnt += (bool) (a[j] & (1 << (i + 1)));
      if (cnt % 2) {
        vals[j] += (1 << (i + 1));
      }
      pos[vals[j]].pb(j);
    }

    //per(i, vals);

    int lt = 0;
    for (int j = 1; j < n; ++j) {
      if (!(a[j] & (1 << i))) {
        lt = j;
        continue;
      }
      int x = vals[j];
      while (pos[x][lpos[x]] < lt) {
        ++lpos[x];
      }
      res = max(res, j - pos[x][lpos[x]]);
    }
  }
  cout << res << "\n";
}
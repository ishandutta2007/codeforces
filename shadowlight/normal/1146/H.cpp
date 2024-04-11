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

struct TVector {
  ll x, y;

  int i, j;
};

TVector operator+(TVector a, TVector b) {
  return {a.x + b.x, a.y + b.y};
}

TVector operator-(TVector a, TVector b) {
  return {a.x - b.x, a.y - b.y};
}

ll operator*(TVector a, TVector b) {
  return a.x * b.y - a.y * b.x;
}

bool cmp(TVector v, TVector u) {
  if (v.y >= 0 && u.y < 0) {
    return 1;
  }
  if (v.y < 0 && u.y >= 0) {
    return 0;
  }
  if (v.y == u.y && !v.y) {
    return v.x > u.x;
  }

  return v * u > 0;
}

const int N = 307;
const int K = 5;

ll dp[N][N][K];

int main(){
#ifdef LOCAL
 freopen("H_input.txt", "r", stdin);
 //freopen("H_output.txt", "w", stdout);
#endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);

 int n;
 cin >> n;
 vector <TVector> a(n);

 vector <TVector> edges;
 for (int i = 0; i < n; ++i) {
  cin >> a[i].x >> a[i].y;
 }

 for (int i = 0; i < n; ++i) {
  for (int j = 0; j < n; ++j) {
    if (i == j) continue;
    TVector v = a[j] - a[i];
    v.i = i, v.j = j;

    edges.pb(v);
  }
 }

 sort(all(edges), cmp);
 for (int i = 0; i < n; ++i) {
  dp[i][i][0] = 1;
 }

 ll res = 0;
 for (auto e : edges) {
  int s = e.i, t = e.j;
  res += dp[t][s][K - 1];
  for (int start = 0; start < n; ++start) {
    for (int cnt = 0; cnt + 1 < K; ++cnt) {
      dp[start][t][cnt + 1] += dp[start][s][cnt];
    }
  }
 }
 cout << res << "\n";
}
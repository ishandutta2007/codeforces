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
const int N = 2e5 + 7;

int cnt[N];
int res[N][LOGN];

int get_seg(int l, int r) {
  return (cnt[r] - cnt[l - 1]) % 2;
}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }

  for (int i = 0; i < N; ++i) {
    cnt[i + 1] += cnt[i];
  }

  for (int i = m; i >= 1; --i) {
    res[i][0] = 0;
    for (int j = 1; j < LOGN; ++j) {
      if (i + (1 << j) > m) break;
      res[i][j] = res[i][j - 1] ^ res[i + (1 << (j - 1))][j - 1];
      res[i][j] ^= get_seg(i + (1 << (j - 1)), i + (1 << j) - 1) * (1 << (j - 1)); 
    }
    per(i, res[i][1]);
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int k = LOGN - 1; k >= 0; --k) {
      if (l + (1 << k) > r) continue;
      ans ^= res[l][k];
      l += (1 << k);
      ans ^= get_seg(l, r) * (1 << k);
    }
    cout << (ans ? 'A' : 'B');
  }
  cout << "\n";
}
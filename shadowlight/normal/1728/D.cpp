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

const int N = 2007;
int dp[N][N];
string s;

int get(int l, int r, char a, char b) {
  if (!dp[l][r]) {
    if (a == b) {
      return 0;
    }
    return (a < b ? 1 : -1);
  } else {
    return dp[l][r];
  }
}

void solve() {
  cin >> s;
  int n = s.size();

  for (int i = 0; i < N; ++i) {
    dp[i][i] = 0;
  }

  for (int cnt = 2; cnt <= n; cnt += 2) {
    for (int i = 0; i + cnt <= n; ++i) {
      int l = i, r = i + cnt - 1;
      dp[l][r + 1] = max(min(get(l + 2, r + 1, s[l], s[l + 1]), get(l + 1, r, s[l], s[r])),
                         min(get(l, r - 1, s[r], s[r - 1]), get(l + 1, r, s[r], s[l])));
    }

    /*for (int i = 0; i + cnt <= n; ++i) {
      per(i, i + cnt - 1, dp[i][i + cnt]);
    }*/
  }
  if (dp[0][n] == 1) {
    cout << "Alice\n";
  } else if (dp[0][n] == -1) {
    cout << "Bob\n";
  } else {
    cout << "Draw\n";
  }
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}
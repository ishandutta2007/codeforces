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

struct Pred {
  int cnt, sum1, sum2;
};

const int N = 47;

Pred pr[N][N][N][N];

const int INF = 1e9 + 7;

void solve() {
  int n, A, B;
  cin >> n >> A >> B;

  int total = 0;

  string s;
  cin >> s;
  for (char c : s) {
    total += (c - '0');
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k < A; ++k) {
        for (int l = 0; l < B; ++l) {
          pr[i][j][k][l] = {-1, -1, -1};
        }
      }
    }
  }

  pr[0][0][0][0] = {0, 0, 0};

  for (int i = 0; i < n; ++i) {
    for (int cnt = 0; cnt <= n; ++cnt) {
      for (int sum1 = 0; sum1 < A; ++sum1) {
        for (int sum2 = 0; sum2 < B; ++sum2) {
          if (pr[i][cnt][sum1][sum2].cnt == -1) continue;

          pr[i + 1][cnt + 1][(sum1 * 10 + (s[i] - '0')) % A][sum2] = {cnt, sum1, sum2};
          pr[i + 1][cnt][sum1][(sum2 * 10 + (s[i] - '0')) % B] = {cnt, sum1, sum2};
        }
      }
    }
  }

  int rres = INF;
  string res = "#";

  for (int cnt = 1; cnt < n; ++cnt) {
    if (pr[n][cnt][0][0].cnt == -1) continue;

    if (rres <= abs(2 * cnt - n)) {
      continue;
    }

    rres = abs(2 * cnt - n);
    res = "";
    int ncnt = cnt, nsum1 = 0, nsum2 = 0;
    for (int i = n; i > 0; --i) {
      auto t = pr[i][ncnt][nsum1][nsum2];
      if (t.cnt == ncnt) {
        res += 'B';
      } else {
        res += 'R';
      }
      ncnt = t.cnt, nsum1 = t.sum1, nsum2 = t.sum2;
    }
    reverse(all(res));
  }

  if (rres == INF) {
    cout << "-1\n";
  } else {
    cout << res << "\n";
  }
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}
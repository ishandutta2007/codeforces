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


int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector <int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  vector<int> adds = {0, -1, 1, 0};

  int res = 0;
  for (int mask = 0; mask < 4; ++mask) {
    int need = -1;
    if (mask & 1) {
      need = h[n - 1]; 
    }
    if (mask & 2) {
      need = h[0];
    }
    if (mask == 3 && h[0] != h[n - 1]) break;
    if (mask && mask != 3 && h[0] == h[n - 1]) continue;

    int mlt = (need != -1 ? 1 : k - 1 - (h[0] != h[n - 1])) % mod;

    vector<vector<int>> ways(n, vector<int>(2 * n + 2, 0));
    ways[0][n + adds[mask]] = mlt;

    for (int i = 0; i + 1 < n; ++i) {
      for (int j = 0; j < 2 * n + 2; ++j) {
        if (!ways[i][j]) continue;

        for (int mask = 0; mask < 4; ++mask) {
          int need = -1;
          if (mask & 1) {
            need = h[i + 1]; 
          }
          if (mask & 2) {
            need = h[i];
          }
          if (mask == 3 && h[i] != h[i + 1]) break;
          if (mask && mask != 3 && h[i] == h[i + 1]) continue;

          int mlt = (need != -1 ? 1 : k - 1 - (h[i] != h[i + 1])) % mod;

          if (j + adds[mask] >= 0 && j + adds[mask] < 2 * n + 2) {
            add(ways[i + 1][j + adds[mask]], mult(ways[i][j], mlt));
          }
        }
      }
    }


    for (int i = 0; i < n; ++i) {
      add(res, ways[n - 1][i]);
    }
    //per(mask, mlt, res);
  }

  cout << res << "\n";
}
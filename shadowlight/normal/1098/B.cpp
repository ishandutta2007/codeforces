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

int res = -1;
bool swapped = false;
vector<vector<char>> ans;

string tet = "AGCT";

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  for (int it = 0; it < 2; ++it) {
    for (int x = 0; x < 4; ++x) {
      for (int y = x + 1; y < 4; ++y) {
        for (int z = 0; z < 4; ++z) {
          if (z == x || z == y) continue;
          int w = 6 - x - y - z;

          vector<int> p = {x, y, z, w};

          vector<vector<char>> b(n, vector<char>(m));
          int sum = 0;

          for (int i = 0; i < n; ++i) {
            int mx = -1;
            for (int d = 0; d < 2; ++d) {
              int now = 0;
              for (int j = 0; j < m; ++j) {
                int pos = (i % 2) * 2 + (j % 2) ^ d;
                now += (tet[p[pos]] == a[i][j]); 
              }
              if (now > mx) {
                mx = now;
                for (int j = 0; j < m; ++j) {
                  int pos = (i % 2) * 2 + (j % 2) ^ d;
                  b[i][j] = tet[p[pos]];
                }
              }
            }
            sum += mx;
          }

          if (sum > res) {
            res = sum;
            ans = b;
            swapped = it;
          }

          break;
        }
      }
    }
    vector<vector<char>> b(m, vector<char>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        b[j][i] = a[i][j];
      }
    }
    swap(n, m);
    a = b;
  }

  if (swapped) {
    swap(n, m);
    vector<vector<char>> b(m, vector<char>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        b[j][i] = ans[i][j];
      }
    }
    swap(n, m);
    ans = b;
  }

  per(res);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j];
    }
    cout << "\n";
  }

}
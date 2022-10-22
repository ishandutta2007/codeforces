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
set<int> ys[N];

db intersect(pair<int, int> a, pair<int, int> b) {
  assert(a.x != b.x);

  return (b.y - a.y) / (db)(a.x - b.x);
}

int main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
  cin >> n >> m;
  ++n, ++m;

  vector <string> field(n);

  for (int i = 0; i < n; ++i) {
    cin >> field[i];
    for (int j = 0; j < m; ++j) {
      if (field[i][j] == '1') {
        ys[i].insert(j);
      }
    }
  }

  ll res = 0;
  for (int y = 0; y < m; ++y) {
    vector <pair<int, int>> optimal;
    for (int x = 0; x < n; ++x) {
      auto it = ys[x].lower_bound(y);
      for (int iter = 0; iter < 2; ++iter) {
        if (it != ys[x].end()) {
          optimal.pb({x, *it});
        }
        if (it == ys[x].begin()) break;
        --it;
      }
    }
    vector <pair<int, int>> coefs;
    for (auto t : optimal) {
      int b = (t.x * t.x + t.y * t.y - 2 * y * t.y);
      int k = (-2 * t.x);
      coefs.pb({k, b});
    }
    sort(all(coefs), [&](pair<int, int> a, pair<int, int> b) {
      if (a.x == b.x) {
        return a.y > b.y;
      }
      return a.x > b.x;
    });

    vector <pair<db, pair<int, int>>> st;
    for (auto t : coefs) {
      while (st.size()) {
        if (st.back().y.x == t.x) {
          st.pop_back();
        } else {
          db x = intersect(st.back().y, t);
          if (x <= st.back().x) {
            st.pop_back();
          } else {
            break;
          }
        }
      }
      if (!st.size()) {
        st.pb({-1e36, t}); 
      } else {
        db x = intersect(st.back().y, t);
        st.pb({x, t});
      }
    }

    int now = 0;
    for (int x = 0; x < n; ++x) {
      int ans = st[now].y.x * x + st[now].y.y;
      while (now + 1 < st.size()) {
        int nans = st[now + 1].y.x * x + st[now + 1].y.y;
        if (nans < ans) {
          ans = nans, now++;
        } else {
          break;
        }
      }
      res += ans + x * x + y * y;
      //per(x, y, ans + x * x + y * y);
    }
  }
  cout << res << "\n";
}
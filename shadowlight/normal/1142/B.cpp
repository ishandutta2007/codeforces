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
const int INF = 1e9 + 7;

struct Tree {
  int n;
  vector<int> t;

  Tree(int n, vector<int>& a) : n(n), t(2 * n) {
    for (int i = 0; i < n; ++i) {
      t[i + n] = a[i];
    }
    for (int i = n - 1; i >= 1; --i) {
      t[i] = min(t[2 * i], t[2 * i + 1]);
    }
  }

  int get(int l, int r) {
    int res = INF;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l % 2) {
        res = min(res, t[l++]);
      }
      if (r % 2 == 0) {
        res = min(res, t[r--]);
      }
    }
    return res;
  }
};

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m, q;
  cin >> n >> m >> q;

  vector<int> p(n), a(m);
  vector<int> where(n);

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    where[p[i]] = i;
  }

  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    --a[i];
  }
  vector<int> pos(n, -1);
  vector<int> nxt(m, -1);
  for (int i = m - 1; i >= 0; --i) {
    int now = where[a[i]];
    now = (now + 1) % n;
    if (pos[p[now]] != -1) {
      nxt[i] = pos[p[now]];
    }
    pos[a[i]] = i;
  }

  vector<vector<int>> binup(m, vector<int>(LOGN, -1));
  for (int i = m - 1; i >= 0; --i) {
    binup[i][0] = nxt[i];
    for (int j = 1; j < LOGN; ++j) {
      if (binup[i][j - 1] == -1) break;
      binup[i][j] = binup[binup[i][j - 1]][j - 1];
    }
  }

  vector <int> rpos(m);
  for (int i = 0; i < m; ++i) {
    int res = i;
    for (int j = LOGN - 1; j >= 0; --j) {
      if (res == -1) break;
      if ((1 << j) & (n - 1)) {
        res = binup[res][j];
      }
    }
    rpos[i] = (res == -1 ? INF : res);
  }

  Tree tree(m, rpos);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << (tree.get(l, r) <= r);
  }
  cout << "\n";
}
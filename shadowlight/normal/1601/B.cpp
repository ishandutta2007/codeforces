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
const int INF = 1e9 + 7;

struct Tree {
  int n;
  vector<pair<int, int>> t;

  Tree(vector<int>& a) : n(a.size()), t(2 * n) {
    for (int i = 0; i < n; ++i) {
      t[i + n] = {a[i], i};
    }
    for (int i = n - 1; i > 0; --i) {
      t[i] = min(t[2 * i], t[2 * i + 1]);
    }
  }

  void change(int pos) {
    pos += n;
    t[pos] = {INF, pos - n};
    pos /= 2;
    while (pos) {
      t[pos] = min(t[2 * pos], t[2 * pos + 1]);
      pos /= 2;
    }
  }

  pair<int, int> get(int l, int r) {
    pair<int, int> res = {INF, -1};
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
        uin(res, t[l++]);
      }
      if (r % 2 == 0) {
        uin(res, t[r--]);
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

  int n;
  cin >> n;
  ++n;
  vector<int> a(n);
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    a[i] = i - a[i];
  }

  Tree tree(a);

  vector<int> dp(n, INF);
  vector<int> pr(n, -1);

  vector <vector<int>> gr(n);

  vector<int> b(n);
  for (int i = 1; i < n; ++i) {
    cin >> b[i];
    gr[i + b[i]].pb(i);
  }

  queue<int> q;
  q.push(0);
  dp[0] = 0;
  //tree.change(0);

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    while (true) {
      auto [jump, u] = tree.get(v + 1, n - 1);
      if (jump > v) break;
      tree.change(u);

      for (int x : gr[u]) {
        if (dp[x] != INF) continue;

        dp[x] = dp[v] + 1;
        pr[x] = v;
        q.push(x);
      }
    }
  }

  //per(dp);

  int res = INF;
  int nxt = -1;

  for (int x = n - 1; x >= a[n - 1]; --x) {
    if (dp[x] + 1 < res) {
      res = dp[x] + 1;
      nxt = x;
    }
  }

  if (res == INF) {
    cout << "-1\n";
    return 0;
  }

  cout << res << "\n";
  while (nxt != 0) {
    cout << nxt << " ";
    nxt = pr[nxt];
  }
  cout << 0 << "\n";
}
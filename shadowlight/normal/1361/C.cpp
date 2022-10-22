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
vector <vector<pair<int, int>>> gr;
vector<vector<int>> values;
vector <bool> used;
vector <int> res;
vector <int> iter;
vector <int> a, b;

bool dfs(int v) {
  bool added = false;
  //cout << v << " " << iter[v] << " " << gr[v].size() << endl;
  //per(res);
  while (iter[v] < gr[v].size()) {
    int u = gr[v][iter[v]].x;
    int num = gr[v][iter[v]].y;
    if (used[num / 2]) {
      ++iter[v];
      continue;
    }

    ++iter[v];
    used[num / 2] = true;
    dfs(u);
    res.pb(num ^ 1);
    res.pb(num);
    if ((num & 1) == 0) {
      assert(a[num / 2] == v);
      auto& t = values[a[num / 2]];
      while (t.size()) {
        res.pb(2 * t.back());
        res.pb(2 * t.back() + 1);
        t.pop_back();
      }
    } else {
      assert(b[num / 2] == v);
      auto& t = values[b[num / 2]];
      while (t.size()) {
        res.pb(2 * t.back());
        res.pb(2 * t.back() + 1);
        t.pop_back();
      }
    }
    added = true;
  }
  return added;
}

int n;
void check(vector<int> c) {
  assert(c.size() == 2 * n);
  vector <bool> exists(2 * n, 0);
  for (int x : c) {
    assert(x >= 0 && x < 2 * n);
    assert(!exists[x]);
    exists[x] = true;
  }
  for (int i = 0; i < 2 * n; i += 2) {
    assert((c[i] ^ 1) == c[i + 1]);
    int x = ((c[i + 1] & 1) ? b[c[i + 1] / 2] : a[c[i + 1] / 2]);
    int p = (i + 2) % (2 * n);
    int y = ((c[p] & 1) ? b[c[p] / 2] : a[c[p] / 2]);
    //per("PAIRS", x, y);
    assert(x == y);
  }
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  a.resize(n), b.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  for (int d = LOGN; d >= 0; --d) {
    gr.assign((1 << d), {});
    values.assign((1 << d), {});

    for (int i = 0; i < n; ++i) {
      a[i] %= (1 << d);
      b[i] %= (1 << d);
      if (a[i] != b[i]) {
        gr[a[i]].pb({b[i], 2 * i});
        gr[b[i]].pb({a[i], 2 * i + 1});
      } else {
        values[a[i]].pb(i);
      }
    }
    if (n == 1) {
      if (a[0] == b[0]) {
        cout << d << "\n";
        cout << "1 2\n";
        return 0;
      }
      continue;
    }
    bool bad = false;
    for (int i = 0; i < (1 << d); ++i) {
      if (gr[i].size() % 2) {
        bad = true;
        break;
      }
    }
    if (bad) continue;
    int cnt = 0;
    used.assign(n, false);
    iter.assign((1 << d), 0);
    res.clear();
    for (int v = 0; v < (1 << d); ++v) {
      cnt += dfs(v);
    }
    if (!res.size()) {
      for (int i = 0; i < (1 << d); ++i) {
        if (values[i].size() == n) {
          for (int j = 0; j < n; ++j) {
            res.pb(2 * j);
            res.pb(2 * j + 1);
          }
          break;
        }
      }
    }
    if (cnt > 1 || res.size() != 2 * n) {
      continue;
    }
    /*for (int i = 0; i < n; ++i) {
      per(a[i], b[i]);
    }*/
    cout << d << "\n";
    for (int x : res) {
      cout << x + 1 << " ";
    }
    cout << "\n";
    check(res);
    exit(0);
  }
  assert(false);
}
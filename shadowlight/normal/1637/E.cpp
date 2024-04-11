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

const int SQ = sqrt(3e5 + 7);
vector<int> smalls[SQ];

void solve() {
  int n, m;
  cin >> n >> m;


  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }

  vector<pair<int, int>> values;
  vector<int> counts;
  vector<int> a;
  map<int, int> posq;
  for (auto t : cnt) {
    values.pb({t.y, t.x});
  }
  sort(all(values), greater<pair<int, int>>());
  n = values.size();
  
  int bigs = 0;
  for (int i = 0; i < n; ++i) {
    bigs += (values[i].x >= SQ);
    a.pb(values[i].y);
    counts.pb(values[i].x);
    posq[values[i].y] = i;
    if (values[i].x < SQ) {
      smalls[values[i].x].pb(i);
    }
  }
  assert(bigs < SQ);

  //per(counts, a);


  vector<vector<int>> gr(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x = posq[x];
    y = posq[y];

    gr[x].pb(y);
    gr[y].pb(x);
  }
  for (int i = 0; i < n; ++i) {
    sort(all(gr[i]));
  }

  ll res = 0;

  for (int v = 0; v < bigs; ++v) {
    int now = 0;
    for (int u = 0; u < n; ++u) {
      if (v == u) continue;
      if (now < gr[v].size() && gr[v][now] == u) {
        ++now;
        continue;
      }


      uax(res, (counts[v] + counts[u]) * (ll) (a[v] + a[u]));
      //per(v, u, res);
    }
  }

  for (int cnt1 = 0; cnt1 < SQ; ++cnt1) {
    for (int v : smalls[cnt1]) {
      int now = 0;
      for (int cnt2 = SQ - 1; cnt2 >= 0; --cnt2) {
        while (now < (int) gr[v].size() && counts[gr[v][now]] > cnt2) ++now;

        int pos = 0;
        while (pos < (int) smalls[cnt2].size()) {
          int u = smalls[cnt2][pos];
          if (now < (int) gr[v].size() && gr[v][now] == u) {
            ++now, ++pos;
            continue;
          }
          if (u == v) {
            ++pos;
            continue;
          }
          break;
        }

        if (pos != smalls[cnt2].size()) {
          int u = smalls[cnt2][pos];


          uax(res, (counts[v] + counts[u]) * (ll) (a[v] + a[u]));
          //per(v, u, res);
        }
      }
    }
  }


  cout << res << "\n";

  for (int x : counts) {
    if (x < SQ) smalls[x].clear();
  }
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}
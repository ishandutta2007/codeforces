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

const ll INF = 1e18 + 7;

vector<vector<pair<int, int>>> gr;

struct line {
  char type;
  double x;
  ll k, n;
};
 
bool operator<(line l1, line l2) {
  if (l1.type+l2.type>0) return l1.x<l2.x;
  else return l1.k>l2.k;
}
 
struct st{
  set<line> env;
  typedef set<line>::iterator sit;
 
  bool hasPrev(sit it) { return it!=env.begin(); }
  bool hasNext(sit it) { return it!=env.end() && next(it)!=env.end(); }
 
  double intersect(sit it1, sit it2) {
    return (double)(it1->n-it2->n)/(it2->k-it1->k);
  }
 
  void calcX(sit it) {
    if (hasPrev(it)) {
      line l = *it;
      l.x = intersect(prev(it), it);
      env.insert(env.erase(it), l);
    }
  }
 
  bool irrelevant(sit it) {
    //if (hasNext(it) && next(it)->n <= it->n) return true; // x=0 cutoff //useless
    return hasPrev(it) && hasNext(it) && intersect(prev(it),next(it)) <= intersect(prev(it),it);
  }
 
  void add(ll k, ll a) {
    sit it;
    // handle collinear line
    it=env.lower_bound({0,0,k,a});
    if (it!=env.end() && it->k==k) {
      if (it->n <= a) return;
      else env.erase(it);
    }
    // erase irrelevant lines
    it=env.insert({0,-1000000,k,a}).first;
    if (irrelevant(it)) { env.erase(it); return; }
    while (hasPrev(it) && irrelevant(prev(it))) env.erase(prev(it));
    while (hasNext(it) && irrelevant(next(it))) env.erase(next(it));
    // recalc left intersection points
    if (hasNext(it)) calcX(next(it));
    calcX(it);
  }
 
  ll query(ll x) {
    auto it = env.upper_bound((line){1,(double)x,0,0});
    it--;
    return it->n+x*it->k;
  }
};

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  gr.resize(n);

  for (int i = 0; i < m; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    --v, --u;
    gr[v].pb({u, w});
    gr[u].pb({v, w});
  }

  vector<ll> dist(n, INF);
  dist[0] = 0;

  for (int i = 0; i <= k; ++i) {
    set<pair<ll, int>> q;
    for (int i = 0; i < n; ++i) {
      q.insert({dist[i], i});
    }
    while (!q.empty()) {
      auto [d, v] = *q.begin();
      q.erase(q.begin());
      for (auto [u, w] : gr[v]) {
        if (d + w < dist[u]) {
          q.erase({dist[u], u});
          dist[u] = d + w;
          q.insert({dist[u], u});
        }
      }
    }

    if (i == k) break;
    st cht;
    for (int i = 0; i < n; ++i) {
      cht.add(-2 * i, dist[i] + i * (ll) i);
    }
    for (int i = 0; i < n; ++i) {
      ll res = cht.query(i);
      uin(dist[i], res + i * (ll) i);
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << dist[i] << " ";
  }
  cout << "\n";


}
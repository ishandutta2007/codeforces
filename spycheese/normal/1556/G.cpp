#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ipair;
typedef pair <ll, ll> lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = numeric_limits<double>::infinity();
const double DNAN = numeric_limits<double>::quiet_NaN();
const double EPS = 1e-9;
const double PI = acos((double)-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

ll divFloor(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? a / b : (a - b + 1) / b; }
ll divCeil(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? (a + b - 1) / b : a / b; }
ll divFloorS(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? (a + b - 1) / b - 1 : a / b - 1; }
ll divCeilS(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? a / b + 1 : (a - b + 1) / b + 1; }

template<typename K, typename V> V getOrDef(map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename K, typename V> V getOrDef(unordered_map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }

template<typename A, typename B> istream& operator >> (istream& in, pair<A, B>& p) { return in >> p.X >> p.Y; }
template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> const& p) { return out << p.X << " " << p.Y; }
template<typename T> istream& operator >> (istream& in, vector<T>& a) { for (T& x : a) in >> x; return in; }
template<typename T> ostream& operator << (ostream& out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) out << " ";
    f = false;
    out << x;
  }
  return out;
}

template<typename T> bool isZero(T const& x) { return x == T(0); }
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template<typename T> int sgn(T const& x) { if (isZero(x)) return 0; return x > 0 ? 1 : -1; }

struct Node {
  ll cl, cr;
  Node *l = nullptr;
  Node *r = nullptr;
  int id = -1;
  bool leaf = true;
  bool destroyed = 0;
  Node(ll cl, ll cr) : cl(cl), cr(cr) {}
};
struct Query {
  bool destroy;
  ll a, b;
};

void down1(ll l, ll r, Node *c) {
  if (l >= c->cr || c->cl >= r) return;
  if (l <= c->cl && c->cr <= r) {
    assert(c->leaf);
    c->destroyed = 1;
    return;
  }
  if (c->leaf) {
    assert(!c->destroyed);
    c->leaf = 0;
    ll mid = (c->cl + c->cr) / 2;
    c->l = new Node(c->cl, mid);
    c->r = new Node(mid, c->cr);
  }
  down1(l, r, c->l);
  down1(l, r, c->r);
}

vector<Node*> leafs;
vector<ll> cls;
void dfs2(Node *c) {
  if (c->leaf) {
    leafs.push_back(c);
    cls.push_back(c->cl);
  } else {
    dfs2(c->l);
    dfs2(c->r);
  }
}

struct DSU {
  vector<int> p;
  DSU() = default;
  DSU(int n) : p(n, -1) {}
  
  int get(int v) { return p[v] == -1 ? v : p[v] = get(p[v]); }
  bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    p[y] = x;
    return true;
  }
} dsu;

int k;
Node* root;

int main() {
  ios::sync_with_stdio(false);
  int qn;
  cin >> k >> qn;
  ll n = 1LL << k;
  vector<Query> qs; 
  root = new Node(0, n);
  for (int i = 0; i < qn; ++i) {
    string type;
    ll a, b;
    cin >> type >> a >> b;
    if (type == "block") {
      qs.push_back({1, a, b + 1});
      down1(a, b + 1, root);
    } else {
      qs.push_back({0, a, b});
    }
  }

  dfs2(root);
  for (int i = 0; i < sz(leafs); ++i)
    leafs[i]->id = i;
  dsu = DSU(sz(leafs));

  for (int id = 0; id < sz(leafs); ++id) {
    Node* c = leafs[id];
    if (c->destroyed) continue;
    ll len = c->cr - c->cl;
    for (int i = 0; i < k; ++i) {
      if ((1LL << i) < len) continue;
      ll nl = c->cl ^ (1LL << i);
      ll nr = nl + len;
      int j = upper_bound(all(cls), nl) - cls.begin() - 1;
      while (j < sz(cls) && cls[j] < nr) {
        if (!leafs[j]->destroyed) dsu.merge(id, j);
        j++;
      }
    }
  }

  vector<int> ans;
  reverse(all(qs));
  for (Query const& q : qs) {
    if (q.destroy) {
      int id1 = lower_bound(all(cls), q.a) - cls.begin();
      int id2 = lower_bound(all(cls), q.b) - cls.begin();
      for (int id = id1; id < id2; ++id) {
        Node* c = leafs[id];
        c->destroyed = false;
        ll len = c->cr - c->cl;
        for (int i = 0; i < k; ++i) {
          if ((1LL << i) < len) continue;
          ll nl = c->cl ^ (1LL << i);
          ll nr = nl + len;
          int j = upper_bound(all(cls), nl) - cls.begin() - 1;
          while (j < sz(cls) && cls[j] < nr) {
            if (!leafs[j]->destroyed) dsu.merge(id, j);
            j++;
          }
        }
      }
    } else {
      int id1 = upper_bound(all(cls), q.a) - cls.begin() - 1;
      int id2 = upper_bound(all(cls), q.b) - cls.begin() - 1;
      ans.push_back(dsu.get(id1) == dsu.get(id2));
    }
  }
  reverse(all(ans));
  for (int x : ans)
    cout << x << "\n";

  return 0;
}
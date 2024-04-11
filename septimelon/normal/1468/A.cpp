#ifdef LOCAL
//# define _GLIBCXX_DEBUG
#endif  // LOCAL

#include <memory.h>
namespace memory_manager {
const int mem_size = 305 * (int)1e6;

char mem[mem_size];
char* mem_ptr = mem;
char* saved_ptr;

void save() { saved_ptr = mem_ptr; }
void restore() { mem_ptr = saved_ptr; }
}

void* operator new(size_t count) {
  using memory_manager::mem_ptr;

  void* ret = mem_ptr;
  mem_ptr = mem_ptr + count;
  return ret;
}

void operator delete(void* ptr) noexcept {}

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for(int i=(a);i<(n);++i)
#define per(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()

template<typename T1, typename T2>
inline bool umin(T1& x, const T2& y) { return y < x ? x = y, true : false; }

template<typename T1, typename T2>
inline bool umax(T1& x, const T2& y) { return x < y ? x = y, true : false; }

typedef long long ll;
typedef long double ld;

const int maxn = (int) 5e5 + 5;
const int mod = (int) 1e9 + 7;
const int inf = (int) 1e9 + 17;
const ll llinf = (ll) 1e18 + 17;

class Ptree {
 public:
  struct Node {
    int mx;
    Node* lf;
    Node* rg;

    Node() {mx = 0; lf = rg = nullptr; }

    Node(int mx) : mx(mx) { lf = rg = nullptr; }

    Node(int tl, int tr) {
      mx = 0;
      lf = rg = nullptr;
      if (tl == tr) return;
      int tm = (tl + tr) / 2;
      lf = new Node(tl, tm);
      rg = new Node(tm + 1, tr);
    }

    Node(Node* lhs, Node* rhs) {
      this->mx = max(lhs->mx, rhs->mx);
      this->lf = lhs;
      this->rg = rhs;

    }
  };

  Ptree() { root = nullptr; }
  Ptree(int n) : n(n) {
    root = new Node(0, n - 1);
  }

  Ptree(const Ptree& other) {
    n = other.n;
    root = other.root;
  }

  inline void assign(int p, int x) {
    root = this->assign(root, p, x, 0, n - 1);
  }

  inline int getmax(int l, int r) const {
    if (r < l) return 0;
    return this->getmax(root, l, r, 0, n - 1);
  }

 private:
  int n;
  Node* root;

  Node* assign(Node* root, int p, int x, int tl, int tr) {
    if (tl == tr) return new Node(x);
    int tm = (tl + tr) / 2;
    if (p <= tm) return new Node(assign(root->lf, p, x, tl, tm), root->rg);
    return new Node(root->lf, assign(root->rg, p, x, tm + 1, tr));
  }

  int getmax(Node* root, int l, int r, int tl, int tr) const {
    assert(root != nullptr);
    if (l <= tl && tr <= r)
      return root->mx;
    int tm = (tl + tr) / 2;
    if (r <= tm) return getmax(root->lf, l, r, tl, tm);
    if (tm < l) return getmax(root->rg, l, r, tm + 1, tr);
    return max(getmax(root->lf, l, r, tl, tm), getmax(root->rg, l, r, tm + 1, tr));
  }
};


int n;
int a[maxn];
int prv[maxn];


void solve() {
  cin >> n;
  rep(i, 0, n) cin >> a[i];
  memory_manager::save();

  vector<int> order(a, a+n);
  sort(all(order));
  order.erase(unique(all(order)), end(order));

  prv[0] = -1;
  vector<pair<int,int>> s;
  rep(i, 0, n) {
    a[i] = lower_bound(all(order), a[i]) - begin(order);
    while (!s.empty() && s.back().first <= a[i]) {
      s.pop_back();
    }
    if (!s.empty()) {
      prv[i] = s.back().second;
    } else {
      prv[i] = -1;
    }
    s.emplace_back(a[i], i);
  }

  vector<Ptree> t;
  t.reserve(n + 1);

  memory_manager::save();
  t.emplace_back(order.size());

  int ans = 0;
  rep(i, 0, n) {
    int dp = 1;
    umax(dp, t.back().getmax(0, a[i]) + 1);
    if (prv[i] != -1) {
      umax(dp, t[prv[i]].getmax(0, a[i]) + 2);
    }

    t.push_back(t.back());
    t.back().assign(a[i], dp);
    umax(ans, dp);
  }
  memory_manager::restore();
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t --> 0) {
    solve();
  }

  return 0;
}
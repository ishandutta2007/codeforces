#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair


struct InfType {
    static constexpr int int_inf = static_cast<int>(1e9 + 666);
    static constexpr ll ll_inf = (ll)3e18 + 666;

    operator int() const {
        return int_inf;
    }

    operator long long() const {
        return ll_inf;
    }
} const INF;

template<class T>
bool operator==(T val, const InfType& inf) {
    return val == T(inf);
}

const ll INFll = INF;
mt19937 rnd((uint32_t)chrono::high_resolution_clock::now().time_since_epoch().count());
// mt19937 rnd(666);

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline int bpow(ll a, ll b, int mod) {
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

template<class T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) {
        in >> x;
    }
    return in;
}

template<class TLambda>
struct YPredicate {
    YPredicate(TLambda&& l) : l_(l) {}

    template<class... TArgs>
    auto operator()(TArgs&&... args) {
        return l_(*this, std::forward<TArgs>(args)...);
    }

private:
    TLambda l_;
};

void run();

// #define TASK "taskname"

signed main() {
#if defined(TASK) && !defined(LOCAL)
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void solve();

void run() {
  int n;
  cin >> n;
  while (n --> 0) {
    solve();
  }
}

vector<int> count_before(const string& s, char a, char b) {
  vector<int> ans;
  int cnta = 0;
  for (auto c : s) {
    if (c == a) {
      ++cnta;
    } else if (c == b) {
      ans.pb(cnta);
    }
  }
  return ans;
}

string erase(string s, char c) {
  s.resize(remove_if(all(s), [c](char cc) { return cc == c; }) - s.begin());
  return s;
}

void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  {
    auto ss = s, tt = t;
    sort(all(ss)); sort(all(tt));
    if (ss != tt) {
      cout << "NO\n";
      return;
    }
  }
  if (erase(s, 'b') != erase(t, 'b')) {
    cout << "NO\n";
    return;
  }
  {
    vector<int> sab = count_before(s, 'a', 'b'), tab = count_before(t, 'a', 'b');
    for (int i = 0; i < len(sab); ++i) {
      if (sab[i] < tab[i]) {
        cout << "NO\n";
        return;
      }
    }
  }
  {
    vector<int> sbc = count_before(s, 'b', 'c'), tbc = count_before(t, 'b', 'c');
    for (int i = 0; i < len(sbc); ++i) {
      if (sbc[i] < tbc[i]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
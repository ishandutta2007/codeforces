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
// mt19937 rnd((uint32_t)chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937 rnd(666);

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
  int t;
  cin >> t;
  while (t --> 0) {
    solve();
  }
}

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string s;
  cin >> s;
  int cnt[2] = {0, 0};
  for (auto x : s) {
    ++cnt[x - 'A'];
  }
  if (cnt[0] != a + c + d || cnt[1] != b + c + d) {
    cout << "NO\n";
    return;
  }
  char last_c = s[0];
  int last_len = 0;
  int odd = 0;
  vector<int> even[2]; // {A...B, B...A}

  for (int i = 1; i < len(s); ++i) {
    if (s[i] == last_c && last_len != 0) {
      if (last_len & 1) {
        even['B' - last_c].pb((last_len + 1) >> 1);
      } else {
        odd += (last_len >> 1);
      }
      last_len = 0;
    }
    if (s[i] != last_c) {
      ++last_len;
    }
    last_c = s[i];
  }
  if (last_len != 0) {
    if (last_len & 1) {
      even['B' - last_c].pb((last_len + 1) >> 1);
    } else {
      odd += (last_len >> 1);
    }
    last_len = 0;
  }

  sort(all(even[0]));
  reverse(all(even[0]));
  sort(all(even[1]));
  reverse(all(even[1]));

  int curc = accumulate(all(even[0]), 0), curd = accumulate(all(even[1]), 0);
  for (int i = 0; i < len(even[0]) && curc > c; ++i) {
    curc -= even[0][i];
    odd += even[0][i] - 1;
  }
  for (int i = 0; i < len(even[1]) && curd > d; ++i) {
    curd -= even[1][i];
    odd += even[1][i] - 1;
  }

  assert(curc <= c && curd <= d);
  if (c + d - curc - curd <= odd) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

}
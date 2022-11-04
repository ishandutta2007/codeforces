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


struct NegativeInfType;

struct PositiveInfType {
    static constexpr std::tuple infinities{
      // static_cast<int>(1e9) + 666,
      static_cast<int>(1 << 30),
      static_cast<ll>(1e18) + 666,
      static_cast<double>(1e40l),
      static_cast<float>(1e25),
    };

    template<class T>
    operator T() const {
      return get<T>(infinities);
    }

    NegativeInfType operator-() const;
} const INF;

struct NegativeInfType {
    template<class T>
    operator T() const {
        return -(T)INF;
    }
};

NegativeInfType PositiveInfType::operator-() const {
    return {};
}

template<class T>
bool operator==(T val, const PositiveInfType& inf) {
    return val == T(inf);
}

template<class T>
bool operator==(T val, const NegativeInfType& neg_inf) {
    return val == T(neg_inf);
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

template<class T, size_t N>
istream& operator>>(istream& in, array<T, N>& v) {
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

inline int GetBit(int val, int pos) {
  return (val >> pos) & 1;
}

inline int SetBit(int val, int pos, int b) {
  return val |= (b << pos);
}

void run() {
  constexpr int mod = 998'244'353;
  constexpr int bits = 3 + 3;
  constexpr int states = 1 << bits;

  string s;
  cin >> s;
  int n = len(s);

  array<int, states> dp1{}, dp2{};
  // Bits:
  // a/b/c has the same prefix as n
  // 1...7 -- who has leadership potential (a^b, b^c, a^c), 0 -- leader defeated

  dp1[0b111111] = 1;
  for (int i = 0; i < n; ++i) {
    for (int state = 0; state < states; ++state) {
      const int pref = state & 7;
      const int leaders = state >> 3;
      const int chr = s[i] - '0';
      const int abound = chr || !GetBit(pref, 0);
      const int bbound = chr || !GetBit(pref, 1);
      const int cbound = chr || !GetBit(pref, 2);
      for (int na = 0; na <= abound; ++na) {
        for (int nb = 0; nb <= bbound; ++nb) {
          for (int nc = 0; nc <= cbound; ++nc) {
            int npref = 0;
            npref = SetBit(npref, 0, GetBit(pref, 0) && (na == chr));
            npref = SetBit(npref, 1, GetBit(pref, 1) && (nb == chr));
            npref = SetBit(npref, 2, GetBit(pref, 2) && (nc == chr));

            int ab = na ^ nb, bc = nb ^ nc, ac = na ^ nc;
            int leader_attendees = 0;
            leader_attendees = SetBit(leader_attendees, 0, ab);
            leader_attendees = SetBit(leader_attendees, 1, bc);
            leader_attendees = SetBit(leader_attendees, 2, ac);
            if (leader_attendees == 0) {
              leader_attendees = 7;
            }
            int nleaders = leader_attendees & leaders;

            int nstate = npref | (nleaders << 3);
            if (int& dp = (dp2[nstate] += dp1[state]); dp >= mod) {
              dp -= mod;
            }
          }
        }
      }
    }
    dp1 = dp2;
    fill(all(dp2), 0);
  }
  int ans = 0;
  for (int i = 0; i < 8; ++i) {
    ans += dp1[i];
    if (ans >= mod) {
      ans -= mod;
    }
  }
  cout << ans << endl;
}
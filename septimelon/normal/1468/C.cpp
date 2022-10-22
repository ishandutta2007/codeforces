#ifdef LOCAL
//# define _GLIBCXX_DEBUG
#endif  // LOCAL

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()

template <typename T1, typename T2>
inline bool umin(T1& x, const T2& y) {return y<x ? x=y,true : false;}

template <typename T1, typename T2>
inline bool umax(T1& x, const T2& y) {return x<y ? x=y,true : false;}

typedef long long ll;
typedef long double ld;

const int maxn = (int)2e5+5;
const int mod  = (int)1e9+7;
const int inf  = (int)1e9+17;
const ll llinf = (ll)1e18+17;


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int q;
  cin >> q;

  set<pair<int,int>> f_order;
  set<pair<int,int>> s_order;

  auto Extract = [](set<pair<int,int>>& f, set<pair<int,int>>& s) {
    auto w = *begin(f);
    f.erase(begin(f));
    s.erase({w.second, w.first});
    return w;
  };

  int guest_id = 1;
  while (q --> 0) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      f_order.insert({guest_id, -x});
      s_order.insert({-x, guest_id});
      ++guest_id;
    } else if (t == 2) {
      cout << Extract(f_order, s_order).first << ' ';
    } else if (t == 3) {
      cout << Extract(s_order, f_order).second << ' ';
    }
  }
  return 0;
}
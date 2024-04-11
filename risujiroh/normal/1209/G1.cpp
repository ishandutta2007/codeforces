#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

// Description: set(map)O(log)
 
// #### attention! : [l, r] ( include r, not [l, r) )
class SegmentMap : public std::map<signed, signed> {
private:
    bool flagToMergeAdjacentSegment;
public:
    // if merge [l, c] and [c+1, r], set flagToMergeAdjacentSegment to true
    SegmentMap(bool flagToMergeAdjacentSegment) :
        flagToMergeAdjacentSegment(flagToMergeAdjacentSegment) {}
    // __exist -> iterator pair(l, r) (contain p)
    // noexist -> map.end()
    auto get(signed p) const {
        auto it = upper_bound(p);
        if (it == begin() || (--it)->second < p) return end();
        return it;
    }
    // insert segment [l, r]
    void insert(signed l, signed r) {
        auto itl = upper_bound(l), itr = upper_bound(r + flagToMergeAdjacentSegment);
        if (itl != begin()) {
            if ((--itl)->second < l - flagToMergeAdjacentSegment) ++itl;
        }
        if (itl != itr) {
            l = std::min(l, itl->first);
            r = std::max(r, std::prev(itr)->second);
            erase(itl, itr);
        }
        (*this)[l] = r;
    }
    // remove segment [l, r]
    void remove(signed l, signed r) {
        auto itl = upper_bound(l), itr = upper_bound(r);
        if (itl != begin()) {
            if ((--itl)->second < l) ++itl;
        }
        if (itl == itr) return;
        int tl = std::min(l, itl->first), tr = std::max(r, std::prev(itr)->second);
        erase(itl, itr);
        if (tl < l) (*this)[tl] = l - 1;
        if (r < tr) (*this)[r + 1] = tr;
    }
    // Is p and q in same segment?
    bool same(signed p, signed q) const {
        const auto&& it = get(p);
        return it != end() && it->first <= q && q <= it->second;
    }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  V<> a(n); for (auto&& e : a) cin >> e, --e;
  V<> l(200000, n), r(200000, -1);
  for (int i = 0; i < n; ++i) {
    r[a[i]] = i;
  }
  for (int i = n - 1; i >= 0; --i) {
    l[a[i]] = i;
  }

  SegmentMap mp(false);
  for (int x = 0; x < 200000; ++x) if (l[x] < r[x]) {
    mp.insert(l[x], r[x]);
  }
  int res = 0;
  for (const auto& e : mp) {
    map<int, int> c;
    for (int i = e.first; i <= e.second; ++i) {
      ++c[a[i]];
    }
    int mx = 0;
    for (const auto& f : c) {
      mx = max(mx, f.second);
    }
    res += e.second - e.first + 1 - mx;
  }
  cout << res << '\n';
}
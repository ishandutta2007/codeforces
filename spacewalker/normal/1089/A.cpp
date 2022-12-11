#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

pair<int, int> overlap(pair<int, int> a, pair<int, int> b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

// find range of x such that x + L <= v <= x + R
pair<int, int> xRangeIn(int L, int R, int v) {
    return {v - R, v - L};
};

bool inside(pair<int, int> range, int v) {
    return range.first <= v && v <= range.second;
}

vector<int> getSolution(int sum, const vector<int> &bounds) {
    vector<int> ans(bounds.size());
    int rem = sum;
    for (int i = 0; i < bounds.size(); ++i) {
        ans[i] = min(bounds[i], rem);
        rem -= ans[i];
    }
    return ans;
}

// Find the max x such that a is in [aoff[0] + x, aoff[1] + x]
// and similarly for boff.
// Return -1 if no such x exists.
int permX(pair<int, int> aoff, pair<int, int> boff, int a, int b) {
    auto arange = xRangeIn(aoff.first, aoff.second, a);
    auto brange = xRangeIn(boff.first, boff.second, b);
    auto ans = overlap(arange, brange);
    if (ans.first <= ans.second) return ans.second;
    else return -1;
}

vector<pair<int, int>> check3_0(int wr, int lr) {
    if (wr == 75 && lr <= 69) {
        vector<int> lsets = getSolution(lr, {23, 23, 23});
        return {{25, lsets[0]}, {25, lsets[1]}, {25, lsets[2]}};
    }
    // check if possible assuming one deuce
    int x = wr - 50;
    if (x - 2 <= lr && lr <= x + 44 && x >= 25) {
        vector<int> lsets = getSolution(lr - (x - 2), {23, 23});
        return {{x, x-2}, {25, lsets[0]}, {25, lsets[1]}};
    }
    return {};
}

vector<pair<int, int>> check3_1(int wr, int lr) {
    if (inside({75, 98}, wr) && inside({25, 94}, lr)) {
        vector<int> lsets = getSolution(lr - 25, {23, 23, 23});
        return {{wr - 75, 25}, {25, lsets[0]}, {25, lsets[1]}, {25, lsets[2]}};
    }
    // check if possible assuming A wins a deuce
    int x = permX({50, 73}, {23, 69}, wr, lr);
    if (x >= 25) {
        vector<int> lsets = getSolution(lr - 25 - (x - 2), {23, 23});
        return {{wr - 50 - x, 25}, {x, x-2}, {25, lsets[0]}, {25, lsets[1]}};
    }
    // check if possible assuming B wins a deuce
    x = permX({73, 73}, {0, 69}, wr, lr);
    if (x >= 25) {
        vector<int> lsets = getSolution(lr - x, {23, 23, 23});
        return {{x-2, x}, {25, lsets[0]}, {25, lsets[1]}, {25, lsets[2]}};
    }
    return {};
}

vector<pair<int, int>> check3_2(int wr, int lr) {
    if (inside({65, 111}, wr) && inside({50, 109}, lr)) {
        vector<int> lsets = getSolution(lr - 50, {23, 23, 13});
        vector<int> wsets = getSolution(wr - 65, {23, 23});
        return {{wsets[0], 25}, {wsets[1], 25}, {25, lsets[0]}, {25, lsets[1]}, {15, lsets[2]}};
    }
    // check if possible assuming A wins a non-TB deuce
    int x = permX({40, 86}, {48, 84}, wr, lr);
    if (x >= 25) {
        vector<int> lsets = getSolution(lr - 50 - (x - 2), {23, 13});
        vector<int> wsets = getSolution(wr - x - 40, {23, 23});
        return {{wsets[0], 25}, {wsets[1], 25}, {x, x-2}, {25, lsets[0]}, {15, lsets[1]}};
   }
   // check if possible assuming B wins a non-TB deuce
   x = permX({63, 86}, {25, 84}, wr, lr);
   if (x >= 25) {
        vector<int> lsets = getSolution(lr - 25 - x, {23, 23, 13});
        return {{x-2, x}, {wr - 65 - (x-2), 25}, {25, lsets[0]}, {25, lsets[1]}, {15, lsets[2]}};
   }
   // check if possible assuming TB is a deuce
   x = permX({50, 96}, {48, 94}, wr, lr);
   if (x >= 15) {
        vector<int> lsets = getSolution(lr - 50 - (x-2), {23, 23});
        vector<int> wsets = getSolution(wr - 50 - x, {23, 23});
        return {{wsets[0], 25}, {wsets[1], 25}, {25, lsets[0]}, {25, lsets[1]}, {x, x-2}};
   }
   return {};
}

void report(const vector<pair<int, int>> &ans) {
    if (ans.empty()) {
        cout << "Impossible" << "\n";
        return;
    }
    int ascore = 0, bscore = 0;
    for (auto [ap, bp] : ans) (ap > bp ? ascore : bscore)++;
    cout << ascore << ":" << bscore << "\n";
    for (auto [ap, bp] : ans) cout << ap << ":" << bp << " ";
    cout << "\n";
}

void solve(int a, int b) {
    vector<vector<pair<int, int>>> cases{
        check3_0(a, b), check3_1(a, b), check3_2(a, b), check3_2(b, a), check3_1(b, a), check3_0(b, a)
    };
    for (int i = 3; i < cases.size(); ++i) {
        for (auto& [ap, bp] : cases[i]) swap(ap, bp);
    }
    for (auto &v : cases) {
        if (!v.empty()) {
            // check that this is valid
            int awin = 0, bwin = 0;
            for (int i = 0; i < v.size(); ++i) {
                auto [a, b] = v[i];
                assert(max(a, b) >= (i < 4 ? 25 : 15));
                assert(abs(a - b) >= 2);
                if (a > b) ++awin;
                else ++bwin;
            }
            assert(max(awin, bwin) == 3);
            report(v);
            return;
        }
    }
    report({}); // impossible
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m; cin >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        solve(a, b);
    }
    /*
    for (int a = 0; a <= 200; ++a) {
        for (int b = 0; b <= 200; ++b) {
            cout << "TEST A=" << a << " " << "B=" << b << endl;
            solve(a, b);
        }
    }
    */
}
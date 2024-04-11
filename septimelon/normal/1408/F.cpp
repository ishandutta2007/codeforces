#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;
const ll MOD = 998244353;

vector<int> fir;
vector<int> sec;

set<int> fuse(set<int>& s1, set<int>& s2) {
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    set<int> fusion;
    for (int i = 0; i < s1.size(); ++i) {
        fir.push_back(*it1);
        sec.push_back(*it2);
        fusion.insert(*it1);
        fusion.insert(*it2);
        ++it1;
        ++it2;
    }
    return fusion;
}

pair<set<int>, set<int>> fuse(set<int> gre, set<int> sma, int one) {
    pair<set<int>, set<int>> rez;
    auto itg = gre.begin(), its = sma.begin();
    int csma = 1;
    vector<int> ones({ one });
    while (csma <= sma.size()) {
        if (sma.size() & csma) {
            for (int i = 0; i < csma; ++i) {
                ones.push_back(*its);
                fir.push_back(ones[i]);
                sec.push_back(*its);
                ++its;
            }
        }
        else {
            for (int i = 0; i < csma; ++i) {
                ones.push_back(*itg);
                fir.push_back(ones[i]);
                sec.push_back(*itg);
                ++itg;
            }
        }
        csma *= 2;
    }

    pair<set<int>, set<int>> ans;
    for (int i = 0; i < csma; ++i) {
        ans.second.insert(ones[i]);
    }
    while (itg != gre.end()) {
        ans.first.insert(*itg);
        ++itg;
    }

    if (ans.first.size() < ans.second.size()) {
        swap(ans.first, ans.second);
    }

    return ans;
}

pair<set<int>, set<int>> linear(int l, int r) {
    if (r - l == 1) {
        return { {l}, {} };
    }
    int len = (r - l) / 2;
    pair<set<int>, set<int>> left = linear(l, l + len), righ = linear(l + len, l + len * 2);
    pair<set<int>, set<int>> ans = { fuse(left.first, righ.first), fuse(left.second, righ.second) };
    if ((r - l) % 2 == 1) {
        ans = fuse(ans.first, ans.second, r - 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    linear(1, n + 1);

    cout << fir.size() << "\n";
    for (int i = 0; i < fir.size(); ++i) {
        cout << fir[i] << " " << sec[i] << "\n";
    }

    return 0;
}
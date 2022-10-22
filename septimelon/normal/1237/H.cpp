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

string rev(string s) {
    if (s == "10") {
        return "01";
    }
    if (s == "01") {
        return "10";
    }
    return s;
}

void solve() {
    string a, b;
    cin >> a >> b;

    map<string, int> ca, cb, del;
    ca["00"] = 0;
    ca["01"] = 0;
    ca["10"] = 0;
    ca["11"] = 0;
    cb = ca;
    del = ca;
    for (int i = 0; i < a.size(); i += 2) {
        ++ca[a.substr(i, 2)];
        ++cb[b.substr(i, 2)];
    }

    if (ca["00"] != cb["00"] || ca["11"] != cb["11"]) {
        cout << "-1\n";
        return;
    }

    vector<int> ans;
    int lastr = 0;

    if (ca["10"] != cb["01"]) {
        for (int i = 0; i < a.size(); i += 2) {
            ++del[a.substr(i, 2)];
            if (del["01"] + ca["10"] - del["10"] == cb["01"]) {
                reverse(a.begin(), a.begin() + i + 2);
                ans.push_back(i + 2);
                ca["10"] += del["01"] - del["10"];
                ca["01"] += del["10"] - del["01"];
                break;
            }
        }
    }

    del["10"] = 0;
    del["01"] = 0;
    if (ca["10"] != cb["01"]) {
        for (int i = 0; i < a.size(); i += 2) {
            ++del[b.substr(i, 2)];
            if (del["01"] + cb["10"] - del["10"] == ca["01"]) {
                reverse(b.begin(), b.begin() + i + 2);
                lastr = i + 2;
                cb["10"] += del["01"] - del["10"];
                cb["01"] += del["10"] - del["01"];
                break;
            }
        }
    }

    if (ca["10"] != cb["01"]) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < a.size(); i += 2) {
        for (int j = i; j < a.size(); j += 2) {
            if (rev(a.substr(j, 2)) == b.substr(a.size() - i - 2, 2)) {
                if (j > 0) {
                    ans.push_back(j);
                    reverse(a.begin(), a.begin() + j);
                }
                ans.push_back(j + 2);
                reverse(a.begin(), a.begin() + j + 2);
                break;
            }
        }
    }

    if (lastr > 0) {
        ans.push_back(lastr);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }

    return 0;
}
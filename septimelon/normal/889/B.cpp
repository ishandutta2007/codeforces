#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
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

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e16;
const int INF = 2e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

bool append(string& s, string& t, char ch) {
    int si = s.find(ch), ti = t.find(ch);
    int il = si + 0 - ti, ir = si + t.size() - ti;
    for (int i = max(0, il); i < min<int>(s.size(), ir); ++i) {
        if (s[i] != t[i - il]) {
            return false;
        }
    }

    if (il <= 0) {
        if (ir >= s.size()) {
            s = t;
        }
        else {
            s = t + s.substr(ir);
        }
    }
    else {
        if (ir > s.size()) {
            s = s.substr(0, il) + t;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> ss('z' - 'a' + 1);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); ++j) {
            ss[s[i][j] - 'a'].push_back(i);
        }
    }

    vector<string> strings;
    vector<bool> useds(n, false), usedc('z' - 'a' + 1, false);
    for (int i = 0; i < n; ++i) {
        if (useds[i]) {
            continue;
        }
        useds[i] = true;
        string cs = s[i];
        queue<int> atch;
        for (int i = 0; i < cs.size(); ++i) {
            atch.push(cs[i] - 'a');
        }
        while (!atch.empty()) {
            int cc = atch.front();
            atch.pop();
            if (usedc[cc]) {
                continue;
            }
            usedc[cc] = true;
            for (int j = 0; j < ss[cc].size(); ++j) {
                if (useds[ss[cc][j]]) {
                    continue;
                }
                useds[ss[cc][j]] = true;
                string ns = s[ss[cc][j]];
                if (!append(cs, ns, 'a' + cc)) {
                    cout << "NO\n";
                    return 0;
                }
                for (int k = 0; k < ns.size(); ++k) {
                    atch.push(ns[k] - 'a');
                }
            }
        }
        strings.push_back(cs);
    }

    sort(strings.begin(), strings.end());
    string ans = "";
    for (int i = 0; i < strings.size(); ++i) {
        ans += strings[i];
    }
    set<char> chars;
    for (int i = 0; i < ans.size(); ++i) {
        if (chars.count(ans[i]) > 0) {
            cout << "NO\n";
            return 0;
        }
        chars.insert(ans[i]);
    }

    cout << ans << "\n";

    return 0;
}
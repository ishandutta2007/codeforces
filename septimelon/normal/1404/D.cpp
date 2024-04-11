#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int q = 0; q < 2; ++q) {
            for (int i = 1; i <= n; ++i) {
                cout << i << " ";
            }
        }
        cout << endl;
        return 0;
    }

    cout << "Second" << endl;

    vector<vector<int>> p(n);
    vector<int> inp(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        int a;
        cin >> a;
        --a;
        p[a].push_back(i);
        inp[i] = a;
    }

    vector<ll> ans;

    vector<bool> used(n, false);
    for (int i = 0; i < 2 * n; ++i) {
        if (used[i % n]) {
            continue;
        }
        int ci = i;
        while (!used[ci % n]) {
            ans.push_back(ci + 1);
            used[ci % n] = true;
            if (ci < n) {
                ci += n;
            }
            else {
                ci -= n;
            }
            if (p[inp[ci]][0] == ci) {
                ci = p[inp[ci]][1];
            }
            else {
                ci = p[inp[ci]][0];
            }
        }
    }

    vector<bool> inc(n * 2 + 1, true);
    for (int i = 0; i < ans.size(); ++i) {
        inc[ans[i]] = false;
    }
    vector<ll> altans;
    ll alts = 0LL;
    for (ll i = 1; i <= 2 * n; ++i) {
        if (inc[i]) {
            altans.push_back(i);
            alts += i;
        }
    }

    if (alts % (2 * n) == 0) {
        ans = altans;
    }


    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    int rez;
    cin >> rez;

    return 0;
}
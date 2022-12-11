#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const int MAXN = 1e5;

int main() {
#ifdef LOCAL
//    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    int MAXB = 60;
    vector<vector<ll>> byFirst(MAXB);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = MAXB - 1; j >= 0; --j) {
            if ((a[i] >> j) & 1) {
                byFirst[j].push_back(a[i]);
                break;
            }
        }
    }

    vector<ll> cur;
    for (int j = MAXB - 1; j >= 0; --j) {
        if (byFirst[j].size() == 0) {
            continue;
        }
        /*
        cerr <<"Start " << j << '\n';
        for (auto x : byFirst[j]) {
            cerr << x << ' ' ;
        }
        cerr << '\n';*/
        vector<ll> nxt;
        int p = 0;

        nxt.push_back(byFirst[j][0]);
        for (int i = 1; i < byFirst[j].size(); ++i) {
            ll x = byFirst[j][i];
            while (p < cur.size()) {
                if ((cur[p] >> j) & 1) {
                    break;
                }
                nxt.push_back(cur[p]);
                p++;
            }

            if (p == cur.size()) {
                cout << "No\n";
                return 0;
            }

            nxt.push_back(cur[p]);
            p++;
            nxt.push_back(x);
        }

        while (p < cur.size()) {
            nxt.push_back(cur[p]);
            p++;
        }

        cur = nxt;
    }

    cout << "Yes\n";
    for (auto x : cur) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}
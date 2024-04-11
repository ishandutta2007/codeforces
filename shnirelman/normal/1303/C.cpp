#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 500 + 13;
const int LOGN = 10;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
4
1 2 3 4
1
1 5
*/

set<int> g[A];

void solve() {
    string s;
    cin >> s;

    for(int i = 0; i < A; i++) {
        g[i].erase(g[i].begin(), g[i].end());
    }

    for(int i = 1; i < s.size(); i++) {
        int v = s[i] - 'a', u = s[i - 1] - 'a';

        g[v].insert(u);
        g[u].insert(v);
    }

    for(int i = 0; i < A; i++) {
        if(g[i].size() > 2) {
            cout << "NO" << endl;
            return;
        }
    }

    int v = -1;
    for(int i = 0; i < A; i++) {
        if(g[i].size() == 1 || g[i].size() == 2 && v == -1)
            v = i;
    }

    if(v == -1) {
        cout << "YES" << endl;
        for(int i = 0; i < A; i++) {
            cout << char('a' + i);
        }
        cout << endl;
        return;
    }

    string ans = "";
    vector<bool> used(A, false);

    while(ans.size() < A) {
        ans += char(v + 'a');
        used[v] = true;
        bool fl = false;
        for(auto u : g[v]) {
            if(!used[u]) {
                v = u;
                fl = true;
            } else if(ans[ans.size() - 2] - 'a' != u) {
                cout << "NO" << endl;
                return;
            }
        }

        if(!fl) {
            for(int i = 0; i < A; i++) {
                if(!used[i]) {
                    v = i;
                    fl = true;
                    break;
                }
            }
        }
    }

    cout << "YES" << endl;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}
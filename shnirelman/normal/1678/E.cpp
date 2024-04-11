#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int LOGN = 30;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        p[a[i]] = b[i];
    }

    int l = 0, r = n - 1;
    vector<int> res(n, -1);

    vector<bool> used(n, false);
    vector<int> extra;
    for(int i = 0; i < n; i++) {
        if(used[i])
            continue;

        vector<int> cyc;
        int v = i;
        while(!used[v]) {
            used[v] = true;
            cyc.push_back(v);
            v = p[v];
        }

        if(cyc.size() % 2 == 1) {
            extra.push_back(cyc.back());
            cyc.pop_back();
        }

        for(int j = 0; j < cyc.size(); j++) {
            res[cyc[j]] = (j % 2 == 0 ? r-- : l++);
        }
    }

    for(int x : extra) {
        res[x] = l++;
    }

    li ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(res[a[i]] - res[b[i]]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}
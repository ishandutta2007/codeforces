#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 34;

int n, m, s;
int a[N], b[N], c[N], ans[N], perm[N], pt[N], cur[N];

bool ok(int days) {
    // cout << "Days = " << days << endl;
    priority_queue<pair<int, int>> q;
    int curS = 0;
    auto add = [&](int minPower) {
        // cout << "add " << minPower << endl;
        while (curS < n && b[perm[curS]] >= minPower) {
            q.push(make_pair(-c[perm[curS]], perm[curS]));            
            // cout << "added " << perm[curS] + 1 << endl;
            curS++;
        }
    };

    int sumC = 0;

    for (int kek = 0; kek < m; kek += days) {
        add(a[pt[kek]]);
        if (q.empty()) return false;

        int ind = q.top().second;
        sumC -= q.top().first;
        q.pop();
        if (sumC > s) return false;

        for (int lol = kek; lol < min(m, kek + days); lol++)
            cur[pt[lol]] = ind;
    }

    for (int i = 0; i < m; i++) ans[i] = cur[i];
    return true;
}

void solve() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) perm[i] = i;
    for (int i = 0; i < m; i++) pt[i] = i;

    sort(perm, perm + n, [&](int i1, int i2) { return b[i1] > b[i2]; });
    sort(pt, pt + m, [&](int i1, int i2) { return a[i1] > a[i2]; });

    if (a[pt[0]] > b[perm[0]]) {
        cout << "NO\n";
        return;
    }

    int L = 0;
    int R = m + 1;
    ans[0] = -1;

    while (R - L > 1) {
        int M = (L + R) / 2;
        if (ok(M)) R = M;
        else L = M;
    }

    if (ans[0] == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < m; i++)
            cout << ans[i] + 1 << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
#ifdef SERT
    int t = 4;
    for (int i = 1; i < t; i++) {
        solve();
    }
#endif
}
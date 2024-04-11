#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

vector<int> g[1010];
int d[1010];

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    forn (i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        d[a]++;
        d[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> del(n);
    while (1) {
        int a = -1, b = -1;
        forn (i, n) {
            if (!del[i] && d[i] == 1) {
                if (a == -1) {
                    a = i;
                } else {
                    b = i;
                    break;
                }
            }
        }
        if (b == -1) {
            forn (i, n) {
                if (!del[i]) {
                    cout << "! " << i + 1 << endl;
                    return 0;
                }
            }
        }
        cout << "? " << a + 1 << " " << b + 1 << endl;
        int x;
        cin >> x;
        --x;
        if (b == x) {
            swap(a, b);
        }
        if (a == x) {
            cout << "! " << a + 1 << endl;
            return 0;
        }
        del[a] = del[b] = true;
        for (int to: g[a]) {
            --d[to];
        }
        for (int to: g[b]) {
            --d[to];
        }
    }
}
#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 2e18 + 13;
const int M = 1e9 + 7;
const int N = 18 + 3;

/*
*/

vector<pii> g[N], r[N];
vector<int> ts;
bool used[N];

void dfs(int v) {
    used[v] = true;

    for(auto u : g[v])
        if(!used[u.f])
            dfs(u.f);

    ts.push_back(v);
}

int n;
int a[N];
int lf[N], rg[N];
int f[1 << N];

void recalc() {
    for(int i = 0; i < n; i++) {
        lf[i] = 0;
        for(auto u : g[i]) {
            lf[i] = max(lf[i], a[u.f] + 1);
        }

        rg[i] = n;
        for(auto u : r[i]) {
            rg[i] = min(rg[i], a[u.f] - 1);
        }
    }

}

//bool isinc(int mask) {
//    for(int i = 0; i < n; i++)
//        if(((1 << i) & mask) > 0 && a[i] == rg[i])
//            return false;
//    return true;
//}
//
//bool isdec(int mask) {
//    for(int i = 0; i < n; i++)
//        if(((1 << i) & mask) > 0 && a[i] == lf[i])
//            return false;
//    return true;
//}

bool isinc(int mask) {
    for(int v = 0; v < n; v++) {
        if(((1 << v) & mask) != 0) {
            if(a[v] == n)
                return false;
            for(auto u : r[v]) {
                if(((1 << u.f) & mask) == 0)
                    if(a[v] + 1 == a[u.f])
                        return false;
            }
        }

    }

    return true;
}

bool isdec(int mask) {
    for(int v = 0; v < n; v++) {
        if(((1 << v) & mask) != 0) {
            if(a[v] == 0)
                return false;
            for(auto u : g[v]) {
                if(((1 << u.f) & mask) == 0)
                    if(a[v] == a[u.f] + 1)
                        return false;
            }
        }

    }

    return true;
}

/*
6  8
1 2 2
1 3 1
1 4 1
2 6 2
3 2 3
3 6 1
4 5 1
5 6 1
*/

int main() {
    int m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;

        v--;
        u--;

        g[v].emplace_back(u, w);
        r[u].emplace_back(v, w);
    }

    for(int i = 0; i < n; i++)
        if(!used[i])
            dfs(i);

    for(int i = 0; i < n; i++) {
        a[ts[i]] = i;
    }

//    recalc();

    int ans = 0;
    for(int v = 0; v < n; v++) {
        for(auto u : g[v])
            ans += (a[v] - a[u.f]) * u.s;
    }

//    for(int i = 0; i < n; i++) {
//        cout << lf[i] << ' ' << a[i] << ' ' << rg[i] << endl;
//    }

    for(int mask = 0; mask < (1 << n); mask++) {
        for(int v = 0; v < n; v++) {
            for(auto u : g[v]) {
                if(((1 << v) & mask) != 0 && ((1 << u.f) & mask) == 0) {
                    f[mask] += u.s;
                }

                if(((1 << v) & mask) == 0 && ((1 << u.f) & mask) != 0) {
                    f[mask] -= u.s;
                }
            }
        }
    }
//cout << f[(1 << 0) + (1 << 3) + (1 << 4)] << ' ' << isdec((1 << 0) + (1 << 3) + (1 << 4)) << endl;
//    cout << f[(1 << 4)] << ' ' << isdec((1 << 4)) << endl;
//    cout << ans<< endl;
//    for(int i = 0; i < n; i++) {
//        cout << a[i] << ' ';
//    }
//    cout << endl;

    bool fl = true;
    while(fl) {

        fl = false;
        for(int mask = 0; mask < (1 << n); mask++) {
            if(f[mask] < 0 && isinc(mask)) {
                ans += f[mask];
                for(int j = 0; j < n; j++)
                    if((1 << j) & mask) {
                        a[j]++;
                    }
//                recalc();
                fl = true;
                break;
            }

            if(f[mask] > 0 && isdec(mask)) {
                ans -= f[mask];
                for(int j = 0; j < n; j++)
                    if((1 << j) & mask) {
                        a[j]--;
                    }
//                recalc();
                fl = true;
                break;
            }
        }
//        cout << ans<< endl;
//        for(int i = 0; i < n; i++) {
//            cout << a[i] << ' ';
//        }
//        cout << endl;
//        cout << fl << endl;
    }

//    for(int i = 0; i < n; i++) {
//        cout << lf[i] << ' ' << a[i] << ' ' << rg[i] << endl;
//    }
//cout << f[(1 << 0) + (1 << 3) + (1 << 4)] << ' ' << isdec((1 << 0) + (1 << 3) + (1 << 4)) << endl;

//    cout << f[(1 << 4)] << ' ' << isdec((1 << 4)) << endl;
//    cout << ans << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
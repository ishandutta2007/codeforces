#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;
const ll INF = 1e18;

vector <pair<int, int> > e, bad;
ll a[1034][1034];
int n, m, l, st, fn, v1, v2, c, kol;
ll d[N];
bool u[N];

ll go(ll M) {
    ll c;
    for (int i = 0; i < (int)bad.size(); i++) {
        c = M / kol;
        if (i < M % kol)
            c++;
        a[bad[i].first][bad[i].second] = a[bad[i].second][bad[i].first] = c;
    }
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        u[i] = false;
    }
    d[st] = 0;

    int mn;
    for (int i = 0; i < n; i++) {
        mn = -1;
        for (int j = 0; j < n; j++)
            if (!u[j] && (mn == -1 || d[mn] > d[j]))
                mn = j;
        if (mn == -1)
            break;
        u[mn] = true;
        for (int j = 0; j < n; j++)
            d[j] = min(d[j], d[mn] + a[mn][j]);
    }
    return d[fn];
}

int main() {
    init();

    cin >> n >> m >> l >> st >> fn;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = INF;

    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> c;
        e.push_back(make_pair(v1, v2));
        a[v1][v2] = a[v2][v1] = c;
        if (c == 0) {
            bad.push_back(make_pair(v1, v2));
            kol++;
        }
    }

    ll L = kol;
    ll R = 1e14;
    ll M;

    while (R - L > 1) {
        M = (L + R) / 2;
        //cerr << M << " " << go(M) << "\n";
        if (go(M) <= l)
            L = M;
        else
            R = M;
    }

    if (go(L) != l) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        cout << e[i].first << " " << e[i].second << " " << a[e[i].first][e[i].second] << "\n";
    }


    return 0;
}
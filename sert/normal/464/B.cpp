#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

#define sqr(x) x * x
#define ff first
#define ss second

using namespace std;

typedef long long ll;

const ll N = 1e6 + 34;
const ll S68 = 1679616;

ll n, m;
ll a[N][3], b[N][3];
pair<ll, ll> d[8];
string s;

ll dist(int i, int j) {
    return (b[j][0] - b[i][0]) * (b[j][0] - b[i][0]) + (b[j][1] - b[i][1]) * (b[j][1] - b[i][1]) + (b[j][2] - b[i][2]) * (b[j][2] - b[i][2]);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];

    for (int st = 0; st < S68; st++) {
        m = st;
        for (int i = 0; i < 8; i++) {
            b[i][0] = a[i][m % 3];
            b[i][1] = a[i][(m % 3 + m % 2 + 1) % 3];
            b[i][2] = a[i][0] + a[i][1] + a[i][2] - b[i][0] - b[i][1];
            m /= 6;
        }
        for (int i = 1; i < 8; i++)
            d[i - 1] = make_pair(dist(0, i), i);
        sort(d, d + 7);
        if (d[0].ff != d[2].ff || d[3].ff != d[5].ff) continue;
        if (d[0].ff * 2 != d[4].ff || d[0].ff * 3 != d[6].ff) continue;
        if (dist(d[0].ss, d[1].ss) != 2 * d[0].ff) continue;
        if (dist(d[0].ss, d[2].ss) != 2 * d[0].ff) continue;
        if (dist(d[2].ss, d[1].ss) != 2 * d[0].ff) continue;
        if (dist(d[3].ss, d[4].ss) != 2 * d[0].ff) continue;
        if (dist(d[3].ss, d[5].ss) != 2 * d[0].ff) continue;
        if (dist(d[5].ss, d[4].ss) != 2 * d[0].ff) continue;
       if (!d[0].ff) continue;
        if (dist(d[0].ss, d[3].ss) != d[0].ff && dist(d[0].ss, d[3].ss) != 3 * d[0].ff) continue;
        if (dist(d[0].ss, d[3].ss) + dist(d[1].ss, d[3].ss) + dist(d[2].ss, d[3].ss) != 5 * d[0].ff) continue;
        if (dist(d[3].ss, d[6].ss) != d[0].ff) continue;
        if (dist(d[2].ss, d[6].ss) != d[0].ff * 2) continue;
        cout << "YES\n";
        for (int i = 0; i < 8; cout << "\n", i++)
            for (int j = 0; j < 3; j++)
                cout << b[i][j] << " ";
        return 0;
    }
    cout << "NO\n";
    return 0;
}
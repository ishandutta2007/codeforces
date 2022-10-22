#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*
1
4 4 1 2
*/

void solve() {
    li n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<pii> a(4);
    a[0] = {1, 1};
    a[1] = {n, 1};
    a[2] = {1, m};
    a[3] = {n, m};

    li res = -1, ai = 0, aj = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < i; j++) {
            li r = abs(x - a[i].f) + abs(x - a[j].f) + abs(a[i].f - a[j].f) +
                    abs(y - a[i].s) + abs(y - a[j].s) + abs(a[i].s - a[j].s);

//            cout << i << ' ' << j << ' ' << a[i].f << ' ' << a[i].s << ' ' << a[j].f << ' '<< a[j].s << ' ' << r << endl;

            if(r > res) {
                res = r;
                ai = i;
                aj = j;
            }
        }
    }

    cout << a[ai].f << ' ' << a[ai].s << ' ' << a[aj].f << ' ' << a[aj].s << endl;
}

int main() {

    int t;
    cin >> t;

    while(t--)
        solve();
}
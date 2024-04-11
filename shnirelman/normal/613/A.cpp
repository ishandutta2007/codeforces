//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

//const li INF = 2e18 + 13;
const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
//const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

/*
*/


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    ld mx = 0, mn = INF * 1ll * INF;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        int x1, y1;
        cin >> x1 >> y1;

        a[i] = {x1, y1};

        int dx = x - x1, dy = y - y1;
        ld dist = dx * 1ll * dx + dy * 1ll * dy;

        mx = max(mx, dist);
        mn = min(mn, dist);
    }

    for(int i = 0; i < n; i++) {
        ld l = 0, r = 1;
        int j = (i + 1) % n;
        for(int ind = 0; ind < 50; ind++) {
            ld m1 = (l * 2 + r) / 3, m2 = (l + r * 2) / 3;


            ld res1 = 0, res2 = 0;
            {
                ld x1 = m1 * a[i].f + (1 - m1) * a[j].f;
                ld y1 = m1 * a[i].s + (1 - m1) * a[j].s;

                ld dx = x - x1, dy = y - y1;
                res1 = dx * dx + dy * dy;
            }

            {
                ld x1 = m2 * a[i].f + (1 - m2) * a[j].f;
                ld y1 = m2 * a[i].s + (1 - m2) * a[j].s;

                ld dx = x - x1, dy = y - y1;
                res2 = dx * dx + dy * dy;
            }

            if(res1 < res2)
                r = m2;
            else
                l = m1;
        }

        ld x1 = l * a[i].f + (1 - l) * a[j].f;
        ld y1 = l * a[i].s + (1 - l) * a[j].s;

        ld dx = x - x1, dy = y - y1;
        ld dist = dx * dx + dy * dy;

//        cout << i << ' ' << j << ' ' << dist << endl;

        mn = min(mn, dist);
    }

    cout << setprecision(20) << fixed << (mx - mn) * acos(-1) << endl;
}
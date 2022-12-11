#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <cstring>
#include <string>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define fab(i, a, b) for (int i = a; i <= int(b); i++)
#define fdown(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)

typedef int ld;

using namespace std;

const int maxn = 3e6+4;

struct pt{
    ld x, y;
    pt(){}

    pt(ld _x, ld _y){
        x = _x;
        y = _y;
    }

    ld operator % (const pt &a){
        return x * a.x + y * a.y;
    }

    ld operator * (const pt &a){
        return x * a.y - y * a.x;
    }

    pt operator + (const pt &a){
        pt b = a;
        b.x += x;
        b.y += y;
        return b;
    }
    pt operator - (const pt &a){
        return pt(x - a.x, y - a.y);
    }

};

int n;
bool u[1010][1010];
pt a[10000];
pt h1, h2, h3;
ld ans;
ld a1, a2, ta;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    fr(i, n)
        cin >> a[i].x >> a[i].y;

    fr(i, n)
        fr(j, i) {
            a1 = 0;
            a2 = 0;
            h1 = a[i] - a[j];
            fr(k, n) {
                if (k == i || k == j)
                    continue;
                h2 = a[k] - a[j];
                ta = h1 * h2;
                if (ta < a1)
                    a1 = ta;
                if (ta > a2)
                    a2 = ta;
            }
            if (a2 == 0 || a1 == 0)
                continue;
            if (a2 - a1 > ans)
                ans = a2 - a1;
        }

    cout << ans / 2 << "." << 5 * (ans % 2);

    return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <vector>

#define y1 yy1
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 7;

using namespace std;

struct mt {
    bool z;
    ll n;
    ll l, c;
};

ll n, m, k, t, p, l, c;
mt a[N];
ll b[N];
bool u[N];
string s;

ll go(ll x) {
    ll lft, rit, mid;
    lft = -1;
    rit = n - 1;

    while (rit - lft > 1) {
        mid = (rit + lft) / 2;
        if (b[mid + 1] >= x)
            rit = mid;
        else
            lft = mid;
    }

   //cerr << rit << "\n";

    if (a[rit].z) {
        return a[rit].n;
    }

    ll q = x - b[rit];
    //cerr << q << "  q\n";
    return go((q - 1) % a[rit].l + 1);
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (k == 1) {
            scanf("%d", &p);
            //cerr << p << "\n";
            a[i].z = true;
            a[i].n = p;
            b[i + 1] = b[i] + 1;
        }
        else
        {
            scanf("%d %d", &l, &c);
            a[i].z = false;
            a[i].l = l;
            a[i].c = c;
            b[i + 1] = b[i] + l * c;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%I64d", &p);
        printf("%I64d ", go(p));
    }
    return 0;
}
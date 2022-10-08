#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define MO 1000000007
#define N 210

struct P {
    ll x, y;
    P () {}
    P (ll _x, ll _y):x(_x),y(_y) {}
    P operator - (const P&a) const {return P(x-a.x,y-a.y);}
    P operator + (const P&a) const {return P(x+a.x,y+a.y);}
    ll crs (const P&a) const {return (ll)x*a.y-(ll)y*a.x;}
    void get () {cin >> x >> y;} 
}a[N];

bool c[N][N];
int n;

int sgn(ll x) {
    if (x >= 1) return 1;
    if (x <= -1) return -1;
    return 0;
}

PII sgn(P x) {
    return mp(sgn(x.x),sgn(x.y));
}

bool val(int x, int y) {
    if ((x+1)%n == y || (y+1)%n == x) return 1;
    for (int i = 0; i < n; i ++)
        if (i != x && i != y) {
            if ((a[i]-a[x]).crs(a[i]-a[y]) != 0) continue;
            if (sgn(a[i]-a[x]) == sgn(a[y]-a[i])) return 0;
        }
    bool F = 0;
    P mid = a[x]+a[y];
    for (int i = 0; i < n; i ++) {
        P le = a[i], ri = a[(i+1)%n];
        le = le+le; ri = ri+ri;
        if (le.y == ri.y) continue;
        if (le.y > ri.y) swap(le,ri);
        if (!(le.y <= mid.y && mid.y < ri.y)) continue;
        if ((mid-le).crs(mid-ri) > 0) F ^= 1;
    }
    if (!F) return 0;
    for (int i = 0; i < n; i ++) {
        int j = (i+1)%n;
        if (i == x || i == y || j == x || j == y) continue;
        if (sgn((a[i]-a[x]).crs(a[i]-a[y]))*sgn((a[j]-a[x]).crs(a[j]-a[y])) == -1 && sgn((a[x]-a[i]).crs(a[x]-a[j]))*sgn((a[y]-a[i]).crs(a[y]-a[j])) == -1) return 0;
    }
    return 1;
}

ll f[N][N];

ll ff(int l, int r) {
    if (f[l][r] != -1) return f[l][r];
    f[l][r] = 0;
    if (l+1 == r) return f[l][r] = 1;
    for (int k = l+1; k <= r-1; k ++) 
        if (c[l][k] && c[k][r]) (f[l][r] += (ll)ff(l,k)*ff(k,r)%MO) %= MO;
    return f[l][r];
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i ++) a[i].get();
    for (int i = 0; i < n; i ++) 
        for (int j = i+1; j < n; j ++)
            c[i][j] = c[j][i] = val(i,j);
    for (int i = 0; i < n; i ++) 
        for (int j = 0; j < n; j ++) f[i][j] = -1;
    cout << ff(0,n-1) << endl;
    return 0; 
}
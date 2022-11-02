#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct pnt {
    ll x, y;
    pnt(ll x = 0, ll y = 0) : x(x), y(y) {}
    pnt operator + (const pnt &b) const {return pnt(x + b.x, y + b.y);}
    pnt operator - (const pnt &b) const {return pnt(x - b.x, y - b.y);}
    ll operator ^ (const pnt &b) const {return x * b.y - b.x * y;}
};


#define N 100010

ll x[N], y[N];
pnt p[N];
int a[N];

int main() {
    int n;
    scanf("%d", &n);
    map <ll, ll> mp;
    for(int i = 1; i <= n; i ++) {
        scanf("%I64d%I64d", &x[i], &y[i]);
        y[i] -= 1ll * x[i] * x[i];
        if(mp.count(x[i])) mp[x[i]] = max(mp[x[i]], y[i]);
        else mp[x[i]] = y[i];
    }
    int m = 0;
    for(map <ll, ll> :: iterator it = mp.begin(); it != mp.end(); it ++) p[++ m] = pnt(it -> first, it -> second);
    if(m < 3) {
        printf("%d\n", m - 1);
        return 0;
    }
    int ed = 2;
    a[0] = 1, a[1] = 2;
    for(int i = 3; i <= m; i ++) {
        while(ed >= 2 && ((p[a[ed-1]] - p[a[ed-2]]) ^ (p[i] - p[a[ed-1]])) >= 0) ed --;
        a[ed ++] = i;
    }
    printf("%d\n", ed - 1);
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fr(i, n) for(ll i = 0; i < n; i++)
#define fab(i, a, b) for(ll i = a; i <= b; i++)

const ll N = 1e3 + 7;

ll sum, n, t, a[N], l, ans, m, k, h;
bool u[N];
int p[N];

int get(int v){
    if (p[v] == v)
        return v;
    else{
        p[v] = get(p[v]);
        return p[v];
    }
}

int add(int v1, int v2){
    int g1 = get(v1);
    int g2 = get(v2);
    if (g1 != g2)
        p[g1] = g2;
}

int main()
{
   // freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);

    cin >> n >> m;
    fr(i, m + 1)
        p[i] = i;

    fr(i, n){
        cin >> k;
        if (k == 0)
            ans++;
        else
            h = 1;
        fr(j, k){
            cin >> a[j];
            u[a[j]] = true;
        }
        fr(j, k - 1)
            fab(ii, j + 1, k - 1)
                add(a[j], a[ii]);
    }

    fr(i, m + 1)
        if (p[i] == i && u[i])
            ans++;

    cout << ans - h;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int n, m;
ll h[MAXN], p[MAXN];

bool check(ll bnd) {
    int ph = 1, pp = 1;
    ll le = 0, ri = 0;
    while(ph <= n && pp <= m) {
        if(p[pp] <= h[ph])
            le = max(le, h[ph] - p[pp]);
        else
            ri = max(ri, p[pp] - h[ph]);
        if(min(2*ri + le, 2*le + ri) > bnd) {
            ph++;
            le = 0;
            ri = 0;
        }
        else
            pp++;
    }
    return (pp == (m + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= m; i++)
        cin >> p[i];
    ll lo = 0, hi = 1e15;
    while(lo < hi) {
        ll mi = (lo + hi)/2;
        if(check(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    cout << lo << endl;
}
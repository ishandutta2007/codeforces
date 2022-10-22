#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 2e5 + 13;
const li INF = 4e18;

li get(int a, int b, int c) {
    li d1 = a - b, d2 = b - c, d3 = a - c;
    return d1 * d1 + d2 * d2 + d3 * d3;
}

void solve() {
    int na, nb, nc;
    cin >> na >> nb >> nc;

    vector<int> a(na), b(nb), c(nc);
    for(int i = 0; i < na; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    for(int i = 0; i < nb; i++)
        cin >> b[i];
    sort(b.begin(), b.end());

    for(int i = 0; i < nc; i++)
        cin >> c[i];
    sort(c.begin(), c.end());

//    cout << get(1, 1, 1000000000) << endl;

    int ia = 0, ib = 0, ic = 0;
    li ans = INF;
    for(; ia < na - 1 || ic < nc - 1 || ib < nb - 1; ) {
        ans = min(ans, get(a[ia], b[ib], c[ic]));
        li ra = INF;
        if(ia < na - 1)
            ra = get(a[ia + 1], b[ib], c[ic]);

        li rb = INF;
        if(ib < nb - 1)
            rb = get(a[ia], b[ib + 1], c[ic]);

        li rc = INF;
        if(ic < nc - 1)
            rc = get(a[ia], b[ib], c[ic + 1]);

        if(ra <= rb && ra <= rc)
            ia++;
        else if(rb <= ra && rb <= rc)
            ib++;
        else
            ic++;

//        if(ia < na - 1 && (a[ia] > b[ib] || ib == nb - 1) && (a[ia] > c[ic] || ic == nc - 1)) {
//            ia++;
//            continue;
//        }
    }

    ans = min(ans, get(a[ia], b[ib], c[ic]));
    cout << ans << endl;
}

/*
1
1 1 1
1
1
1000000000
*/

int main() {
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
//#include <>
#include <map>

#define ll long long int
#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))

using namespace std;
const int inf = 1000000000;
const double eps = 0.000000001;

struct otr {
    int l,r,k;
};

bool _less(const otr & a, const otr & b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}

otr p[200];
int a[200];
bool use[200];

int n;

int main()
{
    int tr = -1;
    cin >> n;
    FOR(i,n) { p[i].k=i; cin >> p[i].l >> p[i].r; }
    //sort(p, p+n, _less);
    FOR(i,n) {
        int x =inf;
        FOR(j,n) if (!use[j]) x = min(x, max(tr+1, p[j].l));
        int z = -1;
        FOR(j,n) if (!use[j] &&
            (p[j].l <= x && x <= p[j].r && (z<0 || p[j].r<p[z].r) ) ) z = j;
        use[z] = 1;
        a[z] = x; tr = x;
    }
    FOR(i,n) cout << a[i] << " ";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
typedef pair <int, int> pii;

int n, q;
set <pii> A;
set <pii> :: iterator it1;
vector <pii> v[2];

int main() {
    scanf("%d %d", &n, &q);
    int left = n;
    A.insert(pii(1, n));
    int L, R, k;
    while (q --) {
        scanf("%d %d %d", &L, &R, &k);
        pii rpt = pii(L, R);
        it1 = A.lower_bound(rpt);
        if (it1 != A.begin()) it1 --;
        if (it1 != A.end() && it1 -> y < L) it1 ++;
        v[0].clear(); v[1].clear();
        for ( ; it1 != A.end(); it1 ++) {
            int l = it1 -> x, r = it1 -> y;
            if (l > R) break;
            v[0].pb(pii(l, r));
            if (l < L) v[1].pb(pii(l, L-1));
            if (R < r) v[1].pb(pii(R+1, r));
        }
        if (k == 2) v[1].pb(rpt);
        for (auto x : v[0]) {
            A.erase(x);
            left -= x.y - x.x + 1;
        }
        for (auto x : v[1]) {
			A.insert(x);
			left += x.y - x.x + 1;
        }
        printf("%d\n", left);
    }
	return 0;
}
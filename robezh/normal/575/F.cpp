#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
typedef long long ll;
const ll INF = (ll)1e18;

int n, x, l, r;
int nl, nr;

int main() {
    ll res = 0;
    cin >> n >> nl; nr = nl;
    while(n--) {
        cin >> l >> r;
        if(max(nl, l) <= min(nr, r)) {
            nl = max(nl, l);
            nr = min(nr, r);
            continue;
        }
        if(l > nr) {
            res += l - nr;
            nl = nr;
            nr = l;
        }
        else {
            res += nl - r;
            nr = nl;
            nl = r;
        }
    }
    cout << res << endl;
}
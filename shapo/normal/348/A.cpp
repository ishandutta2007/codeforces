#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

typedef vector < int > vi;
typedef long long ll;

int n;
vi cur;
ll x;

bool
ok(ll x)
{
    ll res = 0LL;
    for (int i = 0; i < n; ++i) {
        res += (x - cur[i]);
        if (res >= x) {
            return true;
        }
    }
    return false;
}

int
main(void)
{
#ifndef _DEBUG
    ios_base::sync_with_stdio(false);
#endif
    cin >> n;
    cur.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> cur[i];
    }
    x = 0LL;
    sort(cur.rbegin(), cur.rend());
    ll l = cur[0] - 1, r = 1LL;
    for (int i = 0; i < n; ++i) {
        r += cur[i];
    }
    while (l < r - 1) {
        ll m = (l + r) / 2;
        if (ok(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endline;
    return 0;
}
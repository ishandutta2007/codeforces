#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 1e6 + 5;
long long t, l, r, n, cnt;
int a[N], b[N], f[N], ans[N], ll[N], rr[N];

void Enter() {
    cin >> l >> r;
    n = r - l + 1;
    FOR(i, 1, n) cin >> a[i];
}

int next_(int &x) {
    if (!x) {
        x = ++cnt;
        ll[x] = rr[x] = 0;
    }
    return x;
}

void update(int x) {
    int root = 0;
    REPD(i, 17, 0) {
        if ((x>>i)&1) root = next_(rr[root]);
        else root = next_(ll[root]);
    }
    ll[root] = x;
}

int get_left(int x) {
    int root = 0;
    REPD(i, 17, 0) {
        if ((x>>i)&1) {
            if (rr[root]) root = rr[root];
            else root = ll[root];
        }
        else {
            if (ll[root]) root = ll[root];
            else root = rr[root];
        }
    }
    return x ^ ll[root];
}

int get_right(int x) {
    int root = 0;
    REPD(i, 17, 0) {
        if ((x>>i)&1) {
            if (ll[root]) root = ll[root];
            else root = rr[root];
        }
        else {
            if (rr[root]) root = rr[root];
            else root = ll[root];
        }
    }
    return x ^ ll[root];
}

void Process() {
    cnt = 0;
    ll[0] = rr[0] = 0;
    FOR(i, 1, n)
        update(a[i]);
    FOR(i, 1, n) {
        int val = a[i] ^ l;
        if (get_left(val) == l && get_right(val) == r) {
            cout << val << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        Enter();
        Process();
    }
}
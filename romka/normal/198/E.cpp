#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define sqr(x) (ll)(x) * (ll(x))

const int inf = (int)1e9 + 7;
const int maxn = (1 << 18) + 10;

int xs, ys, ps, rs, n, x[maxn], y[maxn], m[maxn], p[maxn], r[maxn];
int t[maxn*2];
pii q[maxn];
pair<long long, int> d[maxn];
int qb, qf, N;

void go(int i, int L, int R, int qR, int pw) {
    if (pw < t[i]) return;
    if (L == R) {
        t[i] = inf;
        // printf("take %d with pw=%d\n", d[i-N].second+1, pw);
        q[qf++] = pii(p[d[i-N].second], r[d[i-N].second]);
        return;
    }

    int M = (L+R) >> 1;

    go(i*2, L, M, min(qR, M), pw);
    if (qR >= M+1) go(i*2+1, M+1, R, qR, pw);

    t[i] = min(t[i*2], t[i*2+1]);
}

int main() {
    scanf("%d %d %d %d %d", &xs, &ys, &ps, &rs, &n);
    forn(i, n) {
        scanf("%d %d %d %d %d", &x[i], &y[i], &m[i], &p[i], &r[i]);
        d[i].first = sqr(xs - x[i]) + sqr(ys - y[i]);
        d[i].second = i;
    }
    
    sort(d, d+n);

    N = 1;
    while (N < n) N <<= 1;
    forn(i, N)
        if (i < n) t[N+i] = m[ d[i].second ];
        else t[N+i] = inf;

    for (int i = N-1; i > 0; i--)
        t[i] = min(t[2*i], t[2*i+1]);

    q[qf++] = pii(ps, rs);
    while (qb < qf) {
        pii cur = q[qb++]; 

        int cp = cur.first;
        ll cr = sqr(cur.second);

        int mx = upper_bound(d, d+n, make_pair(cr, n+2)) - d;
        go(1, 0, N-1, mx-1, cp);
    }

    printf("%d\n", qb - 1);

    return 0;
}
#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
#define push_back pb
#define emplace_back eb
#define mod(x) ((x)%Mod)
#define nm ((nl+nr)/2)
#define lc (n*2+1)
#define rc (n*2+2)
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 200005, Max = 1 << 18, MaxNodes = 1 << 20;

int N, M, K;
char s[MaxN];

const ll m1 = 1000000007, m2 = 1000000009;
const ll b1 = 137, b2 = 139;

ll h1[MaxNodes], h2[MaxNodes], times1[Max+5], times2[Max+5], all1[Max+5], all2[Max+5], lazy[MaxNodes];
void unlazy(int n, int nl, int nr) {
    if (lazy[n]) {
        h1[n] = (all1[nr-nl-1] * lazy[n]) % m1;
        h2[n] = (all2[nr-nl-1] * lazy[n]) % m2;
        if (nl+1 != nr) {
            lazy[lc] = lazy[rc] = lazy[n];
        }
        lazy[n] = 0;
    }
}
void update(int n, int nl, int nr, int ul, int ur, int uv) {
    unlazy(n, nl, nr);
    if (ul <= nl && nr <= ur) lazy[n] = uv;
    else {
        if (ul < nm) update(lc, nl, nm, ul, ur, uv);
        if (ur > nm) update(rc, nm, nr, ul, ur, uv);
        unlazy(lc, nl, nm);
        unlazy(rc, nm, nr);
        h1[n] = (times1[nr-nm] * h1[lc] + h1[rc]) % m1;
        h2[n] = (times2[nr-nm] * h2[lc] + h2[rc]) % m2;
    }
}
std::pair<ll, ll> query(int n, int nl, int nr, int ql, int qr) {
    unlazy(n, nl, nr);
    if (ql <= nl && nr <= qr) return std::make_pair((times1[qr-nr] * h1[n]) % m1, (times2[qr-nr] * h2[n]) % m2);
    else {
        std::pair<ll, ll> cur = std::make_pair(0ll, 0ll), kur;
        if (ql < nm) {
            kur = query(lc, nl, nm, ql, qr);
            cur.first = (cur.first + kur.first) % m1;
            cur.second = (cur.second + kur.second) % m2;
        }
        if (nm < qr) {
            kur = query(rc, nm, nr, ql, qr);
            cur.first = (cur.first + kur.first) % m1;
            cur.second = (cur.second + kur.second) % m2;
        }
        return cur;
    }
}

int main()
{
    times1[0] = times2[0] = all1[0] = all2[0] = 1;
    for (int i = 1; i <= Max; i++) {
        times1[i] = (times1[i-1] * b1) % m1;
        all1[i] = (all1[i-1] + times1[i]) % m1;
        times2[i] = (times2[i-1] * b2) % m2;
        all2[i] = (all2[i-1] + times2[i]) % m2;
    }

    scanf("%d%d%d %s", &N, &M, &K, s);
    for (int i = 0; i < N; i++) {
        update(0, 0, Max, i, i+1, s[i] - '0' + 1);
    }
    for (int i = 0; i < M+K; i++) {
        //{ fprintf(stderr, "%d\n", i); fflush(stdout); }
        int a, b, l, r; scanf("%d%d%d%d", &a, &l, &r, &b); l--;
        if (a == 1) {
            update(0, 0, Max, l, r, b+1);
        } else {
            //int curl = l, curd = b;
            bool fail = false;
            /*while (curl + curd + curd <= r) {
                std::pair<ll, ll> q1 = query(0, 0, Max, curl, curl + curd);
                std::pair<ll, ll> q2 = query(0, 0, Max, curl + curd, curl + curd + curd);
                if (q1 != q2) {
                    fail = true; break;
                }
                curd += curd;
            }
            if (fail) {
                printf("NO\n"); continue;
            }
            if (curl + curd < r) {
                //printf("%d %d %d\n", curl, curd, r); fflush(stdout);
                curd = r - (curl + curd);
                //printf("%d %d %d\n", curl, curd, r); fflush(stdout);
                if (query(0, 0, Max, curl, curl + curd) != query(0, 0, Max, r - curd, r)) {
                    fail = true;
                }
            }*/
            if (b < r-l) fail = query(0, 0, Max, l, r-b) != query(0, 0, Max, l+b, r);
            if (fail) {
                printf("NO\n"); continue;
            }
            printf("YES\n");
        }
    }
}
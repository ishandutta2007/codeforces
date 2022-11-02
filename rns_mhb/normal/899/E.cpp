#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pc putchar
#define gc getchar
#define pb push_back
#define ppb pop_back
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f2(i, a, b) for (int i = a; i > b; i --)
#define f3(i, a, b) for (int i = a; i >= b; i --)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;
typedef vector <int> vi;

const int inf = 0x3f3f3f3f;
const ll linf = 2e18 + 100;
const double eps = 1e-7;

#define N 200005
#define M 400005

int n, a[N];
int len[M], s[M], v[M], r[M], l[M];

struct cmp {
    bool operator () (const int x, const int y) const {
        if (len[x] != len[y]) return len[x] < len[y];
        return s[x] > s[y];
    }
} ;

multiset <int, cmp> S;
multiset <int, cmp> :: iterator it, it1, it2;

int main() {
    scanf("%d", &n);
    f1(i, 1, n) scanf("%d", &a[i]);
    int sz = 0, prv = 0;
    for (int i = 1, j; i <= n; ) {
        for (j = i; j <= n && a[j] == a[i]; j ++) ;
        sz ++; len[sz] = j - i, v[sz] = a[i], s[sz] = i;
        l[sz] = prv;
        if (prv) r[prv] = sz;
        prv = sz;
        i = j;
    }
    r[prv] = 0;
    f1(i, 1, sz) S.insert(i); int ans = 0;
    while (!S.empty()) {
        it = S.end(); it --;
        int x = *it; S.erase(it);
        if (r[x] && l[x]) {
            int L = l[x], R = r[x];
            r[L] = R, l[R] = L;
            if (v[L] == v[R]) {
                sz ++;
                len[sz] = len[L] + len[R];
                s[sz] = s[L]; v[sz] = v[L];
                l[sz] = l[L], r[sz] = r[R];
                if (l[L]) r[l[L]] = sz;
                if (r[R]) l[r[R]] = sz;
                S.erase(S.find(L));
                S.erase(S.find(R));
                S.insert(sz);
            }
        }
        else {
            if (r[x]) l[r[x]] = 0;
            else r[l[x]] = 0;
        }
        ans ++;
    }
    printf("%d\n", ans);
	return 0;
}
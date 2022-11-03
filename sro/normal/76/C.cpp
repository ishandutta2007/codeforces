/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int n, k, t;
char s[1 << 18];
int c[23], d[23][23];
int nxt[23];
int sm[1 << 22 | 1];

int main() {
    scanf("%d%d%d", &n, &k, &t);
    scanf("%s", s);
    loop(i, k) scanf("%d", c + i);
    loop(i, k) loop(j, k) scanf("%d", d[i] + j);
    loop(i, k) nxt[i] = n;
    range(i, n - 1, 0, -1) {
        vector<pair<int, int> > pr;
        loop(j, k) pr.pub(mak(nxt[j], j));
        sort(all(pr));
        int msk = 0, u = s[i] - 'A';
        loop(j, k) {
            if(pr[j].first == n) break;
            int v = pr[j].second;
            sm[msk] += d[u][v];
            sm[msk | (1 << u)] -= d[u][v];
            sm[msk | (1 << v)] -= d[u][v];
            sm[msk | (1 << u) | (1 << v)] += d[u][v];
            if(u == v) break;
            msk |= 1 << v;
        }
        nxt[u] = i;
    }
    loop(i, k) loop(j, 1 << k) if((j >> i) & 1) sm[j] += sm[j ^ (1 << i)];
    int ans = 0, shit = 0;
    loop(i, k) if(nxt[i] == n) shit |= 1 << i;
    loop(i, 1 << k) if(!(i & shit) && (i | shit) != (1 << k) - 1) {
        int sum = sm[i];
        loop(j, k) if((i >> j) & 1) sum += c[j];
        if(sum <= t) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
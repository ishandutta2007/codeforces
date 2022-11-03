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

int n, m, ys, ye;
int a[1 << 17], b[1 << 17];
int at[1 << 17], hp[1 << 17];
int cnt[1 << 17];
int sp[1 << 17];
bool usd[1 << 17];

int main() {
    scanf("%d%d%d%d", &n, &m, &ys, &ye);
    cont(i, n) scanf("%d", a + i);
    cont(i, m) scanf("%d", b + i);
    vector<pair<int, int> > cand;
    cont(i, n) {
        int pos = upper_bound(b + 1, b + m + 1, a[i]) - b;
        if(pos == 1) {
            at[i] = 1;
            continue;
        }
        if(pos == m + 1) {
            at[i] = m;
            continue;
        }
        // cerr<<i<<' '<<b[pos]<<' '<<b[pos - 1]<<' '<<a[i]<<endl;
        if(b[pos] - a[i] == a[i] - b[pos - 1]) {
            cand.pub(mak(i, pos));
            sp[i] = pos;
            continue;
        }
        if(b[pos] - a[i] > a[i] - b[pos - 1]) {
            at[i] = pos - 1;
        } else {
            at[i] = pos;
        }
        // cerr<<i<<' '<<pos<<' '<<at[i]<<endl;
    }
    // cont(i, n) cerr<<at[i]<<' ';cerr<<endl;
    memset(hp, Inf, sizeof(hp));
    cont(i, n) if(at[i]) hp[at[i]] = min(hp[at[i]], abs(b[at[i]] - a[i]));
    cont(i, n) if(at[i] && abs(b[at[i]] - a[i]) == hp[at[i]]) ++cnt[at[i]];
    int res = 0;
    cont(i, n) if(at[i] && abs(b[at[i]] - a[i]) > hp[at[i]]) ++res;
    // TODO: 
    int cl = res, cr = res, cs = 0, lstp = -1;
    cont(i, n) if(!at[i]) {
        int lp = sp[i] - 1, rp = sp[i];
        int ncl = Inf, ncr = Inf;
        ncl = min(ncl, cl + (a[i] - b[lp] == hp[lp] ? 0 : (a[i] - b[lp] < hp[lp] ? cnt[lp] : 1)));
        if(cs == lp) {
            int nhp = min(b[lp] - lstp, hp[lp]);
            int ncnt = 1;
            if(b[lp] - lstp == hp[lp]) ncnt = cnt[lp] + 1;
            else if(b[lp] - lstp > hp[lp]) ncnt = cnt[lp];
            // cerr<<i<<' '<<nhp<<endl;
            ncl = min(ncl, cr + (a[i] - b[lp] == nhp ? 0 : (a[i] - b[lp] < nhp ? ncnt : 1)));
        } else {
            ncl = min(ncl, cr + (a[i] - b[lp] == hp[lp] ? 0 : (a[i] - b[lp] < hp[lp] ? cnt[lp] : 1)));
        }
        ncr = min(ncr, min(cl, cr) + (b[rp] - a[i] == hp[rp] ? 0 : (b[rp] - a[i] < hp[rp] ? cnt[rp] : 1)));
        // cerr<<i<<' '<<ncl<<' '<<ncr<<' '<<cnt[lp]<<' '<<lp<<' '<<cnt[rp]<<' '<<rp<<endl;
        cs = rp; lstp = a[i]; cl = ncl; cr = ncr;
    }
    printf("%d\n", min(cl, cr));
    return 0;
}
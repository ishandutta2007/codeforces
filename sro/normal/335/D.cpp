/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(register int i = 0; i < (n); ++i)
#define cont(i, n)          for(register int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(register int i = (a); i <= (b); ++i)
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

int n;
short qzh[3005][3005], qzi[3005][3005];
int pre[3005][3005];
int x1[1 << 17], x2[1 << 17], y1[1 << 17], y2[1 << 17];

int main() {
    scanf("%d", &n);
    cont(i, n) {
        scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
        ++x1[i]; ++y1[i]; ++x2[i]; ++y2[i];
        circ(j, x1[i], x2[i] - 1) qzh[j][y2[i]] = 1, qzh[j][y1[i]] = 1;
        circ(j, y1[i], y2[i] - 1) qzi[x2[i]][j] = 1, qzi[x1[i]][j] = 1;
        ++pre[x1[i]][y1[i]]; ++pre[x2[i]][y2[i]];
        --pre[x1[i]][y2[i]]; --pre[x2[i]][y1[i]];
    }
    cont(i, 3003) cont(j, 3003) pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    cont(i, 3003) cont(j, 3003) pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    cont(i, 3003) loop(j, 3003) qzh[i][j] += qzh[i - 1][j];
    loop(i, 3003) cont(j, 3003) qzi[i][j] += qzi[i][j - 1];
    bool hv = 0;
    int l1, r1, l2, r2;
    cont(i, n) {
        const int lx(x1[i]), ly(y1[i]);
        int ch = 0;
        circ(rx, lx, 3003) {
            ch += (rx - lx) << 1 | 1;
            const int ry(ly + rx - lx);
            if(qzh[rx][ry + 1] - qzh[lx - 1][ry + 1] != rx - lx + 1) continue;
            if(qzh[rx][ly] - qzh[lx - 1][ly] != rx - lx + 1) break;
            if(qzi[rx + 1][ry] - qzi[rx + 1][ly - 1] != ry - ly + 1) continue;
            if(qzi[lx][ry] - qzi[lx][ly - 1] != ry - ly + 1) break;
            if(pre[rx][ry] - pre[lx - 1][ry] - pre[rx][ly - 1] + pre[lx - 1][ly - 1] != ch) {
                break;
            }
            hv = 1; l1 = lx, r1 = rx, l2 = ly, r2 = ry;
            break;
        }
        if(hv) break;
    }
    if(!hv) {
        puts("NO");
    } else {
        vector<int> vc;
        cont(i, n) if(x1[i] >= l1 && y1[i] >= l2 && x2[i] - 1 <= r1 && y2[i] - 1 <= r2) vc.pub(i);
        printf("YES %d\n", SZ(vc));
        loop(i, SZ(vc)) printf("%d ", vc[i]); puts("");
    }
    return 0;
}
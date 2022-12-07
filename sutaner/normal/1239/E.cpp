#pragma optimize(3)
#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 60
using namespace std;

int n;
int a[maxn];
int ansa[maxn], ansb[maxn];
int sum, mi = 0;

struct ele{
    int pos, rest, nowv;
    ele(int pos, int rest, int nowv) : pos(pos), rest(rest), nowv(nowv){}
    ele(){}
    bool operator < (const ele b) const{
        return (pos == b.pos) ? ((rest == b.rest) ? nowv < b.nowv : rest < b.rest) : pos < b.pos;
    }
};

int aa[maxn], bb[maxn];
int ca = 0, cb = 0;
//set<ele> f;
int maxa = 0;
int f[50][25 * 50000];
void DP(int pos, int rest, int nowv){
    if ((nowv >= (sum - nowv)) && (nowv - (sum - nowv) >= maxa)) return;
    if (ca == (n >> 1) && cb == (n >> 1)){
        if (max(nowv, sum - nowv) < mi) {
            mi = max(nowv, sum - nowv);
            rep(i, 1, ca) ansa[i] = aa[i];
            rep(i, 1, cb) ansb[i] = bb[i];
        }
        return;
    }
    else if (nowv >= (sum - nowv) && nowv >= mi) return;
    else if (f[pos][nowv] & (1 << rest)) return;
    else {
        f[pos][nowv] |= (1 << rest);
        if (cb < (n >> 1)) bb[++cb] = a[pos], DP(pos + 1, rest, nowv), --cb;
        if (ca < (n >> 1)) aa[++ca] = a[pos], DP(pos + 1, rest + 1, nowv + a[pos]), --ca;
    }
}

int main(){
    int _n;
    scanf("%d", &n), _n = n;
    rep(i, 1, n) scanf("%d", a + i);
    rep(i, 1, n) scanf("%d", a + n + i);
    n <<= 1;
    sort(a + 1, a + 1 + n);
    int ans1 = a[1], ans2 = a[2];
    n -= 2;
    rep(i, 1, n) a[i] = a[i + 2], sum += a[i], maxa = max(maxa, a[i]); mi = sum + 1;
    //printf("%d %d\n", mi, sum);
    DP(1, 0, 0);
    //printf("%d %d\n", mi, sum);
    printf("%d", ans1); rep(i, 1, (n >> 1)) printf(" %d", ansa[i]); printf("\n");
    per(i, (n >> 1), 1) printf("%d ", ansb[i]); printf("%d", ans2); printf("\n");
    return 0;
}
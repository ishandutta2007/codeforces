#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

template<class T>
void gn(T &x) {
    static char c, s;
    s=0;
    while (c=getchar(), (c<'0' || c>'9') && c!='-');
    if (c=='-') s=1, c=getchar();
    for (x=0; c>='0'; x=(x<<1)+(x<<3)+c-'0', c=getchar());
    if (s) x=-x;
}

inline void smin(INT &x, const INT &y) {
    if (x>y) x=y;
};

inline void smax(INT &x, const INT &y) {
    if (x<y) x=y;
};

#define INF 0x3f3f3f3f3f3f3f3fLL
#define NN 101010
INT x[NN][4];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int T, n;
    INT u, v, w;
    for (gn(T); T--; ) {
        gn(n);
        for (int i=1; i<=n; i++) {
            gn(u); gn(v); gn(w);
            x[i][0]=-u+v+w;
            x[i][1]=u-v+w;
            x[i][2]=u+v-w;
            x[i][3]=u+v+w;
        }
        INT st=-1, ed=(INT)3e18;
        auto f = [&n](INT m) {
            INT mi[4], ma[4];
            for (int i=0; i<4; i++) mi[i]=-INF, ma[i]=INF;
            for (int i=1; i<=n; i++) {
                for (int j=0; j<4; j++) {
                    smax(mi[j], x[i][j]-m);
                    smin(ma[j], x[i][j]+m);
                    if (mi[j]>ma[j]) return 0;
                }
            }
            for (int i=0; i<2; i++) {
                INT p[4], q[4];
                int ok=1;
                for (int j=0; j<4 && ok; j++) {
                    p[j]=mi[j]; q[j]=ma[j];
                    if (p[j]+i&1) p[j]++;
                    if (q[j]+i&1) q[j]--;
                    if (p[j]>q[j]) ok=0;
                }
                if (!ok) continue;
                if (p[0]+p[1]+p[2]>q[3]) continue;
                if (q[0]+q[1]+q[2]<p[3]) continue;
                return 1;
            }
            return 0;
        };
        while (ed-st>1) {
            INT md=st+ed>>1;
            if (f(md)) ed=md;
            else st=md;
        }
        INT mi[4], ma[4];
        for (int i=0; i<4; i++) mi[i]=-INF, ma[i]=INF;
        INT m=ed;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<4; j++) {
                smax(mi[j], x[i][j]-m);
                smin(ma[j], x[i][j]+m);
            }
        }
        for (int i=0; i<2; i++) {
            INT p[4], q[4];
            int ok=1;
            for (int j=0; j<4 && ok; j++) {
                p[j]=mi[j]; q[j]=ma[j];
                if (p[j]+i&1) p[j]++;
                if (q[j]+i&1) q[j]--;
                if (p[j]>q[j]) ok=0;
            }
            if (!ok) continue;
            if (p[0]+p[1]+p[2]>q[3]) continue;
            if (q[0]+q[1]+q[2]<p[3]) continue;
            if (p[0]+p[1]+p[2]<p[3]) {
                INT mid=p[0]+p[1]+p[2];
                for (int j=0; j<3; j++) {
                    if (mid-p[j]+q[j]>=p[3]) {
                        p[j]=p[3]-(mid-p[j]);
                        if (p[j]+i&1) p[j]++;
                        break;
                    }
                    mid=mid-p[j]+q[j];
                    p[j]=q[j];
                }
            }
            printf("%I64d %I64d %I64d\n", p[1]+p[2]>>1, p[0]+p[2]>>1, p[0]+p[1]>>1);
            break;
        }
    }

    return 0;
}
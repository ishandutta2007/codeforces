#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector<int> VI;

#define x first
#define y second

int n, m;
const int NN = 155;
bitset<NN> now, cur, tmp, E[NN], a[NN], b[NN], tp[NN];

void power(int N) {
    for (int i=1; i<=n; i++) b[i]=E[i];
    while (N) {
        if (N&1) {
            tmp.reset();
            for (int i=1; i<=n; i++) if ((now&b[i]).any()) tmp[i]=1;
            now = tmp;
        }
        N>>=1;
        if (N) {
            for (int i=1; i<=n; i++) tp[i].reset();
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if (b[i][j]) tp[i]|=b[j];
                }
            }
            for (int i=1; i<=n; i++) b[i]=tp[i];
        }
    }
}

pi3 p[NN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    cin>>n>>m;
    for (int i=0; i<m; i++) scanf("%d%d%d", &p[i].y.x, &p[i].y.y, &p[i].x);
    sort(p, p+m);
    int pre=0;
    now[1]=1;
    for (int i=0, j; i<m; i=j) {
        power(p[i].x-pre);
        for (j=i; j<m && p[i].x==p[j].x; j++) E[p[j].y.y].set(p[j].y.x);
        cur = now;
        for (int k=0; k<n; k++) {
            if (cur[n]) {
                printf("%d\n", p[i].x+k);
                return 0;
            }
            tmp.reset();
            for (int r=1; r<=n; r++) if ((cur&E[r]).any()) tmp[r]=1;
            cur = tmp;
        }
        pre=p[i].x;
    }

    puts("Impossible");
    
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1000000+10;
int n,k;
int v[N],c[N];
int mx[N][20],mn[N][20],LG[N];
void init() {
    for(int i=1;i<N;i++) LG[i]=(int)(log2(i));
    for(int i=1;i<=n;i++)mx[i][0]=v[i],mn[i][0]=c[i];
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            if(j+(1<<i)>=n+2) continue;
            mn[j][i] = min(mn[j][i-1], mn[j+(1<<(i-1))][i-1]);
            mx[j][i] = max(mx[j][i-1], mx[j+(1<<(i-1))][i-1]);
        }
    }
}

bool ok=0;
int rmq(int l,int r) {
    int len = (r-l+1);
    int k = LG[len];
    ok = min(mn[l][k],mn[r-(1<<k)+1][k]) >= 100*max(mx[l][k],mx[r-(1<<k)+1][k]);
    return min(min(mn[l][k],mn[r-(1<<k)+1][k]),100*max(mx[l][k],mx[r-(1<<k)+1][k]));
}

int ans[N];
void solve(int x) {
    int L=x, R=n;
    while(R-L>1) {
        int mid=(L+R)>>1;
        rmq(x,mid);
        if(ok) L=mid;
        else R=mid;
    }
    ans[x] = 0;
    for(int i=L-10;i<=L+10;i++) {
        if(i<=n&&i>=x) ans[x] = max(ans[x], rmq(x,i));
    }
}
double p[N]; // p[i]: minid >= i
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    init(); //printf("LG=%d\n", LG[1000000]);
    for(int i=1;i<=n;i++) solve(i);
    sort(ans+1,ans+1+n);
    p[1]=1; int tmp=n;
    for(int i=2;i<=n-k+1;i++) {
        p[i] = p[i-1] * (tmp-k) / tmp; tmp--;
    }
    double res = 0;
    for(int i=1;i<=n;i++) {
        p[i] = p[i]-p[i+1];
        //printf("%.8f\n", p[i]);
        res = res + p[i] * ans[i];
    }
    printf("%.8f\n", res);
}
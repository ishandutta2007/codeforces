#include <iostream>
#include <algorithm>
using namespace std;
const int N=300000+10;
typedef long long LL;
int n,m;
struct Nod{
    LL x,y,id, ans;
    bool operator < (const Nod & o) const {
        return x-y > o.x-o.y;
    }
} nod[N], tmp[N];
LL pre[N],suf[N],res[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%lld%lld",&nod[i].x,&nod[i].y);
        nod[i].id = i; tmp[i]=nod[i];
    }
    sort(nod+1,nod+1+n);

    for(int i=1;i<=n;i++) pre[i] = pre[i-1] + nod[i].y;
    for(int i=n;i>=1;i--) suf[i] = suf[i+1] + nod[i].x;
    for(int i=1;i<=n;i++) {
        nod[i].ans += (i-1) * nod[i].x + pre[i-1] + (n-i) * nod[i].y +suf[i+1];
        res[nod[i].id] = nod[i].ans;
    }

    for(int i=1;i<=m;i++) {
        int u,v; scanf("%d%d",&u,&v);
        LL mn = min(tmp[u].x+tmp[v].y, tmp[u].y+tmp[v].x);
        res[u]-=mn, res[v]-=mn;
    }
    for(int i=1;i<=n;i++) {
        printf("%lld ",res[i]);
    }
}
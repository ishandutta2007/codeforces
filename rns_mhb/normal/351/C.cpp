#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 51
int res[N][N],d[N][N],ans[N][N],n,m;
int a[N],b[N];
void cheng(int a[N][N],int b[N][N]) {
    int c[N][N];
    memset(c,120,sizeof(c));
    for (int i=0;i<=2*n;i++) for (int j=0;j<=2*n;j++) for (int k=0;k<=2*n;k++) {
        c[i][k]=min(ll(c[i][k]),(ll)a[i][j]+b[j][k]);
    }
    memcpy(a,c,sizeof(c));
}
int main() {
    //freopen("C.in","r",stdin);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    for (int i=1;i<=n;i++) scanf("%d",b+i);
    memset(d,120,sizeof(d));
    for (int i=0;i<=2*n;i++) d[i][i]=0;
    for (int i=1;i<=n;i++) {
        memcpy(res,d,sizeof(d));
        memset(d,120,sizeof(d));
        for (int j=0;j<=2*n;j++) for (int k=0;k<=2*n;k++) {
            if (k!=0) d[j][k-1]=min(d[j][k-1],res[j][k]+b[i]);
            if (k!=2*n) d[j][k+1]=min(d[j][k+1],res[j][k]+a[i]);
        }
    }
    memset(ans,120,sizeof(ans));
    ans[0][0]=0;
    while (m) {
        if (m&1) cheng(ans,d);
        cheng(d,d);
        m>>=1;
    }
    printf("%d\n",ans[0][0]);
}
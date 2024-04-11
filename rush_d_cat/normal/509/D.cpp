#include <iostream>
using namespace std;
const int N=102;
typedef long long LL;
int n,m; 
LL a[N][N], row[N], col[N];
LL r[N],c[N];
int main() {
    scanf("%d%d",&n,&m);
    LL mx=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        scanf("%lld",&a[i][j]), mx=max(mx,a[i][j]);

    LL mod = 0;
    for(int i=1;i<n;i++){
        LL dt1=-1,dt2=+1;
        for(int j=1;j<=m;j++){
            if(a[i][j]<=a[i+1][j]){
                if(dt1>=0 && a[i+1][j]-a[i][j]!=dt1) {
                    return !printf("NO\n");
                }
                dt1 = a[i+1][j] - a[i][j];
            } else {
                if(dt2<=0 && a[i+1][j]-a[i][j]!=dt2) {
                    return !printf("NO\n");
                }
                dt2 = a[i+1][j] - a[i][j];
            }
        }
        //printf("# %lld %lld\n", dt1, dt2);
        if(dt1>=0 && dt2<=0) {
            LL tmp = dt1 - dt2;
            if(mod==0) mod=tmp;
            else {
                if(tmp!=mod) {
                    return !printf("NO\n");
                }
            }
        }
        if(dt1>=0) {
            row[i] = dt1;
        } else {
            row[i] = dt2;
        }
    }

   // printf("mod=%d\n", mod);
    for(int i=1;i<m;i++){
        LL dt1=-1,dt2=+1;
        for(int j=1;j<=n;j++){
            if(a[j][i]<=a[j][i+1]){
                if(dt1>=0 && a[j][i+1]-a[j][i]!=dt1) {
                    return !printf("NO\n");
                }
                dt1 = a[j][i+1] - a[j][i];
            } else {
                if(dt2<=0 && a[j][i+1]-a[j][i]!=dt2) {
                    return !printf("NO\n");
                }
                dt2 = a[j][i+1] - a[j][i];
            }
        }
        if(dt1>=0 && dt2<=0) {
            LL tmp = dt1 - dt2;
            if(mod==0) mod=tmp;
            else {
                if(tmp!=mod) {
                    return !printf("NO\n");
                }
            }
        }
        if(dt1>=0) {
            col[i] = dt1;
        } else {
            col[i] = dt2;
        }
    }
    if(mod==0) mod=1e18;
    if(mod<=mx)return !printf("NO\n");
    
    
    r[1]=0,c[1]=a[1][1];
    for(int i=1;i<n;i++) r[i+1] = ((r[i]+row[i])%mod+mod)%mod;
    for(int i=1;i<m;i++) c[i+1] = ((c[i]+col[i])%mod+mod)%mod;
    
    printf("YES\n");
    printf("%lld\n", mod);
    for(int i=1;i<=n;i++) printf("%lld ", r[i]); printf("\n");
    for(int i=1;i<=m;i++) printf("%lld ", c[i]); printf("\n");
}
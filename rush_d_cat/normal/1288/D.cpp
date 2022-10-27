#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int n,m;
int a[N][9];
int f1,f2;
bool chk(int x){
    int has[1<<8]={0};
    for(int i=1;i<=n;i++){
        int mask=0;
        for(int j=1;j<=m;j++){
            if(a[i][j]>=x)mask|=(1<<(j-1));
        }
        has[mask]=i;
    }
    for(int i=0;i<1<<m;i++){
        for(int j=0;j<1<<m;j++){
            if((has[i]>0)&&(has[j]>0)&&((i|j)==(1<<m)-1)){
                f1=has[i],f2=has[j];
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int l=0,r=1e9+1;
    while(r-l>1){
        int mid=(l+r)>>1;
        if(chk(mid)) l=mid;
        else r=mid;
    }
    chk(l);
    printf("%d %d\n", f1,f2);
}
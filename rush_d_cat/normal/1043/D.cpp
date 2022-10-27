#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100000+10;
int n,m,p[12][N],a[12][N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]), p[i][a[i][j]]=j;
    LL ans=0;
    for(int l=1,r=1;l<=n;l=r){
        while(r<=n) {
            bool ok=1;
            for(int i=2;i<=m;i++)
                if(a[i][ p[i][a[1][l]] + (r-l)] != a[1][r]) ok=0;
            //printf("l=%d,r=%d\n", l,r);
            if(ok) r++; else break;
        }
        ans += (LL)(r-l)*(r-l+1)/2;
    }
    cout<<ans<<endl;
}
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 300000+10;
int n;
LL a[N][2],f[N][2];
LL pre1[N][2],pre2[N][2],suf1[N][2],suf2[N][2];

int main() {
    scanf("%d",&n);
    for(int j=0;j<2;j++) for(int i=1;i<=n;i++) scanf("%lld",&a[i][j]);
    
    f[0][0]=0, f[0][1]=-1e12;
    f[1][0]=-1e12; f[1][1]=a[1][0]+2*a[1][1];
    for(int i=2;i<=n;i++) {
        f[i][0]=f[i-1][1]+(2LL*i-1)*a[i][1]+2LL*i*a[i][0];
        f[i][1]=f[i-1][0]+(2LL*i-1)*a[i][0]+2LL*i*a[i][1];
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<2;j++) {
            pre1[i][j]=pre1[i-1][j]+a[i][j];
            pre2[i][j]=pre2[i-1][j]+1LL*i*a[i][j];
        }
    }
    for(int i=n;i>=1;i--) {
        for(int j=0;j<2;j++) {
            suf1[i][j]=suf1[i+1][j]+a[i][j];
            suf2[i][j]=suf2[i+1][j]+1LL*(n-i+1)*a[i][j];
        }
    }
    LL ans=0;
    for(int i=0;i<n;i++) {
        LL tmp0 = f[i][0] + (pre2[n][0]-pre2[i][0]) + 1LL*i*(pre1[n][0]-pre1[i][0]) 
        + suf2[i+1][1] + 1LL*(i+n)*suf1[i+1][1];

        LL tmp1 = f[i][1] + (pre2[n][1]-pre2[i][1]) + 1LL*i*(pre1[n][1]-pre1[i][1])
        + suf2[i+1][0] + 1LL*(i+n)*suf1[i+1][0];
        //printf("%lld  %lld %lld\n", (pre2[n][1]-pre2[i][1]) ,1LL*i*(pre1[n][1]-pre1[i][1]), suf2[i+1][0] + 1LL*(i+n)*suf1[i+1][0]);
        //printf("%lld %lld\n", tmp0,tmp1);
        ans = max(ans, tmp0); 
        ans = max(ans, tmp1);
    }
    ans = max(ans, f[n][0]);
    ans = max(ans, f[n][1]);

    LL sum=0;
    for(int i=1;i<=n;i++) sum+=a[i][0]+a[i][1];
    cout << (ans-sum) << endl;
}
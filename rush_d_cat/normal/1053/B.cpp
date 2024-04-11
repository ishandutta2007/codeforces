#include <iostream>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int n; 
LL a[N], c[N];
LL ans = 0;
LL sum[N][2];
int count(LL x) {
    int ans=0;
    while(x) {
        if(x%2==1) ans++; x/=2;
    }    
    return ans;
}
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%lld", &a[i]);
        c[i] = count(a[i]);
    }
    int L = 65;
    for(int i=1;i<=n;i++) {
        int s=0,mx=0;
        for(int j=i;j<=min(i+L-1,n);j++){
            s+=c[j], mx=max(mx,(int)c[j]);
            if(s%2==0 && 2*mx<=s) ans++;
        }
    }
    for(int i=1;i<=n;i++) c[i] += c[i-1];
    sum[0][0]=1;
    for(int i=1;i<=n;i++) {
        sum[i][0] = sum[i-1][0] + ((c[i]%2==0)?1:0);
        sum[i][1] = sum[i-1][1] + ((c[i]%2==0)?0:1);
        //printf("%lld %lld\n", sum[i][0],sum[i][1]);
    }

    for(int i=L+1;i<=n;i++) {
        if(c[i]%2==1) {
            ans = ans + sum[i-(L+1)][1];
        } else {
            ans = ans + sum[i-(L+1)][0];
        }
        //cout << ans << endl;
    }
    cout<<ans<<endl;
}
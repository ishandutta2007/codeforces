#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000000 + 10;
typedef long long LL;
const LL MOD = 1e9+7;
LL fac[N],inv[N]; int n, cnt[50];
LL a[50][2], p[50][2];LL pre[50], suf[50];
int main() {
    inv[1]=1; for(int i=2;i<N;i++) inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
    fac[0]=1; for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%MOD;

    cin >> n;
    for(int i=1;i<=n;i++){
        int t=i,c=0;
        while(t%2==0){
            t/=2,c++;
        }
        cnt[c]++;
    }
    int mx=0;
    for(int i=49;i>=0;i--){
        if(cnt[i]) {
            mx=i; break;
        }
    }
    LL ans=0;

    LL sum=n,tmp=fac[n];
    for(int i=mx;i>=0;i--){
        tmp = tmp * cnt[i] % MOD * inv[sum] % MOD; 
        sum -= cnt[i];
    }
    ans=tmp;
    for(int i=1;i<=n;i++) {
        int t=i,c=0;
        while(t%2==0){
            t/=2,c++;
        }
        c=min(c,mx-1);
        if(i%3==0) a[c][1]++; else a[c][0]++;     
    }
    for(int i=mx-1;i>=0;i--) {
        //printf("i=%d\n", i);
        LL tmp=1,sum=n;
        for(int j=mx-1;j>=i;j--){
            //printf("1 %d/%d\n", a[j][1],sum);
            tmp=tmp*a[j][1]%MOD*inv[sum]%MOD; sum -= a[j][1];
        }
        LL tmpsum=0; for(int j=i;j<mx;j++) tmpsum += a[j][0];
        tmp=tmp*tmpsum%MOD*inv[sum]%MOD; sum -= tmpsum;
        for(int j=i-1;j>=0;j--){
            //printf("2 %d/%d\n", a[j][0]+a[j][1],sum);
            tmp=tmp*(a[j][0]+a[j][1])%MOD*inv[sum]%MOD; sum -= (a[j][0]+a[j][1]);
        }
        ans = (ans + tmp * fac[n] % MOD) % MOD;
    }
    cout << ans << endl;
}
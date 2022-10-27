#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
const int N=100000+10;
const LL MOD = 1e9 + 7;

LL n,k,inv[100];

LL dp[10002][62];
int tot=0; LL ans = 1;
void gen(int id,LL x,int c) {
    //printf("id=%d, x=%lld,c=%d\n", id,x,c);

    for(int i=0;i<=k;i++)for(int j=0;j<=c;j++)dp[i][j]=0;
    dp[0][c]=1;
    for(int i=0;i<k;i++){
        LL sum=0;
        for(int j=c;j>=0;j--){
            sum = (sum + dp[i][j] * inv[j+1]) % MOD;
            dp[i+1][j] = (dp[i+1][j] + sum) % MOD;
        }
    }

    LL tmp = 1, res = 0;
    for(int i=0;i<=c;i++) {
        res = (res + dp[k][i] * tmp % MOD) % MOD;
        tmp = tmp * x % MOD;
    }
    ans = ans * res % MOD;
}

int main(){
    inv[1]=1;
    for(int i=2;i<100;i++){
        inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
    }

    cin>>n>>k;
    for(LL x=2;x*x<=n;x++){
        if(n%x==0){
            int c=0;
            while(n%x==0){
                n/=x; ++c;
            }
            gen(++tot, x,c);
            //printf("%lld %d\n", x,c);
        }
    }
    if(n>1) {
        gen(++tot,n,1);
        //printf("%lld 1\n", n);
    }
    cout << ans << endl;

}
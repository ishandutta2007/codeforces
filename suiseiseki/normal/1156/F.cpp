#include <cstdio>
using namespace std;
#define ll long long
#define Maxn 5000
#define Mod 998244353
int n,a[Maxn+5],cnt[Maxn+5];
int num[Maxn+5],len;
ll fac[Maxn+5];
ll dp[Maxn+5][Maxn+5];
ll quick_pow(ll a,ll b){
    ll res=1ll;
    while(b){
        if(b&1){
        	res=res*a%Mod;
		}
        a=a*a%Mod;
        b>>=1;
    }
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    fac[0]=1ll;
    for(int i=1;i<=Maxn;i++){
    	fac[i]=fac[i-1]*i%Mod;
	}
    for(int i=1;i<=Maxn;i++){
    	if(cnt[i]){
            num[++len]=i;
            cnt[len]=cnt[i];
    	}
	}
    ll ans=0ll;
    for(int i=0;i<=len;i++){
    	dp[i][0]=1ll;
	}
    for(int i=1;i<=len;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=(dp[i-1][j-1]*cnt[i]+dp[i-1][j])%Mod;
        }
    }
    for(int i=1;i<=len;i++){
        if(cnt[i]>=2){
            for(int j=i;j>0;j--){
            	ans=(ans+((dp[i-1][j-1]*cnt[i]%Mod*(cnt[i]-1))%Mod)*fac[n-2-j+1]%Mod)%Mod;
            }
        }
    }
    ans=ans*quick_pow(fac[n],Mod-2)%Mod;
    printf("%I64d\n",ans);
    return 0;
}
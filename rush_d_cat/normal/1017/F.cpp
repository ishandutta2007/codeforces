#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1000000+10;
const LL MOD = (1LL<<32);
LL n,a,b,c,d,ans;
void getAns(LL x) {
    LL k=x,res=0;
    while(x<=n) {
        res += (a*k%MOD*k%MOD*k%MOD + b*k%MOD*k%MOD + c*k%MOD + d) * (n/x);
        res %= MOD; x *=k;
    }
    ans += res; ans %= MOD;
}
int prime[N],nprime[N];
void getprime() {
    for(int i=2;i<N;i++){
        if(nprime[i]==0) {
            getAns(i);
            prime[++prime[0]]=i;
            for(int j=2*i;j<N;j+=i){
                nprime[j]=1;
            }
        }
    }
}
void getprime2(int L,int R) {
    memset(nprime,0,sizeof(nprime));
    for(int i=1;i<=prime[0];i++) {
        int j=(L+prime[i]-1)/prime[i]; 
        for(;j<=R/prime[i];j++) {
            nprime[prime[i]*j - L]=1;
        }        
    }
    for(int i=0;i<N;i++) {
        if(nprime[i]==0) getAns(i+L);
    }
}
int main() {
    cin>>n>>a>>b>>c>>d;
    getprime();
    LL BLK = N, las = N;
    while(true) {
        int rig = min(n+1, las+N);
        getprime2(las, rig-1);
        las = rig; if(las == n+1) break;
    }
    cout<<ans<<endl;
}
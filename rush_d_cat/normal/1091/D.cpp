#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
typedef long long LL;
const int MOD=998244353;
const int N=2000000+10;
LL inv[N],f[N];
int c(int a,int b){
    return f[a]*inv[b]%MOD*inv[a-b]%MOD;
}
int main(){
    inv[1]=1;inv[0]=1;f[0]=1;
    for(int i=2;i<N;i++){
        inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
    }    
    for(int i=1;i<N;i++){
        f[i]=f[i-1]*i%MOD;
        inv[i]=inv[i-1]*inv[i]%MOD;
    }
    int n; cin >> n;
    LL ans=0;
    for(int k=0;k<n;k++)ans=(ans+c(n,k)*f[k]%MOD*(f[n-k]-1)%MOD)%MOD;
    ans=(ans+1)%MOD;
    cout<<ans<<endl;
}
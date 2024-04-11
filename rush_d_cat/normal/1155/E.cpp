#include <iostream>
using namespace std;
typedef long long LL;
const int N = 20;
const LL MOD = 1e6+3;
LL inv[MOD];
LL mpow(LL a, LL x) {
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0)return t*t%MOD;
    return t*t%MOD*a%MOD;
}
struct Larg {
    int n;
    LL x[N],y[N],w[N],M;
    void init() {
        for(int i=1;i<=n;i++){
            w[i]=1;
            for(int j=1;j<=n;j++){
                if(i!=j) w[i]=w[i]*(x[i]-x[j])%MOD;
            }
            w[i]=(w[i]%MOD+MOD)%MOD;
            w[i]=mpow(w[i],MOD-2);
        }
    }
    LL f(LL val) {
        M=1; 
        for(int i=1;i<=n;i++) {
            if(x[i]==val) return y[i];
            M=M*(val-x[i])%MOD;
        }
        M=(M%MOD+MOD)%MOD;
        LL ans=0;
        for(int i=1;i<=n;i++) {
            ans=ans+M*inv[((val-x[i])%MOD+MOD)%MOD]%MOD*w[i]%MOD*y[i]%MOD;
            ans=(ans%MOD+MOD)%MOD;
        }
        return ans;
    }
} L;
int main() {
    inv[1]=1;
    for(int i=2;i<MOD;i++) {
        inv[i] = (MOD-(MOD/i))*inv[MOD%i]%MOD;
    }
    int B=11;
    L.n=B;
    for(int i=0;i<B;i++) {
        printf("? %d\n", i); fflush(stdout);
        int val; scanf("%d",&val);
        L.x[i+1]=i, L.y[i+1]=val;
    }
    L.init();
    for(int i=0;i<MOD;i++){
        if(L.f(i) == 0) {
            printf("! %d\n", i); fflush(stdout); return 0;
        }
    }
    printf("! %d\n", -1); fflush(stdout); return 0;
}
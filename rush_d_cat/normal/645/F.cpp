#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;

const int N = 1000000 + 10;
LL fac[N],inv[N],I[N];

int prime[N], cnt = 0;
bool vis[N]; 
int phi[N], mius[N];

void getPrime() {
    I[1]=inv[1]=1; I[0]=inv[0]=1; fac[0]=1;
    for(int i=2;i<N;i++){
        inv[i]=1LL*(MOD-(MOD/i))*inv[MOD%i]%MOD; I[i]=inv[i];
    }
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=inv[i-1]*inv[i]%MOD;
    }
    phi[1] = 1, mius[1] = 1;
    for (int i = 2; i < N; i ++) {
        if (vis[i] == 0) {
            prime[++ cnt] = i;
            phi[i] = i - 1;
            mius[i] = -1;
        }
        for (int j = 1; j <= cnt && prime[j] * i < N; j ++) {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0) {           
                mius[prime[j] * i] = 0;
                phi[prime[j] * i] = phi[i] * prime[j];
                break;
            } else {
                mius[prime[j] * i] = mius[i] * -1;
                phi[prime[j] * i] = phi[i] * (prime[j] - 1);
            }
        }
    }
}

int C(int n,int m){
    if(n<m) return 0;
    return fac[n] * inv[m] % MOD * inv[n-m] % MOD;
}

vector<int> D[N],M[N];
int n,k,q,c[N],a[N],b[N],K[N];
LL f[N],g[N];
int main(){
    getPrime();

    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); b[a[i]]++;
    }
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            D[j].push_back(i);
            //if(mius[i]) M[j].push_back(i);
            K[j] += mius[j/i] * i;
            c[i] += b[j];
        }
        f[i] = C(c[i], k);
    }

    LL ans=0;
    for(int i=N-1;i>=1;i--){
        g[i]=f[i];
        for(int j=i+i;j<N;j+=i){
            g[i]-=g[j]; g[i]%=MOD;
        }
        ans=(ans+g[i]*i)%MOD;
    }   
    // g[x] = f[x] - f[2x] - f[3x] + f[6x]
    for(int i=1;i<=q;i++){
        int u; scanf("%d", &u);
        for(auto x: D[u]) {
            LL nex;
            nex = f[x] * (c[x]+1) % MOD * (c[x]-k+1>=0?I[c[x]-k+1]:0) % MOD;
            if(c[x]+1 == k) nex = 1;
            c[x] = c[x] + 1;
            ans = (ans + K[x] * (nex - f[x])) % MOD;
            f[x] = nex;

        }
        ans=(ans%MOD+MOD)%MOD;
        printf("%lld\n", ans);
    }
}
/*
g[1] = f[1] - f[2] - f[3] + f[6]
g[2] = f[2] - f[4] - f[6]
g[3] = f[3] - f[6]
g[6] = f[6]


*/
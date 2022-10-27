#include <iostream>
using namespace std;
const int MOD = 998244353;
typedef long long LL;
const int N = 4002;
LL f[N];
LL mpow(LL a, LL x){
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if (x%2==0) return t*t%MOD;
    return t*t%MOD*a%MOD;
}
LL C(int a,int b){
    return f[a] * mpow(f[b],MOD-2) % MOD * mpow(f[a-b],MOD-2) % MOD;
}

int n,m,k;
int main() {
    f[0]=1; for(int i=1;i<N;i++) f[i]=f[i-1]*i%MOD;
    cin>>n>>m>>k;
    LL ans = C(n-(k+1)+k, k);
    ans = ans * m % MOD * mpow(m-1, k) % MOD;
    cout << ans << endl;
}

/*
x1 + x2 + ... + x_{k+1} = n


x1 + x2 + ..... x_{k+1} = n - (k+1)

*/
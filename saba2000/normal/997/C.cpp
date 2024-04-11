#include<bits/stdc++.h>
using namespace std;
long long fc[1000009],inv[1000009],ifc[1000009], mod =  998244353;
long long exp(long long a, long long b){
    if(!b) return 1;
    if(b&1) return a *exp(a,b-1)%mod;
    return exp(a*a%mod, b/2);
}

long long po[1000009],CC[1000009];
void prec(long long n){
    fc[0] = 1;
    inv [0] = 1;
    inv[1] = 1;
    ifc[0] =1;
    po[0] =1;
    for(long long i = 1; i <= n; i++){
        po[i] = po[i-1]*3%mod;
        fc[i] = fc[i-1]*i % mod;
        if(i > 1)inv[i] = inv[mod % i] * (mod - mod/i)% mod;
        ifc[i] = ifc[i-1] * inv[i] % mod;
    }
}
long long C (long long n, long long m){
    if(m > n || m < 0) return 0;
    return (fc[n] * ifc[m] % mod) * ifc[n-m] % mod;
}
main(){
    long long n;
    cin >> n;
    prec(n);
    for (long long i = 0; i <=n; i++)
        CC[i] =C(n,i);
    long long a = 0, b= 0, c = 0;
    for (long long i = 0; i < n; i++){
        long long A;
        if((i)% 2 == 0) A = 1; else A = -1;

            c =(c+A*3*CC[i]*(exp(1+mod-po[i],n)-exp(mod-po[i],n)+mod))%mod;
        }

    long long E = exp(3,n)-3+mod;
    for(long long i = 1; i <= n; i++){

        a = (a+CC[i]*exp(E, n-i)%mod*po[i])%mod;
    }
    cout << (2*a - c+mod)%mod<< endl;
}
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 200003
#define ll long long
#define reg register
#define p 998244353
using namespace std;
int power(int a,int t){
    int res = 1;
    while(t){
        if(t&1) res = (ll)res*a%p;
        a = (ll)a*a%p;
        t >>= 1;
    }
    return res;
}
int fac[N],ifac[N];
void init(int n){
    fac[0]=fac[1]=ifac[0]=ifac[1]=1;
    for(int i=2;i<=n;i++){
    	fac[i]=1ll*fac[i-1]*i%p;
	}
	ifac[n]=power(fac[n],p-2);
	for(int i=n-1;i>=0;i--){
		ifac[i]=1ll*ifac[i+1]*(i+1)%p;
	}
}

int pw[N],pr[N>>1];

void sieve(int n,int k){
    int cnt = 0;
    pw[1] = 1;
    for(reg int i=2;i<=n;++i){
        if(!pw[i]){
            pr[++cnt] = i;
            pw[i] = power(i,k);
        }
        for(reg int j=1;j<=cnt&&i*pr[j]<=n;++j){
            pw[i*pr[j]] = (ll)pw[i]*pw[pr[j]]%p;
            if(i%pr[j]==0) break;
        }
    }
}
int S(int n,int m){
    sieve(m,n);
    ll res=0;
    for(reg int i=1;i<=m;++i){
        int g=(ll)pw[i]*ifac[i]%p*ifac[m-i]%p;
        res+=(m-i)&1?p-g:g;
    }
    return res%p;
}
int n,k;
int main(){
    ll _k;
    scanf("%d%lld",&n,&_k);
    if(_k>=n){
        putchar('0');
        return 0;
    }
    k=_k;
    init(n-k);
    if(k==0){
        printf("%d",fac[n]);
        return 0;
    }
    int ans = 2ll*S(n,n-k)%p;
    for(reg int i=n;i>k;--i) ans = (ll)ans*i%p;
    printf("%d",ans);
}
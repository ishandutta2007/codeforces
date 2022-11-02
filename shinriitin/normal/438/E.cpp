#include <stdio.h>
#include <string.h>
#include <algorithm>
#define TQ template<class Q>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

TQ inline void Scan(Q&x){
    char c;while(c=getchar(),c<48||c>57);
    for(x=0;c>47&&c<58;c=getchar())x=10*x+c-48;
}

const int MAXN=(1<<19)+5;
typedef long long ll;
const int P=998244353;
const int r2=499122177;
const int G=3;

inline ll qpow(ll x,int k){
    ll ans=1;
    for(;k;x=x*x%P,k>>=1)
        if(k&1)ans=ans*x%P;
    return ans;
}

int rev[MAXN],w[2][MAXN],rn;
inline void init_fft(int n,int bit){
    int g=qpow(G,(P-1)/n);
    w[0][0]=w[0][n]=1;
    rep(i,1,n-1)w[0][i]=(ll)w[0][i-1]*g%P;
    rep(i,0,n)w[1][i]=w[0][n-i];
    rn=qpow(n,P-2);
    rep(i,0,n-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
}

inline void fft(int*a,int n,int t){
    rep(i,1,n-1)if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int i=2;i<=n;i<<=1)
        for(int j=0;j<n;j+=i)
            for(int k=0;k<i>>1;++k){
                int tmp=(ll)w[t][n/i*k]*a[(i>>1)+j+k]%P;
                a[(i>>1)+j+k]=(a[j+k]+P-tmp)%P;
                a[j+k]=(a[j+k]+tmp)%P;
            }
    if(t)rep(i,0,n-1)a[i]=(ll)a[i]*rn%P;
}

inline void inv(int*a,int*b,int n,int bit){
    static int t[MAXN];
    b[0]=qpow(a[0],P-2),b[1]=0;
    int len=1;
    rep(i,1,bit){
        len<<=1;
        init_fft(len<<1,i+1);
        rep(j,0,len)t[j]=a[j];
        rep(j,len,len<<1)t[j]=b[j]=0;
        fft(t,len<<1,0),fft(b,len<<1,0);
        rep(j,0,len<<1){
            b[j]=(ll)b[j]*(2-(ll)t[j]*b[j]%P+P)%P;
        }
        fft(b,len<<1,1);
        rep(j,len,len<<1)b[j]=0;
    }
}

inline void sqrt(int*a,int*b,int n,int bit){
    static int t[MAXN],rb[MAXN];
    b[0]=1,b[1]=0;
    int len=1;
    rep(i,1,bit){
        len<<=1;
        inv(b,rb,len,i);
        rep(j,0,len)t[j]=a[j];
        rep(j,len,len<<1)t[j]=0;
        init_fft(len<<1,i+1);
        fft(t,len<<1,0),fft(b,len<<1,0),fft(rb,len<<1,0);
        rep(j,0,len<<1){
            b[j]=ll(b[j]+(ll)t[j]*rb[j]%P)%P*r2%P;
        }
        fft(b,len<<1,1);
        rep(j,len,len<<1)b[j]=0;
    }
}

int n,m,len;

int a[MAXN],b[MAXN];

inline void Init(){
    Scan(n),Scan(m);
    a[0]=1;
    for(int i=1,x;i<=n;++i){
        Scan(x);
        a[x]=P-4;
    }
}

inline void Solve(){
    len=m+3;
    int bit=1;
    while(1<<bit<len)++bit;
    len=1<<bit;
    sqrt(a,b,len,bit);
    (++b[0])%=P;
    inv(b,a,len,bit);
    rep(i,1,m)printf("%d\n",(a[i]<<1)%P);
}

int main(){
    Init(); Solve(); return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

const int N = 600000 + 10;
typedef long long LL;
const int MOD = 998244353;
const int root = 15311432;   // root ^ (2^23) % MOD = 1
const int root_1 = 469870224; // root * root_1 = 1
const int root_pw = 1 << 23; // 998244353 = 119 * 2^23 + 1
LL mpow(LL a,LL x){
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0)return t*t%MOD;
    return t*t%MOD*a%MOD;
}
LL modinv(LL a){
    LL x0=0,x1=1,r0=MOD,r1=a;
    while(r1){
        LL q=r0/r1;
        x0-=q*x1;swap(x0,x1);
        r0-=q*r1;swap(r0,r1);
    }
    return x0<0?x0+MOD:x0;
}
void fft(vector<int> &a, bool inv) { // a.size()2
    int n=(int)a.size();
    //   butterfly
    for(int i=1,j=0;i<n;i++) {
        int bit=n>>1;
        for(;j>=bit;bit>>=1) j-=bit; j+=bit;   
        if(i<j)swap(a[i],a[j]);
    }
    //  DFT
    for(int len=2;len<=n;len<<=1) {
        int wlen=inv?root_1:root;
        for(int i=len;i<root_pw;i<<=1) wlen=wlen*1LL*wlen%MOD;
        for(int i=0;i<n;i+=len) {
            int w=1;
            for(int j=0;j<len/2;j++) {
                int u=a[i+j],v=int(a[i+j+len/2]*1LL*w%MOD);
                a[i+j] = (u+v<MOD)?u+v:u+v-MOD;
                a[i+j+len/2] = (u-v>=0)?u-v:u-v+MOD;
                w = w*1LL*wlen%MOD;
            }
        }
    }
    if(inv) {
        int nrev = modinv(n);
        for(int i=0;i<n;i++) a[i]=a[i]*1LL*nrev%MOD;
    }
}

void pro(const vector<int> &a, const vector<int> &b, vector<int> &res) {
    vector<int> fa(a.begin(), a.end()),fb(b.begin(), b.end());
    int n=1; while (n<(int) max(a.size(), b.size())) n<<=1; n<<=1;
    fa.resize(n),fb.resize(n);
    fft(fa,false), fft(fb,false);
    for(int i=0;i<n;i++) fa[i] = 1LL*fa[i]*fb[i]%MOD;
    fft(fa,true);
    res = fa;
}

int n,k,a[N],b[N],c[N];

LL inv[N], fac[N], invfac[N], pw[N];
LL C(int x, int y) {
    return fac[x] * invfac[y] % MOD * invfac[x - y] % MOD;
}
vector<int> res[6];
void init() {
    for (int i = 1; i <= k; i ++) {
        int A = 0, B = 0;
        for (int j = 1; j < b[i]; j ++) {
            if (c[j] > 1) {
                A ++; 
            } else if (c[j] == 1) {
                B ++;
            }
        } 
        // (x+1)^{2A} * (2x+1)^{B}
        vector<int> v1, v2, r;
        for (int j=0;j<=2*A;j++) v1.push_back(C(2*A, j));
        for (int j=0;j<=B;j++) v2.push_back(C(B,j) * pw[j] % MOD);
        pro(v1,v2,res[i]);
    }
}

int main() {
    pw[0]=1;for(int i=1;i<N;i++)pw[i]=pw[i-1]*2%MOD;
    inv[1]=1;
    for(int i=2;i<N;i++){
        inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
    }
    fac[0] = invfac[0] = 1;
    for(int i=1;i<N;i++) {
        fac[i] = fac[i-1] * i % MOD;
        invfac[i] = invfac[i-1] * inv[i] % MOD;
    }
    scanf("%d%d", &n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); c[a[i]] ++;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&b[i]);
    }
    sort(a+1,a+1+n);
    init();
    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d",&x);
        LL ans=0;
        for(int i=1;i<=k;i++) {
            int len = x/2 - b[i] - 1;
            if (len >= 0 && len < res[i].size()) ans = (ans + res[i][len]) % MOD;
        }
        printf("%lld\n", ans);
    }
}
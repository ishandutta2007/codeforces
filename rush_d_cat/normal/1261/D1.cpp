#include <iostream>
#include <vector>
using namespace std;
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
void pro(const vector<int> &a, int k, vector<int> &res) {
    vector<int> fa(a.begin(), a.end());
    int n=1; while (n<(int)a.size()) n<<=1; n<<=1;
    fa.resize(n);
    fft(fa,false);
    for(int i=0;i<n;i++) fa[i] = mpow(fa[i], k);
    fft(fa,true);
    res = fa;
}
const int N = 40000 + 10;
int n, k;
int h[N];
struct P {
    int a0,a1,a2;
} p1,p2; int c1,c2;

int main() {
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++) {
        scanf("%d", &h[i]);
        //h[i] = rand() % k + 1;
    }
    p1 = (P){1,k-2,1}; 
    vector<int> v1; v1.push_back(1); v1.push_back(k-2); v1.push_back(1);
    for (int i = 0; i < N; i ++) v1.push_back(0);
    p2 = (P){0,k,0};  
    for(int i=0;i<n;i++){
        int x=h[i],y=h[(i+1)%n];
        if(x==y) {
            c1++;
        } else {
            c2++;
        }
    }
    //printf("c1 = %d, c2 = %d\n", c1, c2);
    pro(v1, c2, v1);

    LL sum = 0;
    for (int i=0;i<v1.size();i++) {
        //printf("%d ", v1[i]);
        v1[i] = 1LL * v1[i] * mpow(k, c1) % MOD;
        if (i + c1 > n) {
            sum = (sum + v1[i]) % MOD;
        }
    }
//printf("\n");
    printf("%lld\n", sum);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, a[N], b[N];
const LL MOD = 998244353;
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
    int n=1; while (n<(int) max(a.size(), b.size())) n<<=1; 
    fa.resize(n),fb.resize(n);
    fft(fa,false), fft(fb,false);
    for(int i=0;i<n;i++) fa[i] = 1LL*fa[i]*fb[i]%MOD;
    fft(fa,true);
    res = fa;
}


LL fac[N],inv[N];

LL c(int x,int y){
	if(y<0||y>x) return 0;
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}

int main() {
	inv[1]=1;
	for(int i=2;i<N;i++){
	    inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
	}
	fac[0]=1,inv[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=inv[i-1]*inv[i]%MOD;
	}

	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	int now=1; vector<int> f(1,1);
	for(int it=1;it<=n;it++){
		vector<int> g(now+a[it]-b[it],0); now+=a[it]-b[it];
		int A=a[it],B=b[it];
		vector<int> nex_f(now,0),res;
		int low=0-(f.size()-1);
		int high=now-1;
		vector<int> chicken(high-low+1,0);
		for(int i=low;i<=high;i++){
			chicken[i-low] = c(A+B,B+i);
		}
		pro(chicken,f,chicken);
		for(int i=0;i<now;i++){
			nex_f[i] = chicken[i-low];
		}
		f=nex_f;
	}
	LL ans=0;
	for(auto x: f) (ans+=x)%=MOD;	
	cout<<ans<<endl;
}
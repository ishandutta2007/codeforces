#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;

typedef long long LL;
const int MOD = 998244353;
const int root = 15311432;   // root ^ (2^23) % MOD = 1
const int root_1 = 469870224; // root * root_1 = 1
const int root_pw = 1 << 23; // 998244353 = 119 * 2^23 + 1
vector<int> d[1000000 + 10];
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
int n,x,y;
int a[N];
bool vis[N];
int main() {
	for(int i=1;i<=500000;i++){
		for(int j=i;j<=500000;j+=i){
			d[j].push_back(i);
		}
	}
	scanf("%d%d%d",&n,&x,&y);
	vector<int> v1,v2; v1.resize(x+1); v2.resize(x+1);
	for(int i=0;i<=x;i++)v1[i]=v2[i]=0;
	for(int i=1;i<=n+1;i++){
		scanf("%d",&a[i]);
		v1[a[i]]=1;
		v2[x-a[i]]=1;
	}
	pro(v1,v2,v1);
	//for(auto x: v1)printf("%d\n", x);
	for(int i=x+1;i<v1.size();i++){
		if(v1[i]) {
			//printf("has %d\n", i - x);
			if(i-x<=x)
			vis[i-x]=1;
		}
	}
	int q; scanf("%d",&q);
	while(q--){
		int l; scanf("%d",&l); l/=2;
		int ans=-1;
		for(auto val:d[l]) {
			// ? + y = val
			if (y <= val && val - y <= x && vis[val - y]) {
				ans = max(ans, 2*val);
			} 
		}
		printf("%d ", ans);
	}
}
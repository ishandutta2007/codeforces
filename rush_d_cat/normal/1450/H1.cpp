#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

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


int a[N];
LL fac[N],inv[N];

LL c(int x,int y){
	if(y<0) return 0;
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}

int n,m;
char s[N];
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

	scanf("%d%d%s",&n,&m,s);
	int tot=0,a=0,b=0;
	for(int i=0;i<n;i++){
		if(s[i]=='b'){
			if(i%2==0)tot++;
			else tot--;
		}else if(s[i]=='?'){
			if(i%2==0)++a;
			else ++b;
		}
	}
	vector<int> v1,v2,v3;
	for(int i=0;i<=a;i++) v1.push_back(mpow((MOD+1)/2, a) * c(a,i) % MOD);
	for(int i=0;i<=b;i++) v2.push_back(mpow((MOD+1)/2, b) * c(b,i) % MOD);
	reverse(v2.begin(),v2.end());
	pro(v1,v2,v3);
	LL ans=0,s=0;
	for(int i=0;i<v3.size();i++){
		LL v=i-b+tot;
		LL p=v3[i];
		//printf("v=%lld,p=%lld\n", v,p);
		if(v%2==0){
			(s+=p)%=MOD;	
		}
	}
	for(int i=0;i<v3.size();i++){
		// x + b-y = i
		// x-y=i-b
		LL v=i-b+tot;
		LL p=v3[i];
		if(v%2==0){
			ans+=abs(v)*p%MOD*mpow(s,MOD-2)%MOD;
			ans%=MOD;	
		}
	}
	ans=ans*mpow(2,MOD-2)%MOD;
	cout<<ans<<endl;
}
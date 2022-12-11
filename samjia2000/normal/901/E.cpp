#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int MAXN = (1<<19)+5;
const db pi = acos(-1);

int n;
int maxn;
LL b[MAXN],c[MAXN],a[MAXN];
LL mo;
LL A[MAXN],B[MAXN],mi[MAXN],Mi[MAXN];
int N;
LL d[MAXN];
LL b1[MAXN],c1[MAXN],d1[MAXN];

LL mul(LL x,LL y){
	LL t=db(1)*x*y/mo;
	LL ret=x*y-t*mo;
	ret=(ret%mo+mo)%mo;
	return ret;
}

LL quickmi(LL x,LL tim){
	LL ret=1;
	x=(x%mo+mo)%mo;
	for(;tim;tim/=2,x=mul(x,x))
		if(tim&1)ret=mul(ret,x);
	return ret;
}

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

LL gcd(LL x,LL y){return !y?x:gcd(y,x%y);}

bool isprime(LL x){
	int u=sqrt(x);
	fo(i,2,u)if (x%i==0)return 0;
	return 1;
}

void DFT(LL *a){
	for(int i=0,j=0;i<N;i++){
		if (i<j)swap(a[i],a[j]);
		int x=N>>1;
		for(;(j^x)<j;x>>=1)j^=x;
		j^=x;
	}
	for(int i=1,d=1;i<N;i<<=1,d++)
		for(int j=0;j<N;j+=(i<<1))
			for(int k=0;k<i;k++){
				LL l=a[j+k],r=mul(a[i+j+k],mi[(maxn>>d)*k]);
				a[i+j+k]=l<r?l-r+mo:l-r;
				a[j+k]=l+r>=mo?l+r-mo:l+r;
			}
}

void IDFT(LL *a){
	DFT(a);
	reverse(a+1,a+N);
	LL ny=quickmi(N,mo-2);
	fo(i,0,N-1)a[i]=mul(a[i],ny);
}

void dft(LL *a){
	N=1;
	while(N<=n*3)N<<=1;
	fo(i,0,N-1)A[i]=B[i]=0;
	fo(i,0,n-1){
		int w=1ll*i*i%(n*2);
		w=(n*2-w)%(n*2);
		A[i]=mul(Mi[w],a[i]);
	}
	fo(i,0,n*2){
		int w=1ll*i*i%(n*2);
		B[i]=Mi[w];
	}
	reverse(A,A+n+1);
	DFT(A),DFT(B);
	fo(i,0,N-1)A[i]=mul(A[i],B[i]);
	IDFT(A);
	fo(i,0,n-1){
		a[i]=A[i+n];
		int w=1ll*i*i%(n*2);
		w=(n*2-w)%(n*2);
		a[i]=mul(a[i],Mi[w]);
	}
}

void idft(LL *a){
	dft(a);
	reverse(a+1,a+n);
	LL ny=quickmi(n,mo-2);
	fo(i,0,n-1)a[i]=mul(a[i],ny);
}

void prepare(){
	LL ad=1;
	while(ad<=n*3)ad<<=1;
	maxn=ad;
	ad=ad*n*2/gcd(n*2,ad);
	
	mo=int(1e9)/ad*ad+ad+1;
	for(;!isprime(mo);mo+=ad);
	
	int g;
	for(g=2;;g++){
		bool yes=1;
		int u=sqrt(mo-1);
		fo(i,2,u)
		if ((mo-1)%i==0){
			yes&=quickmi(g,i)!=1;
			yes&=quickmi(g,(mo-1)/i)!=1;
		}
		if (yes)break;
	}
	
	mi[0]=1;
	mi[1]=quickmi(g,(mo-1)/maxn);
	fo(i,2,maxn)mi[i]=mul(mi[i-1],mi[1]);
	
	Mi[0]=1;
	Mi[1]=quickmi(g,(mo-1)/(n*2));
	fo(i,2,n*2)Mi[i]=mul(Mi[i-1],Mi[1]);
	
	fo(i,0,n-1)b1[i]=b[i];
	dft(b1);
	fo(i,0,n-1)c1[i]=-(c[i]-c[0])/2;
	dft(c1);
	fo(i,1,n-1)c1[i]=mul(c1[i],quickmi(b1[i],mo-2));
}

LL solve(LL x){
	d1[0]=mul(dec(c1[0],mul(x,n)),quickmi(b1[0],mo-2));
	fo(i,1,n-1)d1[i]=c1[i];
	idft(d1);
	fo(i,0,n-1)d[i]=d1[i];
	return d1[0];
}

LL ans[10];

int main(){
	n=get();
	fo(i,0,n-1)b[i]=get();
	fo(i,0,n-1)c[i]=get();
	reverse(b+1,b+n);
	prepare();
	LL v0=solve(0),v1=solve(1);
	if (v0==v1)return printf("0\n"),0;
	LL k=(mo-mul(v0,quickmi(v1-v0,mo-2)))%mo;
	solve(k);
	if (d[0]!=0)return printf("0\n"),0;
	fo(i,0,n-1)if (d[i]>mo/2)d[i]=d[i]-mo;
	LL A=0,B=0,C=0;
	fo(i,0,n-1){
		int j=(n-i)%n;
		LL v=d[i]-b[j];
		A++;
		B=B+2ll*v;
		C=C+v*v;
	}
	C=C-c[0];
	if (B*B-4ll*A*C<0)return printf("0\n"),0;
	LL delt=sqrt(B*B-4ll*A*C);
	if (B*B-4ll*A*C!=delt*delt)return printf("0\n"),0;
	LL x0=(-B+delt)/A/2,x1=(-B-delt)/A/2;
	if (x0>x1)swap(x0,x1);
	if (x0*A*2==delt-B||x0*A*2==-B-delt)ans[++ans[0]]=x0;
	if (x0!=x1){
		if (x1*A*2==delt-B||x1*A*2==-B-delt)ans[++ans[0]]=x1;
	}
	printf("%I64d\n",ans[0]);
	fo(j,1,ans[0]){
		LL a0=ans[j];
		fo(i,0,n-1)printf("%I64d%c",d[i]+a0,i==n-1?'\n':' ');
	}
	return 0;
}
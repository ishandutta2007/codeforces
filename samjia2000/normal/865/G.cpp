#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

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

const int L = 8005;
const int mo = 1e9+7;

int n,m;
LL k;
int d[15];
int c[L];
int Mo[L],Mxr;
LL f0[L],sum[L],a[L],ans[L];
LL tmp[L*2];

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}

LL dec(LL x,LL y){return x>=y?x-y:x+mo-y;}

const int Blk = 32767;
const int MAXN = 34000;
const db pi = acos(-1);

struct comp{
	db x,y;
	comp(const db x_=0,const db y_=0){x=x_;y=y_;}
};
comp operator +(comp a,comp b){return comp(a.x+b.x,a.y+b.y);}
comp operator -(comp a,comp b){return comp(a.x-b.x,a.y-b.y);}
comp operator *(comp a,comp b){return comp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
comp conj(comp a){return comp(a.x,-a.y);}
int N,len;
int bitr[MAXN];
comp A[MAXN],B[MAXN],C[MAXN],D[MAXN];

void prepare(){
	fo(i,0,N-1){
		bitr[i]=0;
		fo(j,0,len-1)
		if ((i&(1<<j))>0)bitr[i]^=(1<<(len-1-j));
	}
}

void DFT(comp *a){
	fo(i,0,N-1)if (i<bitr[i])swap(a[i],a[bitr[i]]);
	for(int now=2;now<=N;now<<=1){
		comp w=comp(1,0),g=comp(cos(pi*2/now),sin(pi*2/now));
		int half=now/2;
		fo(i,0,half-1){
			for(int j=i;j<N;j+=now){
				comp l=a[j],r=a[j+half]*w;
				a[j+half]=l-r;
				a[j]=l+r;
			}
			w=w*g;
		}
	}
}

void IDFT(comp *a){
	fo(i,0,N-1)if (i<bitr[i])swap(a[i],a[bitr[i]]);
	for(int now=2;now<=N;now<<=1){
		comp w=comp(1,0),g=comp(cos(pi*2/now),-sin(pi*2/now));
		int half=now/2;
		fo(i,0,half-1){
			for(int j=i;j<N;j+=now){
				comp l=a[j],r=a[j+half]*w;
				a[j+half]=l-r;
				a[j]=l+r;
			}
			w=w*g;
		}
	}
	fo(i,0,N-1){
		a[i].x=a[i].x/N;
		a[i].y=a[i].y/N;
	}
}

void fft(LL *a,LL *b,LL *tmp){
	fo(i,0,N-1)A[i]=comp(a[i]>>15,a[i]&Blk),B[i]=comp(b[i]>>15,b[i]&Blk);
	DFT(A),DFT(B);
	fo(i,0,N-1){
		comp x=A[i],y=A[i==0?0:N-i];
		comp a1=(x+conj(y))*comp(0.5,0),a0=(x-conj(y))*comp(0,-0.5);
		x=B[i],y=B[i==0?0:N-i];
		comp b1=(x+conj(y))*comp(0.5,0),b0=(x-conj(y))*comp(0,-0.5);
		C[i]=a1*b1+a0*b0*comp(0,1);
		D[i]=a0*b1+a1*b0;
	}
	IDFT(C),IDFT(D);
	fo(i,0,N-1){
		LL c0=C[i].x+0.3,c1=C[i].y+0.3,d0=D[i].x+0.3;
		LL v=add(((((c0%mo)<<15)%mo)<<15)%mo,c1%mo);
		v=add(v,((d0%mo)<<15)%mo);
		tmp[i]=v;
	}
}

LL res[MAXN],dv[MAXN];
LL ny[MAXN],q0[MAXN];
LL s0[MAXN],s1[MAXN];

void getNy(int n){
	if (n==1){ny[0]=1;return;}
	int l;
	getNy(l=n/2+(n&1));
	N=1,len=0;
	while(N<=n+l+l)N<<=1,len++;
	prepare();
	fo(i,0,N-1)s0[i]=0;
	fo(i,0,n-1)s0[i]=q0[i];
	fft(ny,ny,tmp);
	fft(tmp,s0,tmp);
	fo(i,0,n-1)ny[i]=(ny[i]*2+mo-tmp[i])%mo;
}

void getny(){
	fo(i,0,Mxr)q0[i]=Mo[Mxr-i];
	getNy(Mxr);
}

void Mod(){
	int n=0,m=Mxr;
	fd(i,Mxr*2-2,0)if (tmp[i]){n=i;break;}
	if (n<m){fo(i,0,m-1)res[i]=tmp[i];return;}
	N=1,len=0;
	while(N<=(n-m)*2)N<<=1,len++;
	prepare();
	fo(i,0,N-1)s0[i]=s1[i]=0;
	fo(i,0,n-m)s0[i]=tmp[n-i],s1[i]=ny[i];
	fft(s0,s1,dv);
	fo(i,n-m+1,N)dv[i]=0;
	reverse(dv,dv+n-m+1);
	N=1,len=0;
	while(N<=n)N<<=1,len++;
	prepare();
	fo(i,0,N-1)s0[i]=s1[i]=0;
	fo(i,0,m)s0[i]=Mo[i];
	fo(i,0,n-m)s1[i]=dv[i];
	fft(s0,s1,dv);
	fo(i,0,m-1)res[i]=dec(tmp[i],dv[i]);
}

void multi(LL *a,LL *b,LL *c){
	N=1,len=0;
	while(N<=Mxr*2)N<<=1,len++;
	prepare();
	fft(a,b,tmp);
	Mod();
	fo(i,0,Mxr-1)c[i]=res[i];
}

int main(){
	n=get();m=get();
	scanf("%I64d",&k);
	fo(i,1,n)d[i]=get();
	fo(i,1,m){
		int x=get();
		c[x]++;
		Mxr=max(Mxr,x);
	}
	if (Mxr==1)Mxr++;
	Mo[Mxr]=1;
	fo(i,1,Mxr)Mo[Mxr-i]=c[i]?mo-c[i]:0;
	getny();
	f0[0]=1;
	fo(i,1,Mxr-1)
		fo(j,1,i)f0[i]=add(f0[i],f0[i-j]*c[j]%mo);
	fo(i,0,Mxr-1)sum[i]=0;
	fo(now,1,n){
		int tim=d[now];
		fo(i,0,Mxr-1)a[i]=ans[i]=0;
		a[1]=1;
		ans[0]=1;
		for(;tim;tim/=2){
			if (tim&1)multi(ans,a,ans);
			multi(a,a,a);
		}
		fo(i,0,Mxr-1)sum[i]=add(sum[i],ans[i]);
	}
	LL tim=k;
	fo(i,0,Mxr-1)a[i]=sum[i],ans[i]=0;
	ans[0]=1;
	for(;tim;tim/=2){
		if (tim&1)multi(ans,a,ans);
		multi(a,a,a);
	}
	LL v=0;
	fo(i,0,Mxr-1)v=add(v,ans[i]*f0[i]%mo);
	printf("%I64d\n",v);
	return 0;
}
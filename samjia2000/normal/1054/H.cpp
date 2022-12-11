#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef long double db;

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

const int MAXN = (1<<20)+5;
const int mo = 490019;

int id[MAXN],g0;
int n,m,c;
int a[MAXN],b[MAXN];

LL quickmi(LL x,LL tim,LL Mod=mo){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%Mod)
	if (tim&1)ret=ret*x%Mod;
	return ret;
}

const db pi=acos(-1);

int N;
struct comp{
	db x,y;
	comp(const db x_=0,const db y_=0){x=x_;y=y_;}
}A[MAXN],B[MAXN],C[MAXN],D[MAXN],Rt[MAXN];
int rev[MAXN];
comp operator *(comp a,comp b){return comp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
comp operator +(comp a,comp b){return comp(a.x+b.x,a.y+b.y);}
comp operator -(comp a,comp b){return comp(a.x-b.x,a.y-b.y);}
comp conj(comp a){return comp(a.x,-a.y);}

void getRt(){
	int w=0;
	for(int i=1,d=1;i<N;i<<=1,d++){
		for(int k=0;k<i;k++){
			Rt[++w]=comp(cos(pi/i*k),sin(pi/i*k));
		}
	}
	for(int i=0,j=0;i<N;i++){
		rev[i]=j;
		int x=N>>1;
		for(;(j^x)<j;x>>=1)j^=x;
		j^=x;
	}
}

void DFT(comp *a){
	for(int i=0;i<N;i++)
	if (i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1,d=1,st=1;i<N;i<<=1,d++){
		for(int j=0;j<N;j+=(i<<1))
			for(int k=0;k<i;k++){
				comp l=a[j+k],r=a[i+j+k]*Rt[st+k];
				a[i+j+k]=l-r;
				a[j+k]=l+r;
			}
		st+=i;
	}
}

void IDFT(comp *a){
	DFT(a);
	reverse(a+1,a+N);
	fo(i,0,N-1)a[i].x=a[i].x/N,a[i].y/=N;
}

LL inv[MAXN],mi[MAXN];

int main(){
	n=get();m=get();c=get();
	fo(i,0,n-1){
		int id=1ll*i*i%(mo-1);
		a[id]=(a[id]+get())%mo;
	}
	fo(i,0,m-1){
		int id=1ll*i*i%(mo-1)*i%(mo-1);
		b[id]=(b[id]+get())%mo;
	}
	mi[0]=1;
	fo(i,1,mo-1)mi[i]=mi[i-1]*c%mo;
	inv[0]=1;
	inv[1]=quickmi(c,mo-2);
	fo(i,2,mo-2)inv[i]=inv[i-1]*inv[1]%mo;
	N=(1<<20);
	getRt();
	//00+11
	fo(i,0,mo-1)
	if (i&1){
		LL v=inv[1ll*i*i/2%(mo-1)]*a[i]%mo;
		A[i]=comp(v>>10,v&1023);
		v=inv[(1ll*i*i/2+1)%(mo-1)]*b[i]%mo;
		B[i]=comp(v>>10,v&1023);
	}
	else{
		LL v=inv[1ll*i*i/2%(mo-1)]*a[i]%mo;
		A[i]=comp(v>>10,v&1023);
		v=inv[1ll*i*i/2%(mo-1)]*b[i]%mo;
		B[i]=comp(v>>10,v&1023);
	}
	DFT(A),DFT(B);
	fo(i,0,N-1){
		comp x=A[i],y=A[i==0?0:N-i];
		comp a0=(x+conj(y))*comp(0.5,0),a1=(x-conj(y))*comp(0,-0.5);
		x=B[i],y=B[i==0?0:N-i];
		comp b0=(x+conj(y))*comp(0.5,0),b1=(x-conj(y))*comp(0,-0.5);
		C[i]=a0*b0+a0*b1*comp(0,1);
		D[i]=a1*b0+a1*b1*comp(0,1);
	}
	IDFT(C),IDFT(D);
	LL ans=0;
	LL p=(1<<20)%mo;
	fo(i,0,N-1)
	if (i%2==0){
		LL v0=C[i].x+0.3,v1=C[i].y+0.3,v2=D[i].x+0.3,v3=D[i].y+0.3;
		v0%=mo,v1%=mo,v2%=mo,v3%=mo;
		LL v=(v0*p+(v1<<10)+(v2<<10)+v3)%mo;
		v=v*mi[1ll*i*i/2%(mo-1)]%mo;
		ans=(ans+v)%mo;
	}
	//01+10
	fo(i,0,N-1)A[i]=B[i]=comp(0,0);
	fo(i,0,mo-1){
		LL v=inv[1ll*i*i/2%(mo-1)]*a[i]%mo;
		A[i]=comp(v>>10,v&1023);
		v=inv[1ll*i*i/2%(mo-1)]*b[i]%mo;
		B[i]=comp(v>>10,v&1023);
	}
	DFT(A),DFT(B);
	fo(i,0,N-1){
		comp x=A[i],y=A[i==0?0:N-i];
		comp a0=(x+conj(y))*comp(0.5,0),a1=(x-conj(y))*comp(0,-0.5);
		x=B[i],y=B[i==0?0:N-i];
		comp b0=(x+conj(y))*comp(0.5,0),b1=(x-conj(y))*comp(0,-0.5);
		C[i]=a0*b0+a0*b1*comp(0,1);
		D[i]=a1*b0+a1*b1*comp(0,1);
	}
	IDFT(C),IDFT(D);
	fo(i,0,N-1)
	if (i&1){
		LL v0=C[i].x+0.3,v1=C[i].y+0.3,v2=D[i].x+0.3,v3=D[i].y+0.3;
		v0%=mo,v1%=mo,v2%=mo,v3%=mo;
		LL v=(v0*p+(v1<<10)+(v2<<10)+v3)%mo;
		v=v*mi[1ll*i*i/2%(mo-1)]%mo;
		ans=(ans+v)%mo;
	}
	cout<<ans<<endl;
	return 0;
}
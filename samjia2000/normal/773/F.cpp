#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

const int MAXN = (1<<16)+5;
const int maxn = 1<<16;
const db pi = acos(-1);

int Maxn,Maxa,mo;

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}
LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}

struct comp{
	db x,y;
	comp(const db x_=0,const db y_=0){x=x_;y=y_;}
}A[MAXN],B[MAXN],mi[MAXN];
comp operator *(comp a,comp b){return comp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
comp operator +(comp a,comp b){return comp(a.x+b.x,a.y+b.y);}
comp operator -(comp a,comp b){return comp(a.x-b.x,a.y-b.y);}
comp conj(comp a){return comp(a.x,-a.y);}
int N;

void prepare(){
	fo(i,0,maxn)mi[i]=comp(cos(pi*2/maxn*i),sin(pi*2/maxn*i));
}

void DFT(comp *a){
	for(int i=0,j=0;i<N;i++){
		if (i<j)swap(a[i],a[j]);
		int x=N>>1;
		for(;(j^x)<j;x>>=1)j^=x;
		j^=x;
	}
	for(int i=1,d=1;i<N;i<<=1,d++)
		for(int j=0;j<N;j+=(i<<1))
			for(int k=0;k<i;k++){
				comp l=a[j+k],r=a[i+j+k]*mi[(maxn>>d)*k];
				a[i+j+k]=l-r;
				a[j+k]=l+r;
			}
}

void IDFT(comp *a){
	DFT(a);
	reverse(a+1,a+N);
	fo(i,0,N-1)a[i]=comp(a[i].x/N,a[i].y/N);
}

LL f0[MAXN],f1[MAXN],g0[MAXN],g1[MAXN];

int main(){
	prepare();
	Maxn=get();Maxa=get();mo=get();
	int w=1;
	for(;w*2<=Maxa;w<<=1);
	f0[0]=1;
	f1[1]=1;
	N=1;
	while(N<=Maxn*2)N<<=1;
	LL ans=(Maxa>1);
	for(w>>=1;w;w>>=1){
		fo(i,0,Maxn)g0[i]=f0[i],g1[i]=f1[i];
		fo(i,0,N-1)A[i]=B[i]=comp(0,0);
		fo(i,0,Maxn)A[i]=comp((f0[i]+f1[i])%mo,0);
		fo(i,1,Maxn)B[i]=comp(f0[i],0);
		DFT(A),DFT(B);
		fo(i,0,N-1)B[i]=A[i]*B[i];
		IDFT(B);
		int p=((Maxa&(w<<1))>0);
		if (p)fo(i,0,Maxn){LL tmp=B[i].x+0.3;tmp=tmp%mo;g1[i]=add(g1[i],tmp);}
		else fo(i,0,Maxn){LL tmp=B[i].x+0.3;tmp=tmp%mo;g0[i]=add(g0[i],tmp);}
		fo(i,0,N-1)B[i]=0;
		fo(i,1,Maxn)B[i]=comp(f1[i],0);
		DFT(B);
		fo(i,0,N-1)B[i]=A[i]*B[i];
		IDFT(B);
		p^=1;
		if (p)fo(i,0,Maxn){LL tmp=B[i].x+0.3;tmp=tmp%mo;g1[i]=add(g1[i],tmp);}
		else fo(i,0,Maxn){LL tmp=B[i].x+0.3;tmp=tmp%mo;g0[i]=add(g0[i],tmp);}
		fo(i,0,Maxn)f0[i]=g0[i],f1[i]=g1[i];
		if ((Maxa&w)>0){
			fd(i,Maxn-1,0)f1[i+1]=add(f1[i+1],add(f0[i],f1[i]));
		}
		if (w!=1)
		fo(i,0,Maxn)
		if (i&1)ans=add(ans,f1[i]);
	}
	cout<<ans<<endl;
	return 0;
}
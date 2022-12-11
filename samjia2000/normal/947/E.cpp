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

const int MAXN = 262144;
const int mo = 998244353;
const int g =  3;

LL quickmi(LL x,LL tim){LL ret=1;for(;tim;tim/=2,x=x*x%mo)if (tim&1)ret=ret*x%mo;return ret;}

int N,L;
LL A[MAXN+5],B[MAXN+5],ny;
LL mi[MAXN+5];
int n;
LL P[MAXN+5];
LL m;
LL lamda[MAXN+5];
LL js[MAXN+5],inv[MAXN+5];

void prepare(){
	mi[0]=1;
	mi[1]=quickmi(g,(mo-1)/MAXN);
	fo(i,2,MAXN)mi[i]=mi[i-1]*mi[1]%mo;
	js[0]=js[1]=inv[1]=inv[0]=1;
	fo(i,2,n+1)js[i]=js[i-1]*i%mo;
	fo(i,2,n+1)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,0,n)lamda[i]=quickmi(inv[i+1],m);
	fo(i,2,n+1)inv[i]=inv[i-1]*inv[i]%mo;
}

void DFT(LL *a){
	for(int i=0,rev=0;i<N;i++){
		if (i<rev)swap(a[i],a[rev]);
		int j=N>>1;
		for(;(j^rev)<rev;j>>=1)rev=rev^j;
		rev=rev^j;
	}
	for(int i=1,d=1;i<N;i=i<<1,d++)
		for(int j=0;j<N;j=j+(i<<1))
			for(int k=0;k<i;k++){
				LL l=a[j+k],r=a[i+j+k]*mi[(MAXN>>d)*k]%mo;
				a[i+j+k]=l<r?l-r+mo:l-r;
				a[j+k]=l+r>=mo?l+r-mo:l+r;
			}
}

void IDFT(LL *a){
	DFT(a);
	reverse(a+1,a+N);
	fo(i,0,N-1)a[i]=a[i]*ny%mo;
}

int main(){
	n=get();scanf("%I64d",&m);
	fo(i,0,n)P[i]=get();
	prepare();
	
	N=1,L=0;
	while(N<=n*2)N<<=1,L++;
	ny=quickmi(N,mo-2);
	fo(i,0,N-1)A[i]=B[i]=0;
	
	//v^(-1)
	fo(i,0,n)A[n-i]=P[i]*js[i]%mo,B[i]=inv[i];
	DFT(A),DFT(B);
	fo(i,0,N-1)A[i]=A[i]*B[i]%mo;
	IDFT(A);
	fo(i,0,n)P[i]=A[n-i]*inv[i]%mo;
	
	//lamda
	fo(i,0,n)P[i]=P[i]*lamda[i]%mo;
	
	//v
	fo(i,0,N-1)A[i]=B[i]=0;
	fo(i,0,n)A[n-i]=P[i]*js[i]%mo,B[i]=(i&1?mo-inv[i]:inv[i]);
	DFT(A),DFT(B);
	fo(i,0,N-1)A[i]=A[i]*B[i]%mo;
	IDFT(A);
	fo(i,0,n)P[i]=A[n-i]*inv[i]%mo;
	
	fo(i,0,n)printf("%I64d%c",P[i],i==n?'\n':' ');
	return 0;
}
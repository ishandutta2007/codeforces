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

const int mo = 998244353;
const int MAXN = 262200;
const int maxn = 262144;
const int g0 = 3;

int N,L;
LL Mi[MAXN];
LL ny;
LL A[MAXN],B[MAXN];
int n,a,b;
LL js[MAXN],inv[MAXN],Ny[MAXN];

LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}

void DFT(LL *a,int sig){
    for(int i=0,j=0;i<N;i++)
    {
        if(i>j)swap(a[i],a[j]);
        for(int l=N>>1;(j^=l)<l;l>>=1);
    }
	for(int k=1,d=1;k<N;d++,k<<=1){
        for(int j=0;j<N;j=j+(k<<1)){
            for(int i=0;i<k;i++){
                LL r=(LL)Mi[(maxn>>d)*i]*a[j+i+k]%mo;
                a[j+i+k]=a[j+i]<r?a[j+i]-r+mo:a[j+i]-r;
                a[j+i]=a[j+i]+r<mo?a[j+i]+r:a[j+i]+r-mo;
            }
        }
    }
    if(sig==-1)
    {
        reverse(a+1,a+N);
        for(int i=0;i<N;i++)a[i]=(LL)a[i]*ny%mo;
    }
}

LL val[MAXN];

void solve(int l,int r){
	if (l==r){val[l]=Ny[l];return;}
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	N=1,L=0;
	while(N<=r-l+1)N<<=1,L++;
	ny=quickmi(N,mo-2);
	fo(i,0,N-1)A[i]=B[i]=0;
	A[0]=B[0]=1;
	fo(i,1,mid-l+1)A[i]=val[l+i-1];
	fo(i,1,r-mid)B[i]=val[mid+i];
	DFT(A,1);DFT(B,1);
	fo(i,0,N-1)A[i]=A[i]*B[i]%mo;
	DFT(A,-1);
	fo(i,1,r-l+1)val[l+i-1]=A[i];
}

LL calc(int n,int l){
	if (!l)return 0;
	if (l>n)return 0;
	if (l==n)return 1;
	if (n>1)solve(1,n-1);
	val[0]=1;
	l--;
	return js[n-1]*val[l]%mo;
}

int main(){
	n=get();a=get();b=get();
	if (a==0||b==0||a+b-1>n)return printf("0\n"),0;
	if (n==1){
		if (a==1&&b==1)printf("1\n");else printf("0\n");
		return 0;
	}
	js[0]=js[1]=1;
	fo(i,2,n)js[i]=js[i-1]*i%mo;
	Ny[0]=Ny[1]=1;
	fo(i,2,n)Ny[i]=1ll*(mo-mo/i)*Ny[mo%i]%mo;
	inv[0]=1;
	fo(i,1,n)inv[i]=inv[i-1]*Ny[i]%mo;
	Mi[0]=1;
	Mi[1]=quickmi(g0,(mo-1)/maxn);
	fo(i,2,maxn)Mi[i]=Mi[i-1]*Mi[1]%mo;
	LL ans=calc(n-1,a+b-2)%mo;
	ans=ans*js[a+b-2]%mo*inv[a-1]%mo*inv[b-1]%mo;
	cout<<ans<<endl;
	return 0;
}
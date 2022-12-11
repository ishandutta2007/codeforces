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

const int maxn = 1049000;
const int maxl = 21;
const db pi = acos(-1);

int bitr[maxn];
int N,L;
struct comp{
	db x,y;
	comp(const db x_=0,const db y_=0){x=x_;y=y_;}
}A[maxn],B[maxn],c0;
comp operator *(comp a,comp b){return comp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
comp operator +(comp a,comp b){return comp(a.x+b.x,a.y+b.y);}
comp operator -(comp a,comp b){return comp(a.x-b.x,a.y-b.y);}
comp operator /(comp a,db v){return comp(a.x/v,a.y/v);}
int n;
char s[maxn];
int a[maxn],b[maxn];
db si[maxn],cs[maxn];
bool bz[maxn];
int lst[maxn],pri[maxn],k;

void prepare(){
	fo(i,0,N-1){
		bitr[i]=0;
		fo(j,0,L-1)
		if ((i&(1<<j))>0)bitr[i]+=1<<(L-1-j);
	}
	fo(i,0,N-1){
		si[i]=sin(pi*2/N*i);
		cs[i]=cos(pi*2/N*i);
	}
}

void pp(){
	fo(i,2,5e+5){
		if (!lst[i])pri[++k]=lst[i]=i;
		fo(j,1,k){
			if (i*pri[j]>5e+5)break;
			lst[i*pri[j]]=pri[j];
			if (i%pri[j]==0)break;
		}
	}
}

void dft(comp *a,int sig){
	fo(i,0,N-1)
	if (i<bitr[i])swap(a[i],a[bitr[i]]);
	for(int now=2;now<=N;now<<=1){
		int half=now/2;
		fo(i,0,half-1){
			comp w=comp(cs[N/now*i],si[N/now*i]*sig);
			for(int j=i;j<N;j+=now){
				comp l=a[j],r=w*a[j+half];
				a[j]=l+r;
				a[j+half]=l-r;
			}
		}
	}
	if (sig==-1)
	fo(i,0,N-1)a[i]=a[i]/N;
}

int main(){
	pp();
	for(int T=get();T;T--){
		n=get();
		fo(i,1,n){
			char ch;
			while(ch=getchar(),ch!='V'&&ch!='K'&&ch!='?');
			s[i]=ch;
		}
		N=1,L=0;
		while(N<=2*n)N<<=1,L++;
		prepare();
		fo(i,1,n)a[i]=b[i]=0;
		fo(i,1,n){
			if (s[i]=='V')a[i]=1;
			if (s[i]=='K')b[n-i+1]=1;
		}
		c0=comp(0,0);
		fo(i,0,N-1)A[i]=B[i]=c0;
		fo(i,1,n)A[i]=comp(a[i],0);
		fo(i,1,n)B[i]=comp(b[i],0);
		dft(A,1);
		dft(B,1);
		fo(i,0,N-1)A[i]=A[i]*B[i];
		dft(A,-1);
		fo(i,1,n)bz[i]=0;
		fo(i,0,N-1)
		if (fabs(A[i].x)>1e-5)bz[abs(i-n-1)]=1;
		int ans=0;
		fd(i,n,1)
		if (!bz[i])ans++;
		else{
			int x=i;
			while(lst[x]){
				bz[i/lst[x]]=1;
				x/=lst[x];
			}
		}
		printf("%d\n",ans);
		fo(i,1,n)
		if (!bz[i])printf("%d ",i);
		putchar('\n');
	}
	return 0;
}
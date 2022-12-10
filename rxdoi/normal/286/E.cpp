#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e6*4+19;
int rev[N],vis[N],b[N],n,m,c,x,Ans;

typedef double Db;
const Db Pi=acos(-1.0);
struct Comp
{
	Db re,im;
	Comp() {}
	Comp(Db r,Db i) {re=r,im=i;}
} W[2][N],A[N];

Comp operator + (Comp A,Comp B) {return Comp(A.re+B.re,A.im+B.im);}
Comp operator - (Comp A,Comp B) {return Comp(A.re-B.re,A.im-B.im);}
Comp operator * (Comp A,Comp B) {return Comp(A.re*B.re-A.im*B.im,A.re*B.im+A.im*B.re);}

void FFT(Comp *A,int f)
{
	Comp x,y;
	For(i,0,n) if (i<rev[i]) swap(A[i],A[rev[i]]);
	for (int i=1;i<n;i<<=1)
		for (int j=0,t=n/(i<<1);j<n;j+=i<<1)
			for (int k=0,l=0;k<i;k++,l+=t)
				x=A[j+k],y=A[j+k+i]*W[f][l],A[j+k]=x+y,A[j+k+i]=x-y;
	if (f) For(i,0,n) A[i].re/=n;
}

int main()
{
	n=IN(),m=IN();
	For(i,1,n+1) x=IN(),vis[x]=1,A[x].re=1;
	for (c=1;c<m;c<<=1);n=c<<1;
	For(i,0,n)
	{
		W[0][i]=W[1][i]=Comp(cos(2*Pi*i/n),sin(2*Pi*i/n));
		W[1][i].im*=-1;
		for (int x=i,&y=rev[i],k=1;k<n;k<<=1,x>>=1) y=y<<1|x&1;
	}
	FFT(A,0);
	For(i,0,n) A[i]=A[i]*A[i];
	FFT(A,1);
	For(i,0,n) b[i]=fabs(A[i].re+0.5);
	For(i,1,m+1) if (b[i]&&!vis[i]) return puts("NO"),0;
	puts("YES");
	For(i,1,m+1) if (vis[i]&&!b[i]) Ans++;
	printf("%d\n",Ans);
	For(i,1,m+1) if (vis[i]&&!b[i]) printf("%d ",i);puts("");
}
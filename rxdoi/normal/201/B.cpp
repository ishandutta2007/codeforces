#include<cstdio>
using namespace std;

const int Maxn=1000+19;
typedef long long LL;
int n,m;
LL x,H[Maxn],L[Maxn],Ax,Ay,Ix,Iy,Mx=1LL<<60,My=1LL<<60;

inline LL Sqr(LL x) {return x*x;}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%I64d",&x),H[i]+=x,L[j]+=x;
	for (Ax=0;Ax<=n;Ax++)
	{
		LL tmp=0;
		for (LL x=1;x<=n;x++) tmp+=Sqr((4LL*Ax)-(4LL*x-2))*H[x];
		if (tmp<Mx) {Mx=tmp;Ix=Ax;}
	}
	for (Ay=0;Ay<=m;Ay++)
	{
		LL tmp=0;
		for (LL y=1;y<=m;y++) tmp+=Sqr((4LL*Ay)-(4LL*y-2))*L[y];
		if (tmp<My) {My=tmp;Iy=Ay;}
	}
	printf("%I64d\n",Mx+My);
	printf("%I64d %I64d\n",Ix,Iy);
}
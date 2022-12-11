#include<stdio.h>
#include<cctype>
using namespace std;

const int Maxn=100000+19;
typedef long long LL;
LL H[Maxn],P[Maxn],L,R;
int n,m,c;

LL Abs(LL a) {return a>0?a:-a;}
LL max(LL a,LL b) {return a>b?a:b;}
void Read(LL &x)
{
	while (!isdigit(c=getchar()));
	x=c-'0';
	while (isdigit(c=getchar())) x=x*10+c-'0';
}
int check(LL t)
{
	int now=0;LL Final;
	for (int i=0;i<n;i++)
	{
		LL tmp=Abs(H[i]-P[now]);
		if (tmp>t) continue;
		if (P[now]<H[i]) Final=max(H[i]+t-2*tmp,H[i]+(t-tmp)/2);
			else Final=H[i]+t;
		while (now<m&&P[now]<=Final) now++;
	}
	return now>=m;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) Read(H[i]);
	for (int i=0;i<m;i++) Read(P[i]);
	for (L=0,R=Abs(H[0]-P[0])*2+Abs(H[0]-P[m-1]);L<R;)
	{
		LL Mid=(L+R)>>1;
		if (check(Mid)) R=Mid;else L=Mid+1;
	}
	printf("%I64d\n",R);
	return 0;
}
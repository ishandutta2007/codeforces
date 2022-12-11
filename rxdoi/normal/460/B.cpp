#include<cstdio>
using namespace std;

const int Maxn=100+19;
typedef long long LL;
int a,b,c,sx,tot;
int A[Maxn];

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for (sx=0;sx<=100;sx++)
	{
		LL tmp=1,tmp2=0,ttmp;
		for (int i=1;i<=a;i++) tmp=1LL*tmp*sx;
		tmp=1LL*tmp*b+c;
		if (tmp<=0||tmp>=1e9) continue;
		ttmp=tmp;
		while (tmp) tmp2+=tmp%10,tmp/=10;
		if (sx==tmp2) A[tot++]=ttmp;
	}
	printf("%d\n",tot);
	for (int i=0;i<tot;i++) printf("%d ",A[i]);
}
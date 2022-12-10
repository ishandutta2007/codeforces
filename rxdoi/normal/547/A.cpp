#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int M=2e6+19;
int v[M],Mod,S,T,a,b,p1,q1,p2,q2,phi,x;
long long tmp;

void Calc(int &p,int &q)
{
	memset(v,-1,sizeof(v)),v[S]=0;
	for (int i=1;;i++)
	{
		S=(1LL*a*S+b)%Mod;
		if (~v[S])
		{
			if (v[T]==-1) p=q=-1;else p=v[T],q=v[T]<v[S]?-1:i-v[S];
			return;
		}
		v[S]=i;
	}
}

int main()
{
	scanf("%d",&Mod);
	scanf("%d%d%d%d",&S,&T,&a,&b),Calc(p1,q1);
	scanf("%d%d%d%d",&S,&T,&a,&b),Calc(p2,q2);

	if (p1==-1||p2==-1) return puts("-1"),0;
	if (q1==-1&&q2==-1) return printf("%d\n",p1==p2?p1:-1),0;
	if (q1==-1) swap(q1,q2),swap(p1,p2);
	if (q2==-1) return printf("%d\n",p2-p1>=0&&(p2-p1)%q1==0?p2:-1),0;

	For(k1,0,Mod)
		if ((tmp=p1+1LL*k1*q1-p2)>=0&&tmp%q2==0) return printf("%I64d\n",tmp+p2),0;
	puts("-1");
}
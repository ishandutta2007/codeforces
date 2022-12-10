#include<cmath>
#include<ctime>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

typedef long long LL;
typedef double Db;

const int K=50;
LL p[K],V,As,Aa,Ac;
int q[K],k;

LL IN()
{
	int c,f;LL x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

void DFS_C(LL a,int x,LL c)
{
	if (c>1e9||c*c>=V)
	{
		LL S=V+a*(V/c+c);
		if (As==-1||S<As) As=S,Aa=a,Ac=c;
		return;
	}
	if (x==k) return;
	if (q[x]) q[x]--,DFS_C(a,x,c*p[x]),q[x]++;
	DFS_C(a,x+1,c);
}
void DFS_A(int x,LL a)
{
	if (a>1e6||a*a*a>V) return;
	if (x==k)
	{
		if (As!=-1&&V/a+a*2*sqrt(V/a)>=As) return;
		V/=a,DFS_C(a,0,1),V*=a;
		return;
	}
	if (q[x]) q[x]--,DFS_A(x,a*p[x]),q[x]++;
	DFS_A(x+1,a);
}

int main()
{
	for (int T=IN();T--;)
	{
		V=1;As=-1;
		k=IN();
		For(i,0,k)
		{
			p[i]=IN(),q[i]=IN();
			For(j,0,q[i]) V*=p[i];
		}
		DFS_A(0,1);
		printf("%I64d %I64d %I64d %I64d\n",2*As,Aa,V/Aa/Ac,Ac);
	}
}
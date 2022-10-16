#include <cstdio>
#include <map>
using namespace std;
int n,q;
int i,u,e;
char op[10];
map <int,int> p;
double max(double a,double b)
{
	if (a>b)
		return a;
	return b;
}
double get(int u,double mx)
{
	if (mx>=p[u])
		return mx;
	return (get(u<<1,max(p[u]-p[u<<1],mx))
		+get(u<<1^1,max(p[u]-p[u<<1^1],mx)))/2;
}
int main()
{
	scanf("%d%d",&n,&q);
	for (i=1;i<=q;i++)
	{
		scanf("%s",op+1);
		if (op[1]=='a')
		{
			scanf("%d%d",&u,&e);
			while (u)
			{
				p[u]+=e;
				u>>=1;
			}
		}
		else
			printf("%.10lf\n",get(1,0));
	}
	return 0;
}
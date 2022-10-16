#include <cstdio>
using namespace std;
int n,i,pos[200005],move[200005],lastr,ans;
char op;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		op=0;
		while (op!='R'&&op!='L')
			scanf("%c",&op);
		move[i]=op=='R'?1:-1;
	}
	for (i=1;i<=n;i++)
		scanf("%d",&pos[i]);
	lastr=-1;
	ans=-1;
	for (i=1;i<=n;i++)
	{
		if (move[i]==1)
		{
			lastr=i;
			continue;
		}
		if (lastr>=0&&(((pos[i]-pos[lastr])>>1)<ans||ans==-1))
			ans=(pos[i]-pos[lastr])>>1;
	}
	printf("%d\n",ans);
	return 0;
}
#include <cstdio>
using namespace std;
const int N=15;
int T;
char s[N];
int av,ov;
int ans;
void solve()
{
	scanf("%s",s+1);
	av=ov=0;
	for (int i=1;i<=10;i++)
	{
		if (s[i]=='1')
		{
			av|=(1<<i-1);
			ov|=(1<<i-1);
		}
		if (s[i]=='?')
			ov|=(1<<i-1);
	}
	ans=10;
	for (int i=0;i<(1<<10);i++)
		if ((i&av)==av&&(i|ov)==ov)
		{
			int p1=0,p2=0;
			for (int j=0;j<10;j++)
			{
				if (j&1^1)
				{
					p1+=((i&(1<<j))>0);
					if (p1+(10-j)/2-1<p2)
					{
						if (j+1<ans)
							ans=j+1;
						break;
					}
					if (p2+(10-j)/2<p1)
					{
						if (j+1<ans)
							ans=j+1;
						break;
					}
				}
				if (j&1)
				{
					p2+=((i&(1<<j))>0);
					if (p1+(10-j)/2<p2)
					{
						if (j+1<ans)
							ans=j+1;
						break;
					}
					if (p2+(10-j)/2<p1)
					{
						if (j+1<ans)
							ans=j+1;
						break;
					}
				}
			}
		}
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}
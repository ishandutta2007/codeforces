#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;

const int Maxn=100+19;
int c[Maxn],a,b,n,s,x,cnt;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s);
		for (int j=1;j<=s;j++)
		{
			scanf("%d",&x);
			if (s%2==1&&j==s/2+1) c[cnt++]=x;
				else if (j<s/2+1) a+=x;else b+=x;
		}
	}
	sort(c,c+cnt,greater<int>());
	for (int i=0;i<cnt;i++) (i&1?b+=c[i]:a+=c[i]);
	printf("%d %d\n",a,b);
}
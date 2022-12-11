#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=200+19;
int n,now,Fi,Ans,y;
int Have[4][Maxn],com[Maxn],Be[Maxn],inD[Maxn],_inD[Maxn],outD[Maxn],Pre[Maxn][Maxn],To[Maxn][Maxn];

inline int Search(int st)
{
	memcpy(inD,_inD,sizeof(_inD));
	memset(com,0,sizeof(com));
	Fi=0;now=st;Ans=0;
	while (Fi<n)
	{
		int Flag=0;
		for (int i=1;i<=Have[now][0];i++)
		{
			int x=Have[now][i];
			if (com[x]||inD[x]||Be[x]^now) continue;
			Ans++;com[x]=1;Flag=1;Fi++;
			for (int j=0;j<outD[x];j++)
				if (!com[To[x][j]]) inD[To[x][j]]--; 
			break;
		}
		if (!Flag) Ans++,now=now%3+1;
	}
	return Ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&Be[i]),Have[Be[i]][++Have[Be[i]][0]]=i;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&inD[i]);_inD[i]=inD[i];
		for (int j=0;j<inD[i];j++) scanf("%d",&y),To[y][outD[y]++]=i;
	}
	printf("%d\n",min(Search(1),min(Search(2),Search(3))));
}
#include<stdio.h>
#include<cstring>
#include<vector>
#define pb push_back
#define pop pop_back
#define MAXN 110000
using namespace std;
vector<int> p[MAXN];
bool pr[MAXN];int n,q;
int now[MAXN];
bool on[MAXN];
void init()
{
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	if(!pr[i])for(int j=i;j<=n;j+=i)pr[j]=1,p[j].pb(i);
}
int main()
{
	init();
	while(q--)
	{
		char str[3];int x;
		scanf("%s",str+1);scanf("%d",&x);
		if(str[1]=='+')
		{
			if(on[x])printf("Already on\n");
			else
			{
				int ans=0;
				for(int i=0;i<p[x].size();i++)
				{
					if(now[p[x][i]])
					{
						ans=now[p[x][i]];
						break;
					}
				}
				if(ans)printf("Conflict with %d\n",ans);
				else 
				{
					for(int i=0;i<p[x].size();i++)now[p[x][i]]=x;
					on[x]=1;
					printf("Success\n");
				}
			}
		}
		else
		{
			if(!on[x])printf("Already off\n");
			else
			{
				for(int i=0;i<p[x].size();i++)now[p[x][i]]=0;
				printf("Success\n");
				on[x]=0;
				}
			}
		}
	return 0;
}
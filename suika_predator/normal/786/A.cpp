#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
int n,k[2];
int state[23333][2],deg[23333][2];
int trans[23333][2];
string ans[23]={"Lose","Loop","Win"};
queue<pair<int,int> > q;
int main()
{
	scanf("%d",&n);
	scanf("%d",&k[0]);
	for(int i=1;i<=k[0];i++)scanf("%d",&trans[i][0]);
	scanf("%d",&k[1]);
	for(int i=1;i<=k[1];i++)scanf("%d",&trans[i][1]);
	for(int i=1;i<n;i++)state[i][0]=state[i][1]=1,deg[i][0]=k[0],deg[i][1]=k[1];
	state[0][0]=state[0][1]=0;
	q.push(make_pair(0,0));
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		auto _=q.front();q.pop();
		int pos=_.first,ty=_.second;
		for(int i=1;i<=k[!ty];i++)
		{
			int nxt=(n+pos-trans[i][!ty])%n;
			if(state[nxt][!ty]==1)
			{
//				cout<<nxt<<','<<!ty<<"->"<<pos<<','<<ty<<endl;
				state[nxt][!ty]=2;
				for(int j=1;j<=k[ty];j++)
				{
					int nxxt=(n+nxt-trans[j][ty])%n;
//					cout<<nxxt<<','<<ty<<"->"<<nxt<<','<<!ty<<"--deg="<<deg[nxxt][ty]<<endl;
					deg[nxxt][ty]--;
					if(deg[nxxt][ty]==0)
					{
						state[nxxt][ty]=0;
						q.push(make_pair(nxxt,ty));
					}
				}
			}
		}
	}
	for(int i=1;i<n;i++)
		printf("%s ",ans[state[i][0]].c_str());
	printf("\n");
	for(int i=1;i<n;i++)
		printf("%s ",ans[state[i][1]].c_str());
	printf("\n");
	return 0;
}
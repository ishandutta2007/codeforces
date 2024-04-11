#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define N 111
vector<int> a[N];int n,m,d[N];bool v[N];
void ff(int x)
{
	v[x]=1;
	for(int i=0;i<(int)a[x].size();i++)
		if(!v[a[x][i]])ff(a[x][i]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++)
		scanf("%d%d",&x,&y),--x,--y,
		a[x].push_back(y),
		a[y].push_back(x),
		d[x]++,d[y]++;
	ff(0);
	for(int i=1;i<n;i++)
		if(!v[i]){puts("NO");return 0;}
	memset(v,0,sizeof v);
	queue<int> Q;
	for(int i=0;i<n;i++)if(d[i]==1)Q.push(i),v[i]=1;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();d[x]=0;
		for(int i=0;i<(int)a[x].size();i++)
			if(!v[a[x][i]])
			{
				d[a[x][i]]--;
				if(d[a[x][i]]==1&&!v[a[x][i]])Q.push(a[x][i]),v[a[x][i]]=1;
			}
	}
	for(int i=0;i<n;i++)
		if(d[i]!=0&&d[i]!=2){puts("NO");return 0;}
	bool F=1;
	for(int i=0;i<n;i++)if(d[i]==2){F=0;break;}
	if(!F)puts("FHTAGN!");else puts("NO");
	return 0;
}
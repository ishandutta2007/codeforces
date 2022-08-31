#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MXN 100005

int vote[MXN], did[MXN], didnt[MXN], crime[MXN];

int main()
{
	//freopen("in1.in","r",stdin);
	int tdid = 0, tdidnt = 0;
	int n, m, crimes = 0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&vote[i]);
		if(vote[i]>0) tdid++, did[vote[i]]++; 
		else tdidnt++, didnt[-vote[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		int truth = did[i] + tdidnt - didnt[i];
		//printf("truth = %d, m = %d, did = %d, didnt = %d\n",truth,m,did[i],didnt[i]);
		if(truth==m) crime[i] = 1;
		crimes+=crime[i];
	}
	for(int i=1;i<=n;i++)
	{
		if((vote[i]>0 && !crime[vote[i]]) || (vote[i]<0&&crime[-vote[i]]&&crimes==1))
		{
			puts("Lie");
		}
		else if((vote[i]>0&&crime[vote[i]]&&crimes==1)||(vote[i]<0&&!crime[-vote[i]]))
		{
			puts("Truth");
		}
		else puts("Not defined");
	}
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int n,Ans,now;
int a[200020],id[200020],rank[200020];
pair<int,int>ans[200020];

int check(int x)
{
	while(x)
	{
		if(x%10!=4&&x%10!=7)return 0;
		x/=10;
	}
	return 1;
}

void Check()
{
	for(int i=1;i<=n;i++)
		if(check(a[i]))return;
	for(int i=1;i<n;i++)
		if(a[i]>a[i+1])
		{
			puts("-1");
			exit(0);
		}
	puts("0");
	exit(0);
}

inline int cmp(int x,int y)
{
	return a[x]<a[y];
}

void Swap(int &x,int y)
{
	ans[++Ans]=make_pair(x,y);
	swap(id[rank[x]],id[rank[y]]);
	swap(rank[x],rank[y]);
	x=y;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),id[i]=i;
	Check();
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;i++)rank[id[i]]=i;
	for(int i=n;i;i--)
		if(check(a[i]))
		{
			now=i;
			break;
		}
	for(int i=1;i<=n;i++)
	{
		if(id[i]==i)continue;
		if(now!=i)Swap(now,i);
		if(now!=id[i])Swap(now,id[i]);
	}
	printf("%d\n",Ans);
	for(int i=1;i<=Ans;i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
}
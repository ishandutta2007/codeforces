#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
using namespace std;
int n,f[MAXN],p[MAXN],q[MAXN];
bool used[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&f[i]);
	bool flag=true;
	for(int i=1;i<=n;i++)
		if(f[f[i]]!=f[i]) {flag=false; break;}
	if(!flag)
	{
		puts("-1");
		return 0;
	}
	memset(used,false,sizeof(used));
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!used[f[i]])
		{
			used[f[i]]=true;
			p[++cnt]=f[i];
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		q[p[i]]=i;
	for(int i=1;i<=n;i++)
		printf("%d ",q[f[i]]);
	printf("\n");
	for(int i=1;i<=cnt;i++)
		printf("%d ",p[i]);
	printf("\n");
	return 0;
}
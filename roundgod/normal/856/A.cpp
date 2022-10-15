#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
bool used[MAXM];
vector<int> res,save;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		res.clear();
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(used,false,sizeof(used));
		for(int i=1;i<=1000000;i++)
		{
			if(used[i]) continue;
			res.push_back(i);
			used[i]=true;
			if(res.size()==n) break;
			save.clear();
			for(int j=0;j<n;j++)
				save.push_back(i+a[j]);
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					if(save[j]-a[k]>=1&&save[j]-a[k]<=1000000) used[save[j]-a[k]]=true;
		}
		if(res.size()!=n)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=0;i<n;i++)
			printf("%d ",res[i]);
		puts("");
	}
	return 0;
}
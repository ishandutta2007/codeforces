#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
bool used[MAXN];
int main()
{
	scanf("%d",&n);
	n*=2;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int ans=INF;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			memset(used,false,sizeof(used));
			used[i]=true;
			used[j]=true;
			int cnt=0;
			for(int k=0;k<n;k++)
			{
				if(used[k]) continue;
				used[k]=true;
				for(int l=k+1;l<n;l++)
				{
					if(used[l]) continue;
					used[l]=true;
					cnt+=a[l]-a[k];
					break;
				}
			}
			ans=min(ans,cnt);
		}
	printf("%d\n",ans);
	return 0;
}
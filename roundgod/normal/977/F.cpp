#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],dp[MAXN];
map<int,int> mp;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int ans=0,t=-1;
	for(int i=0;i<n;i++)
	{
		if(mp.find(a[i]-1)==mp.end()) mp[a[i]]=1; else 
		{
			if(mp.find(a[i])==mp.end()) mp[a[i]]=mp[a[i]-1]+1;
			else mp[a[i]]=max(mp[a[i]],mp[a[i]-1]+1);
		}
		if(mp[a[i]]>ans) ans=mp[a[i]],t=a[i];
	}
	printf("%d\n",ans);
	int now=t-ans+1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==now)
		{
			printf("%d ",i+1);
			now++;
		}
	}
	puts("");
	return 0;
}
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXC 300
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int p[MAXC],ans[MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	memset(p,-1,sizeof(p));
	for(int i=0;i<n;i++)
	{
		if(p[a[i]]!=-1) {ans[i]=p[a[i]]; continue;}
		int res=a[i];
		for(int j=max(0,a[i]-k+1);j<=a[i];j++)
			if(p[j]==-1||j==0||p[j-1]!=p[j]) {res=j; break;}
		for(int j=res;j<=a[i];j++) p[j]=res;
		ans[i]=p[a[i]];
	}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}
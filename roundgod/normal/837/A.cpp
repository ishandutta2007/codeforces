#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
char str[MAXN];
int main()
{
	scanf("%d",&n);
	getchar();
	gets(str);
	int cnt=0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]==' ')
		{
			ans=max(ans,cnt);
			cnt=0;
		}
		if(str[i]>='A'&&str[i]<='Z') cnt++;
	}
	ans=max(ans,cnt);
	printf("%d\n",ans);
	return 0;
}
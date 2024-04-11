#include<bits/stdc++.h>
#define N 204
using namespace std;
int n,a[N],now,ans;
bool vis[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n<<1;i++)
	{
		scanf("%d",a+i);now=a[i];
		if(vis[now])
		{
			for(int j=i;a[j-1]^now;j--)
			swap(a[j],a[j-1]),ans++;
		}
		vis[a[i]]=1;
	}
	printf("%d",ans);
}
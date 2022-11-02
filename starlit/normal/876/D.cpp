#include<cstdio>
#include<iostream>
#include<cstring>
#define N 300005
using namespace std;
int n,a,now,pre[N],nxt[N];
bool vis[N];
int main()
{
	scanf("%d",&n);pre[n]=n+1;
	printf("1");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		vis[a]=1;
		if(!vis[a+1])nxt[a]=a;
		else nxt[a]=nxt[a+1];
		if(!vis[a-1])pre[a]=a;
		else pre[a]=pre[a-1];
		pre[nxt[a]]=pre[a],nxt[pre[a]]=nxt[a];
		printf(" %d",i-n+pre[n]);
	}
}
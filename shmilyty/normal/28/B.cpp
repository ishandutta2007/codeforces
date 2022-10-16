#include<bits/stdc++.h>
using namespace std;
int n,a[101],fa[101];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(i-x>=1)
			fa[find(i-x)]=find(i);
		if(i+x<=n)
			fa[find(i+x)]=find(i);	
	}	
	for(int i=1;i<=n;i++)
		if(find(i)!=find(a[i]))
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}
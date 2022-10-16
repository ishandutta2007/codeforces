#include<bits/stdc++.h>
using namespace std;
int n,ans,a[200001],b[200001],posa[200001];
map<int,int> num;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		posa[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		int dis=(posa[b[i]]-i+n)%n;
		num[dis]++;
		ans=max(ans,num[dis]);
	}
	cout<<ans;
	return 0;
}
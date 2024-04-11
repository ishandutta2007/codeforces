#include<bits/stdc++.h>
#define N 1000006
using namespace std;
int n,now,mn,ans;
bool pri[N];
int main()
{
	scanf("%d",&n);mn=ans=n;
	for(int i=2;i<n;i++)
	if(!pri[i])
	{
		for(int j=2;i*j<=n;j++)
		pri[i*j]=1;
		if(n%i==0)mn=min(mn,i*(n/i-1)+1);
	}
	for(int i=2;i<n;i++)
	if(!pri[i])
	{
		for(int j=2;i*j<=n;j++)
		if(i*j>=mn)ans=min(ans,i*j-i);
	}
	printf("%d",ans+1);
}
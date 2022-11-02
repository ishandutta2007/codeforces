#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,A,B,T,a[N],b[N],ans;
char S[N];
int main()
{
	scanf("%d%d%d%d%s",&n,&A,&B,&T,S+1);
	for(int i=1;i<=n;i++)
	a[i]=a[i-1]+(i>1?A:0)+1+(S[i]=='w'?B:0);
	for(int i=n;i;i--)
	b[i]=b[i+1]+A+1+(S[i]=='w'?B:0);
	if(a[n]<=T)return printf("%d",n),0;
	for(int i=1,j=2;i<=n;i++)
	{
        if(a[i]+A*(i-1)>T)break;
        while(j<=n&&a[i]+b[j]+A*(i-1)>T)j++;
        ans=max(ans,i+n+1-j);
	}
	for(int i=1,j=2;i<=n;i++)
	{
        if(a[i]>T)break;
        while(j<=n&&a[i]+b[j]+A*(n+1-j)>T)j++;
        ans=max(ans,i+n+1-j);
	}
	printf("%d",ans);
}
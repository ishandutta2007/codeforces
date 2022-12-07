#include<bits/stdc++.h>
using namespace std;
const int N=4e5+50;
int n,ans,bas=0,pos,len,pd=1;
int A[N],B[N],vis[N];
int main()
{
	//freopen("c.in","r",stdin);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&A[i]);
		vis[A[i]]=1;
	}
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&B[i]);
		if(B[i]==1) pos=i;
	}
	if(pos)
	{
	for(i=pos+1;i<=n;i++)
	{
		if(B[i]!=i-pos+1) pd=0;
	}
	if(pd)
	{
		len=n-pos+1;
		for(i=1;i<pos;i++)
		{
			if(!vis[len+i]) pd=0;
			if(B[i]) vis[B[i]]=1; 
		}
		//cout<<"P"<<pd<<endl;
		if(pd) 
		{
			printf("%d",pos-1);
			return 0;
		}
	}
	}
	for(i=1;i<=n;i++)
	{
		if(B[i]) bas=max(bas,i-B[i]+1);
	}
	printf("%d",bas+n);
	return 0;
}
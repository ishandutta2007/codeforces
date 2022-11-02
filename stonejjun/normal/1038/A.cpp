#include<bits/stdc++.h>
using namespace std;


int arr[100001];
char c[100003];

int main()
{
	int a,b,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,mini=100000;
	
	scanf("%d %d",&n,&m);
	scanf("%s",c);
	for(i=0;i<n;i++)
	{
		arr[c[i]-'A'+1]++;
	}
	for(i=1;i<=m;i++)
	{
		mini=min(mini,arr[i]);
	}
	printf("%d",mini*m);
	
	
}
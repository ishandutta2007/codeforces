#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream> 
#include<algorithm>
#define MAXN 100
int n;
int num[MAXN];
bool used[MAXN];
int main()
{
	scanf("%d",&n);
	memset(num,0,sizeof(num));
	memset(used,false,sizeof(used));
	int s=0;
	for(int i=0;i<n;i++)
	{ 
	  scanf("%d",&num[i]);
	  s+=num[i];
   }
   s=s*2/n;
   for(int i=0;i<n/2;i++)
   {
   	int t;
   	for( t=0;t<n;t++)
   	  if(used[t]==false) break;
   	  used[t]=true;
   	for(int j=0;j<n;j++)
   	  if(t!=j&&used[j]==false&&num[t]+num[j]==s)
   	  {
   	  	used[j]=true;
   	  	printf("%d %d\n",t+1,j+1);
   	  	break;
		 }
   }
   return 0;
}
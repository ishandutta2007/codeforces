#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define MAXN 2001
#define INF 1000000001
using namespace std;
char c[MAXN][MAXN];
int extl[MAXN],extr[MAXN];
int m,n,cnt; 
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	  scanf("%s",c[i]);
	cnt=0;
	memset(extl,0,sizeof(extl));
	memset(extr,0,sizeof(extr));
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)
	    if(c[i][j]=='*')
	    {
	    	cnt++;
	    	extl[i]++;
	    	extr[j]++;
		}
	int f=1;
	for(int i=0;i<n;i++)
	  for(int j=0;j<m;j++)
	  if(f)
	  {
	    if (c[i][j]=='.')
		{
		   if (cnt==extl[i]+extr[j])
		   {
		   
		   printf("YES\n");
		   printf("%d %d",i+1,j+1);
		   f=0;
	}
	    }
	     else
	    {
	    	if (cnt==extl[i]+extr[j]-1)
	    	{
		
		   printf("YES\n");
		   printf("%d %d",i+1,j+1);
		   f=0;
	}
		}
		   
     } 
     if(f) printf("NO");
	return 0;
}
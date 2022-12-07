#include<bits/stdc++.h>
using namespace std;
int n,m,x[100010],p;
inline int pos(int i,int j)
{
	return (i-1)*m+j;
}
inline int f(int x)
{
	int i=(x-1)/m,j=x-i*m;
	i++;
	return (j-1)*n+i;
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	if(n<=3 && m<=3)
	  {
	   if(n==1 && m==1)
	     printf("YES\n1\n");
	   else if(n==3 && m==3)
	     printf("YES\n8 1 6\n3 5 7\n4 9 2\n");
	   else
	     printf("NO\n");
	   return 0;
	  }
	if(m<=3)
	  {
	   swap(n,m);
	   p=1;
	  }
	if(m&1)
	  for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		  x[pos(i,j)]=(j*2-(i&1)-1)%m+1+(i-1)*m;
	else
	  for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		  x[pos(i,(i&1)?j:(m+1-j))]=(j*2-(j>m/2)-1)%m+1+(i-1)*m;
	printf("YES\n");
	if(p)
	  for(i=1;i<=m;i++)
	    {
	     for(j=1;j<=n;j++)
	       printf("%d ",f(x[pos(j,i)]));
	     printf("\n");
	    }
    else
	  for(i=1;i<=n;i++)
	    {
	     for(j=1;j<=m;j++)
	       printf("%d ",x[pos(i,j)]);
	     printf("\n");
	    }
	return 0;
}
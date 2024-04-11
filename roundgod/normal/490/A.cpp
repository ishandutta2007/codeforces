#include<cstdio>
#include<cmath>
int main()
{
int a[5001],i,j,k,n,s,f,b[450][4];
scanf("%d",&n);
for(i=1;i<=n;i++)
  scanf("%d",&a[i]);
  f=1;
  s=0;
  k=0;
while(f==1)
{
	k++;
for(i=1;i<=3;i++)
{
	j=1;
  while (a[j]!=i&&j<=n)
    j++;
  if(a[j]==i) 
  {
   b[k][i]=j;
   a[j]=0;
   }
   else f=0;
}
if(f==1) 
s++;
}
printf("%d\n",s);
for(i=1;i<=k;i++)
{
	f=1;
	for(j=1;j<=3;j++)
	  if (b[i][j]==0) f=0;
	if (f==1)
  for(j=1;j<=3;j++)
printf("%d ",b[i][j]);
  printf("\n");
}
return 0;
}
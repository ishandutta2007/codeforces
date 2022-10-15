#include<cstdio>
int main()
{
int n,i,a[100001];
scanf("%d",&n);
for(i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(i=1;i<=n;i++)
   while (a[i]%2==0)
     a[i]/=2;
  for(i=1;i<=n;i++)
   while (a[i]%3==0)
     a[i]/=3;
  for(i=1;i<=n-1;i++)
    if(a[i]!=a[i+1]) 
    {
        printf("NO");
        return 0;
    }
 printf("YES");
 return 0;
}
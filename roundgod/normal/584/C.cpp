#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
int main()
{
char x[100005],y[100005],z[100005];
int i,a[100005],n,t,count1,count2;
scanf("%d %d",&n,&t);
scanf("%s",x);
scanf("%s",y);
memset(a,0,sizeof(a));
count1=0;
for(i=0;i<=n-1;i++)
  if(x[i]==y[i])
   {
     a[i]=1;
     count1++;
   }
count2=n-count1;
if(t<(count2+1)/2)
{
    printf("-1");
    return 0;
}
if(t>=count2)
{
    count2=t-count2;
    t=0;
    count1=0;
}
else
{
    count2=0;
    count1=(n-count1-t);
    t=count1;
}
for(i=0;i<=n-1;i++)
{
    if(x[i]==y[i])
    {
      if(count2>0)
        {
          count2--;
          if(x[i]!=97) z[i]=97; else z[i]=98;
        }
      else z[i]=x[i];
    }
    else
    {
    if(t>0)
    {
        t--;
        z[i]=x[i];
    }
    else
    if(count1>0)
    {
        count1--;
        z[i]=y[i];
    }
    else
    {
        if(x[i]!=97&&y[i]!=97) z[i]=97;
          else  if(x[i]!=98&&y[i]!=98) z[i]=98;
            else z[i]=99;
    }
}
}
for(i=0;i<=n-1;i++)
printf("%c",z[i]);
return 0;
}
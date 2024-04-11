#include<cstdio>
#include<cstring>
int main()
{
    char st[1000],i,j,k,l,digit[10];
    scanf("%s",st);
    l=strlen(st);
    for(i=0;i<=9;i++)
      digit[i]=1;
    for(i=0;i<=l-1;i++)
      if ((st[i]-48)%8==0) 
        {printf("YES\n");
        printf("%d",st[i]-48);
        return 0;
        }
    for(i=l-1;i>=0;i--)
{
    if(digit[st[i]-48]!=-1&&(st[i]-48)%2==0)
   {

      for(j=i-1;j>=0;j--)
      {
        for(k=j-1;k>=0;k--)
      {
        if(((st[k]-48)*100+(st[j]-48)*10+(st[i]-48))%8==0)
        {
          printf("YES\n");
          printf("%c%c%c",st[k],st[j],st[i]);
          return 0;
        }
      
      }
        if (((st[j]-48)*10+(st[i]-48))%8==0)
        {
          printf("YES\n");
          printf("%c%c",st[j],st[i]);
          return 0;
        }
    }  
   }
   digit[st[i]-48]=-1;
}
printf("NO");
return 0;
}
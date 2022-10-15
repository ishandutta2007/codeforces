#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
int main()
{
    int n,m,i,j,cont[100000][2],cnt,x,k,ans,t;
    char c[300005],y;
    ans=0;
    scanf("%d %d",&n,&m);
    scanf("%s",c);
    memset(cont,-1,sizeof(cont));
    i=1;
    j=1;
    for(j=0;j<=strlen(c)-1;j++)
      if(c[j]=='.')
      {
        cnt=0;
        while(c[j+cnt]=='.') cnt++;
        if(cnt>=2) ans=ans+cnt-1;
        j=j+cnt;
      }
for(i=1;i<=m;i++)
{
    scanf("%d %c",&x,&y);
    x--;
    if (c[x]=='.')
    {
        c[x]=y;
        if(y!='.')
          {
            if(x==0) if(c[1]=='.') ans--;
            if(x!=0) 
            {
                if(c[x-1]=='.'&&c[x+1]=='.')ans-=2;
                else if (c[x-1]=='.'||c[x+1]=='.') ans--;
            }
          }
     }
     else if(c[x]!='.')
     {
            c[x]=y;
            if(y=='.')
          {
            if(x==0) if(c[1]=='.') ans++;
            if(x!=0) 
            {
                if(c[x-1]=='.'&&c[x+1]=='.')ans+=2;
                else if (c[x-1]=='.'||c[x+1]=='.') ans++;
            }
          }
    }
        printf("%d\n",ans);
}

return 0;
    
}
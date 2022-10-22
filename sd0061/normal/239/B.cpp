#include <stdio.h>
#include <memory.h>
#include <ctype.h>
char s[120],t[120];
int vis[123];
int main()
{
    int n,q,i,r,x,y,f,p;
    scanf("%d%d%s",&n,&q,t);
    while(q--)
    {
        r=1; f=0;
        memcpy(s,t,sizeof(t));
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&x,&y);
        --x; --y;
        for(i=x;i>=x && i<=y;i+=r)
        {
            if(isdigit(s[i]))
            {
                vis[s[i]-'0']++;
                if(s[i]=='0') s[i]=0;
                else s[i]--;
                f=0;
            }
            else if(s[i]=='>')
            {
                r=1;
                if(f) s[p]=0;
                f=1; p=i;
            }
            else if(s[i]=='<')
            {
                r=-1;
                if(f) s[p]=0;
                f=1; p=i;
            }
        }
        i ++ , -- i;
        for(i=0;i<9;i++) printf("%d ",vis[i]);
        printf("%d\n",vis[i]);
    }
    return 0;
}
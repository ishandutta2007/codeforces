#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a[100010][27],win[100010],lose[100010],n,k,tot,now,root,bo,wx,l,u;
char s[100010];

int dfs(int now,int x)
{
    int bo=1;
    win[now]=x^1;
    for(int i=1;i<=26;i++)
    if(a[now][i])
    {
        bo=0;
        wx=dfs(a[now][i],x^1);
        if(wx==x)win[now]=x;
    }
    if(bo==1)return win[now];
    else return win[now];
}

int Dfs(int now,int x)
{
    int bo=1;
    lose[now]=x^1;
    for(int i=1;i<=26;i++)
    if(a[now][i])
    {
        bo=0;
        wx=Dfs(a[now][i],x^1);
        if(wx==x)lose[now]=x;
    }
    if(bo==1)return lose[now]=x;
    else return lose[now];
}

int main()
{
    scanf("%d%d",&n,&k);
    tot=root=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        now=root;
        l=strlen(s+1);
        for(int j=1;j<=l;j++)
        {
            if(a[now][s[j]-'a'+1])now=a[now][s[j]-'a'+1];
            else a[now][s[j]-'a'+1]=++tot,now=tot;
        }
    }
    dfs(1,1);
    Dfs(1,1);
    if(win[1])
    {
        if(k%2||lose[1])puts("First");
        else puts("Second");
        return 0;
    }
    else puts("Second");
}
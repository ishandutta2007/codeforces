#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long A[4][4],C[4][4],Ans[4][4],a[4][4];
int trie[1000010][4];
long long n,nowans,ans,l,r;
int len,now,cnt;
char s[100010];

void dfs(int x,int now,int len)
{
    for(int i=0;i<4;i++)
        if(trie[now][i])dfs(x,trie[now][i],len+1);
        else a[x][i]=min(a[x][i],1ll*len);
}

int check(long long now)
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            A[i][j]=a[i][j],Ans[i][j]=0;
    while(now)
    {
        if(now&1)
        {
            memset(C,0x3f,sizeof(C));
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    for(int k=0;k<4;k++)
                        C[i][j]=min(C[i][j],Ans[i][k]+A[k][j]);
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    Ans[i][j]=C[i][j];
        }
        memset(C,0x3f,sizeof(C));
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                for(int k=0;k<4;k++)
                    C[i][j]=min(C[i][j],A[i][k]+A[k][j]);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                A[i][j]=C[i][j];
        now>>=1;
    }
    nowans=0x3f3f3f3f3f3f3f3fll;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            nowans=min(nowans,Ans[i][j]);
    if(nowans<n)return 1;
    return 0;
}

int main()
{
    scanf("%I64d",&n);
    scanf("%s",s);
    len=strlen(s);
    for(int i=0;i<len;i++)
    {
        now=0;
        for(int j=i;j<len&&j<=i+10;j++)
        {
            if(!trie[now][s[j]-'A'])trie[now][s[j]-'A']=++cnt;
            now=trie[now][s[j]-'A'];
        }
    }
    memset(a,0x3f,sizeof(a));
    for(int i=0;i<4;i++)
        if(trie[0][i])dfs(i,trie[0][i],1);
    l=1;r=1e18;
    while(l<=r)
    {
        long long mid=(l+r)>>1;
        if(check(mid-1))ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%I64d",ans);
}
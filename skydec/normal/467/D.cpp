#include<stdio.h>
#include<cstring>
#define MAXN 710000
using namespace std;
int n,m;int num[MAXN];
int head[MAXN*5],next[MAXN*5],p[MAXN*5];int t1=0;
int len[MAXN],r[MAXN];
char str[MAXN];
int go[MAXN*2][26];int tot=1;
int info[MAXN*2];int number=0;
int get(char q)
{
    if(q>='a'&&q<='z')return q-'a';
    return q-'A';
}
int geter()
{
    int l=strlen(str+1);int now=1;
    for(int i=1;i<=l;i++)
    {
            if(!go[now][get(str[i])])go[now][get(str[i])]=++tot;
            now=go[now][get(str[i])];
            }
    if(!info[now])info[now]=++number;
    return info[now];
}
int ans[MAXN];
void line(int a,int b){t1++;p[t1]=b;next[t1]=head[a];head[a]=t1;}
int dfn[MAXN],low[MAXN],stack[MAXN];int D;int top;bool ins[MAXN];int nums[MAXN];
int tarjan(int x)
{
    dfn[x]=low[x]=++D;stack[++top]=x;ins[x]=1;
    for(int u=head[x];u;u=next[u])
    if(!dfn[p[u]])
    {
                  tarjan(p[u]);
                  if(low[p[u]]<low[x])low[x]=low[p[u]];
                  }
    else
    if(ins[p[u]]){if(dfn[p[u]]<low[x])low[x]=dfn[p[u]];}
    if (low[x]==dfn[x]){
		int k;
		do {
        k=stack[top--];ins[k]=0;nums[k]=x; 
        if(!ans[x])ans[x]=k;
        for(int u=head[k];u;u=next[u])
        line(x,p[u]);
        if((r[ans[x]]>r[k])||(r[ans[x]]==r[k]&&len[ans[x]]>len[k]))ans[x]=k;
        }while (k!=x);
	}
}
bool dp[MAXN];
int dfs(int x)
{
    if(dp[x])return ans[x];if(!ans[x])ans[x]=x;dp[x]=1;
    for(int u=head[x];u;u=next[u])
    if(nums[p[u]]!=x)
    {
                     int k=dfs(nums[p[u]]);
                     if(!ans[x])ans[x]=k;
                     //if(x==3)printf("--_%d\n",nums[p[u]]);
                     if((r[ans[x]]>r[k])||(r[ans[x]]==r[k]&&len[ans[x]]>len[k]))ans[x]=k;
                     }
    return ans[x];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            scanf("%s",str+1);
            num[i]=geter();
            len[num[i]]=strlen(str+1);
            r[num[i]]=0;
            for(int is=1;is<=len[num[i]];is++)
            if(str[is]=='r'||str[is]=='R')r[num[i]]++;
            }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
            scanf("%s",str+1);
            int a=geter();
            len[a]=strlen(str+1);
            r[a]=0;
            for(int is=1;is<=len[a];is++)
            if(str[is]=='r'||str[is]=='R')r[a]++;
            
            scanf("%s",str+1);
            int b=geter();
            len[b]=strlen(str+1);
            r[b]=0;
            for(int is=1;is<=len[b];is++)
            if(str[is]=='r'||str[is]=='R')r[b]++;
            line(a,b);
            }
    long long R,Len;R=Len=0;
    for(int i=1;i<=number;i++)if(!nums[i])tarjan(i);
    //for(int i=1;i<=number;i++)printf("%d -\n",nums[i]);
    //for(int u=head[3];u;u=next[u])printf("_%d\n",p[u]);
    for(int i=1;i<=n;i++)
    {
            int u=dfs(nums[num[i]]);
            R+=1ll*r[u];
            Len+=1ll*len[u];
            }
    printf("%I64d %I64d\n",R,Len);
    return 0;
}
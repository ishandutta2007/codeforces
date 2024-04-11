#include<cstdio>
#include<vector>
#include<cstring>

#define N 1000010

using namespace std;

vector<int>g[N];
vector<char>S[N];
int trie[N][26],q[N],sum[N],fail[N];
int now,Cnt,cnt,h,l,v,n,m,len,ans,o,x;
int flag[N],st[N],ed[N],c[N],L[N];
char s[N];

void build()
{
    for(int i=0;i<26;i++)
        if(trie[0][i])
        {
            fail[trie[0][i]]=0;
            q[++l]=trie[0][i];
        }
    while(h<l)
    {
        v=q[++h];
        for(int i=0;i<26;i++)
            if(trie[v][i])
            {
                now=trie[v][i];
                fail[now]=trie[fail[v]][i];
                sum[now]+=sum[trie[fail[v]][i]];
                q[++l]=now;
            }
            else trie[v][i]=trie[fail[v]][i];
    }
}

void dfs(int x)
{
    st[x]=++Cnt;
    for(int i=0;i<(int)g[x].size();i++)
        dfs(g[x][i]);
    ed[x]=Cnt;
}

inline void Add(int x,int o)
{
    for(;x<=Cnt;x+=x&-x)c[x]+=o;
}

inline int ask(int x)
{
    int nowans=0;
    for(;x;x-=x&-x)nowans+=c[x];
    return nowans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        flag[i]=1;
        now=0;
        scanf("%s",s);
        len=strlen(s);
        L[i]=len;
        for(int j=0;j<len;j++)
        {
            S[i].push_back(s[j]);
            o=s[j]-'a';
            if(!trie[now][o])trie[now][o]=++cnt;
            now=trie[now][o];
        }
        sum[now]++;
    }
    build();
    for(int i=1;i<=cnt;i++)g[fail[i]].push_back(i);
    dfs(0);
    for(int i=0;i<=cnt;i++)
    {
        Add(st[i],sum[i]);
        Add(st[i]+1,-sum[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        if(s[0]=='?')
        {
            now=0;
            ans=0;
            len=strlen(s);
            for(int j=1;j<len;j++)
            {
                now=trie[now][s[j]-'a'];
                ans+=ask(st[now]);
            }
            printf("%d\n",ans);
        }
        if(s[0]=='-')
        {
            x=0;
            len=strlen(s);
            for(int j=1;j<len;j++)x=x*10+s[j]-'0';
            if(!flag[x])continue;
            flag[x]=0;
            now=0;
            for(int j=0;j<L[x];j++)now=trie[now][S[x][j]-'a'];
            Add(st[now],-1);
            Add(ed[now]+1,1);
        }
        if(s[0]=='+')
        {
            x=0;
            len=strlen(s);
            for(int j=1;j<len;j++)x=x*10+s[j]-'0';
            if(flag[x])continue;
            flag[x]=1;
            now=0;
            for(int j=0;j<L[x];j++)now=trie[now][S[x][j]-'a'];
            Add(st[now],1);
            Add(ed[now]+1,-1);
        }
    }
}
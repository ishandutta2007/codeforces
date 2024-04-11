#include<bits/stdc++.h>
#define MAXL 12
#define MAXS 105
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000009
using namespace std;
typedef long long ll;
struct trie
{
    trie* next[26];
    trie* fail;
    ll id;
    ll max_match;
};
trie* thead;
vector<trie*> num;
char str[MAXN];
ll dp[MAXN][MAXS][MAXL];
ll nxt[MAXS][4];
ll ti=0,n,m;
char ATCG[4]={'A','T','C','G'};
inline trie*  newnode()
{
    trie* t;
    t=(trie*)malloc(sizeof(trie));
    t->fail=NULL;
    t->id=0;
    t->max_match=0;
    memset(t,0,sizeof(trie));
    return t;
}
void insert(char x[])
{
    ll i;
    trie* s=thead;
    trie* t;
    for(i=0;x[i];i++)
    {
        if(s->next[x[i]-'A']) s=s->next[x[i]-'A']; 
        else
        {
            t=newnode();
            s->next[x[i]-'A']=t;
            s=t;
            s->id=ti++;
            num.push_back(s);
        }
    }
    s->max_match=max(s->max_match,(ll)strlen(x));
    return;
}
trie* g(trie* s, char x)
{
    if(s->next[x-'A']) return s->next[x-'A'];
    else if(s==thead) return thead;
    else return NULL;
}

void bfs()
{
    trie* s=thead;
    queue<trie*> que;
    for(ll i=0;i<26;i++)
        if(s->next[i]){s->next[i]->fail=thead; que.push(s->next[i]);}
    while(!que.empty())
    {
        trie* t=que.front();
        que.pop();
        t->max_match=max(t->max_match,t->fail->max_match);
        for(ll i=0;i<26;i++)
            if(g(t,(char)('A'+i))!=NULL)
            {
                que.push(t->next[i]);
                trie* v=t->fail;
                while(g(v,(char)('A'+i))==NULL) v=v->fail;
                t->next[i]->fail=g(v,(char)('A'+i));
            }
    }
    return;
}
void deltrie(trie* s)
{
    ll i;
    for(i=0;i<26;i++)
    {
        if(s->next[i])
        deltrie(s->next[i]);
    }
    free(s);
    s=NULL;
}
int main()
{
    thead=newnode();
    scanf("%I64d%I64d",&n,&m);
    num.clear();
    num.push_back(thead);
    thead->id=0;
    ti=1;
    ll mlen=0;
    for(ll i=0;i<m;i++)
    {
        scanf("%s",str);
        mlen=max(mlen,(ll)strlen(str));
        insert(str);
    }
    bfs();
    for(ll i=0;i<ti;i++)
    {
        for(ll j=0;j<4;j++)
        {
            trie* pt=num[i];
            while(g(pt,ATCG[j])==NULL)
                 pt=pt->fail;
            pt=g(pt,ATCG[j]);
            nxt[i][j]=pt->id;
        }
    }
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<ti;j++)
        {
            for(ll k=0;k<=mlen;k++)
            {
                for(ll p=0;p<4;p++)
                {
                    int to=nxt[j][p];
                    if(num[to]->max_match>k) dp[i+1][to][0]=(dp[i+1][to][0]+dp[i][j][k])%MOD;
                    else dp[i+1][to][k+1]=(dp[i+1][to][k+1]+dp[i][j][k])%MOD;
                }
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<ti;i++)
        ans=(ans+dp[n][i][0])%MOD;
    printf("%I64d\n",ans);
    deltrie(thead);
    return 0;
}
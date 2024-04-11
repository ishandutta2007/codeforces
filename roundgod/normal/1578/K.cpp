#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int tot=1,t=0;
int trie[MAXM][26],id[MAXM];
string str;
void insert(string &str)
{
    int rt=1;
    for(int i=0;i<(int)str.size();i++)
    {
        int x=str[i]-'A';
        if(trie[rt][x]==0) trie[rt][x]=++tot;
        rt=trie[rt][x];
    }
    id[rt]=++t;
}
void dfs(int v,int level)
{
    if(id[v])
    {
        printf("%d ",id[v]);
        return;
    }
    if(!level)
       { for(int i=0;i<26;i++) if(trie[v][i])  dfs(trie[v][i],level^1);}
    else
       { for(int i=25;i>=0;i--) if(trie[v][i]) dfs(trie[v][i],level^1);}
}
int main()
{
    memset(trie,0,sizeof(trie));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        insert(str);
    }
    dfs(1,0);
    return 0;
}
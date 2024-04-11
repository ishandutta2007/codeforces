#include<bits/stdc++.h>
#define MAXN 100050
using namespace std;
struct trie
{
    trie* next[26];
    bool mark;
    multiset<int> ms;
    int dep;
};
trie* thead;
inline trie*  newnode()
{
    trie* t;
    t=(trie*)malloc(sizeof(trie));
    memset(t,0,sizeof(trie));
    t->dep=0;
    return t;
}
void insert(char x[])
{
    trie* s=thead;
    trie* t;
    for(int i=0;x[i];i++)
    {
        if(s->next[x[i]-'a']) {s=s->next[x[i]-'a'];}
        else
        {
            t=newnode();
            s->next[x[i]-'a']=t;
            t->dep=s->dep+1;
            s=t;
        }
    }
    s->ms.insert(s->dep);
    return;
}
void deltrie(trie* s)
{
    for(int i=0;i<26;i++)
    {
        if(s->next[i])
        deltrie(s->next[i]);
    }
    free(s);
    s=NULL;
}
char str[MAXN];
int n;
void dfs(trie *s)
{
    if(s==thead)
    {
        for(int i=0;i<26;i++)
        {
            if(s->next[i])
            dfs(s->next[i]);
        }
        return;
    }
    bool flag=(s->ms.empty())?false:true;
    for(int i=0;i<26;i++)
    {
        if(s->next[i]) 
        {
            dfs(s->next[i]);
            trie* v=s->next[i];
            if((v->ms).size()>(s->ms).size()) swap(v->ms,s->ms);
            for(auto &t:v->ms) s->ms.insert(t);
            v->ms.clear();
        }
    }
    if(!flag)
    {
        s->ms.erase(--s->ms.end());
        s->ms.insert(s->dep);
    }
}
int main()
{
    thead=newnode();
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        insert(str);
    }
    dfs(thead);
    for(int i=0;i<26;i++)
    {
        if(thead->next[i])
        {
            trie *v=thead->next[i];
            for(auto &t:v->ms) ans+=t;
        }
    }
    printf("%d\n",ans);
    deltrie(thead);
    return 0;
}
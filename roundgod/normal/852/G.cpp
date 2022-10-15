#include<bits/stdc++.h>
using namespace std;
struct trie
{
    trie* next[5];
    int mark;
    pair<bool,int> used;
};
trie* thead;
int len;
char x[55];
inline trie*  newnode()
{
    trie* t;
    t=(trie*)malloc(sizeof(trie));
    memset(t,0,sizeof(trie));
    t->mark=0;
    t->used.first=false;
    t->used.second=0;
    return t;
}
void insert(char x[])
{
    int i;
    trie* s=thead;
    trie* t;
    for(i=0;x[i];i++)
    {
        if(s->next[x[i]-'a']) {s=s->next[x[i]-'a'];}
        else
        {
            t=newnode();
            s->next[x[i]-'a']=t;
            s=t;
        }
    }
    s->mark++;
    return;
}
int find(trie* s, int k,int p)
{
    int ans=0;
    if(k==len-1)
    {
        if(x[k]=='?')
        {
            if(s->mark&&!(s->used.first&&s->used.second==p)) {ans+=s->mark; s->used.first=true; s->used.second=p;}
            for(int i=0;i<5;i++)
                if(s->next[i]&&s->next[i]->mark&&!(s->next[i]->used.first&&s->next[i]->used.second==p)) {ans+=s->next[i]->mark; s->next[i]->used.first=true; s->next[i]->used.second=p; }
        }
        else
            if(s->next[x[k]-'a']&&s->next[x[k]-'a']->mark&&!(s->next[x[k]-'a']->used.first&&s->next[x[k]-'a']->used.second==p)) {ans+=s->next[x[k]-'a']->mark; s->next[x[k]-'a']->used.first=true;s->next[x[k]-'a']->used.second=p;}
        return ans;
    }
    else
    {
        if(x[k]=='?')
        {
            ans+=find(s,k+1,p);
            for(int i=0;i<5;i++)
                if(s->next[i]) ans+=find(s->next[i],k+1,p);
        }
        else
        {
            if(!s->next[x[k]-'a']) return 0;
            else return find(s->next[x[k]-'a'],k+1,p);
        }
        return ans;
    }
}
void deltrie(trie* s)
{
    int i;
    for(i=0;i<5;i++)
    {
        if(s->next[i])
        deltrie(s->next[i]);
    }
    free(s);
    s=NULL;
}
int n,m;
int main()
{
    scanf("%d %d",&n,&m);
    thead=newnode();
    for(int i=0;i<n;i++)
    {
        scanf("%s",x);
        insert(x);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%s",x);
        len=strlen(x);
        printf("%d\n",find(thead,0,i));
    }
    deltrie(thead);
    return 0;
}
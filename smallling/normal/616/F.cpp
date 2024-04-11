#include<cstdio>
#include<cstring>
#include<algorithm>

#define N 500010

using namespace std;

struct Sam{
    Sam *fa,*go[26];
    int val,last,flag;
    long long sum;
}*now,*root,*last,*cur,Pool[N*2];

struct lhy{
    Sam *x,*y;
    int next;
}edge[N*2];

int o,tot,n,st[N/5+10],ed[N/5+10];
long long ans;
char s[N];

void Prepare()
{
    cur=Pool;
    root=last=cur;
}

void Insert(int now)
{
    if(last->go[now])
    {
        Sam *p=last,*q=p->go[now];
        if(q->val==p->val+1)
        {
            q->sum+=o;
            last=q;
            return;
        }
        Sam *nt=++cur;
        memcpy(nt->go,q->go,sizeof q->go);
        nt->val=p->val+1;
        nt->fa=q->fa;
        q->fa=nt;
        while(p&&p->go[now]==q)p->go[now]=nt,p=p->fa;
        last=nt;
        nt->sum+=o;
        return;
    }
    Sam *p=last,*np=++cur;
    np->sum=o;
    np->val=p->val+1;
    while(p&&!p->go[now])p->go[now]=np,p=p->fa;
    if(!p)np->fa=root;
    else
    {
        Sam *q=p->go[now];
        if(q->val==p->val+1)np->fa=q;
        else
        {
            Sam *nt=++cur;
            memcpy(nt->go,q->go,sizeof q->go);
            nt->val=p->val+1;
            nt->fa=q->fa;
            np->fa=nt;
            q->fa=nt;
            while(p&&p->go[now]==q)p->go[now]=nt,p=p->fa;
        }
    }
    last=np;
}

inline void add(Sam *x,Sam *y)
{
    edge[++tot].x=x;edge[tot].y=y;edge[tot].next=x->last;x->last=tot;
}

void Dfs(Sam *now)
{
    for(int i=now->last;i;i=edge[i].next)
        Dfs(edge[i].y),now->sum+=edge[i].y->sum;
    ans=max(ans,now->sum*now->val);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        st[i]=ed[i-1]+1;
        scanf("%s",s+st[i]);
        ed[i]=st[i]+strlen(s+st[i])-1;
    }
    Prepare();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&o);
        last=root;
        for(int j=st[i];j<=ed[i];j++)
            Insert(s[j]-'a');
    }
    for(now=cur;now!=root;now--)add(now->fa,now);
    Dfs(root);
    printf("%I64d\n",ans);
}
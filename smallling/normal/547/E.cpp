#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

struct Sam{
    Sam *go[26],*fa;
    int val,x,last,num;
}*root,*last,*cur,*now;
Sam Pool[400020];

struct lhy{
    int nowk,x,k,id;
}A[1000010];

struct lnm{
    int x,y,next;
}edge[400020];

int numcnt,cnt,tot,n,m,l,r,k,A0,nowsx;
int c[400020],son[400020],L[400020],R[400020],len[200020],End[200020];
long long ans[500050];
char S[200020];
string s[200020];

void Insert(int now)
{
    Sam *p=last,*np=++cur;
    np->val=p->val+1;np->num=++numcnt;
    while(p&&!p->go[now])p->go[now]=np,p=p->fa;
    if(!p)np->fa=root;
    else
    {
        Sam *q=p->go[now];
        if(q->val==p->val+1)np->fa=q;
        else
        {
            Sam *nt=++cur;nt->num=++numcnt;
            memcpy(nt->go,q->go,sizeof q->go);
            nt->val=p->val+1;
            nt->fa=q->fa;
            q->fa=nt;
            np->fa=nt;
            while(p&&p->go[now]==q)p->go[now]=nt,p=p->fa;
        }
    }
    last=np;
}

void Prepare()
{
    cur=Pool;
    root=last=cur;
}

inline int cmp(const lhy &a,const lhy &b)
{
    return a.x<b.x;
}

void dfs(int x)
{
    L[x]=++cnt;
    for(int i=son[x];i;i=edge[i].next)dfs(edge[i].y);
    R[x]=cnt;
}

inline void add(int x,int y)
{
    edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}

inline void add(int x)
{
    for(;x<=cnt;x+=x&-x)c[x]++;
}

inline int ask(int x)
{
    int nowans=0;
    for(;x;x-=x&-x)nowans+=c[x];
    return nowans;
}

int main()
{
    Prepare();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",S);
        len[i]=strlen(S);
        s[i]=(string)S;
        last=root;
        for(int j=0;j<len[i];j++)Insert(s[i][j]-'a');
    }
    for(int i=1;i<=n;i++)
    {
        now=root;
        for(int j=0;j<len[i];j++)now=now->go[s[i][j]-'a'];
        End[i]=now->num;
    }
    for(Sam *i=root;i<=cur;i++)if(i->fa)add(i->fa->num,i->num);
    dfs(root->num);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&l,&r,&k);
        A[++A0]=(lhy){-1,l-1,k,i};
        A[++A0]=(lhy){ 1,r  ,k,i};
    }
    nowsx=0;
    sort(A+1,A+1+A0,cmp);
    for(int i=1;i<=A0;i++)
    {
        while(nowsx<=A[i].x)
        {
            now=root;
            for(int j=0;j<len[nowsx];j++)now=now->go[s[nowsx][j]-'a'],add(L[now->num]);
            nowsx++;
        }
        ans[A[i].id]+=A[i].nowk*(ask(R[End[A[i].k]])-ask(L[End[A[i].k]]-1));
    }
    for(int i=1;i<=m;i++)printf("%I64d\n",ans[i]);
}
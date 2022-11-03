#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

#define maxn 200005

char list[maxn];
int first[300],a[maxn],rank[maxn],cnt[maxn],tmp[maxn],sa[maxn],h[maxn];
int n;

int id[maxn];

inline bool cmph(const int &i,const int &j)
{
    return h[i]>h[j];
}

struct node
{
    int l,r;
    LL sum;
}Tree[maxn*4];

inline void Build(int num,int l,int r)
{
    memset(Tree,0,sizeof(Tree));
}

inline LL C(LL n,int m)
{
    return n*(n-1)/2;
}

inline void Merge(node &a,node l,node r,int L,int mid,int R)
{
    a.l=l.l;
    if (l.l==mid-L+1) a.l+=r.l;
    a.r=r.r;
    if (r.r==R-mid) a.r+=l.r;
    a.sum=l.sum+r.sum-C(l.r+1,2)-C(r.l+1,2)+C(l.r+r.l+1,2);
}

inline void Insert(int num,int l,int r,int pos)
{
    if (l==r){
        Tree[num].l=Tree[num].r=1;
        Tree[num].sum=C(1+1,2);
        return;
    }
    int mid=(l+r)/2;
    if (pos<=mid) Insert(num*2,l,mid,pos);
    else Insert(num*2+1,mid+1,r,pos);
    
    Merge(Tree[num],Tree[num*2],Tree[num*2+1],l,mid,r);
}

LL sum;
int up[maxn],down[maxn];

inline int Find(int x,int fa[])
{
    if (x==fa[x]) return x;
    return fa[x]=Find(fa[x],fa);
}

inline void merge(int i,int j)
{
    if (Find(i,down)!=Find(i,up)){
        sum-=C(Find(i,down)-Find(i,up)+2,2);
    }
    if (Find(j,down)!=Find(j,up)){
        sum-=C(Find(j,down)-Find(j,up)+2,2);
    }
    down[i]=Find(j,down);
    up[j]=Find(i,up);
    
    int len=down[i]-up[j]+1;
    sum+=C(len+1,2);
}

int main()
{
    scanf("%s",list+1);
    n=strlen(list+1);
    memset(first,0,sizeof(first));
    memset(rank,0,sizeof(rank));
    memset(tmp,0,sizeof(tmp));
    for (int i=1;i<=n;++i)
        first[list[i]]=1;
    for (int i=1;i<256;++i)
        first[i]+=first[i-1];
    for (int i=1;i<=n;++i)
        rank[i]=first[list[i]];
    int k;
    for (k=0;;++k)
    {
        int l=1<<k;
        if (l>n) break;
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;++i)
            ++cnt[rank[i+l]];
        for (int i=1;i<=n;++i)
            cnt[i]+=cnt[i-1];
        for (int i=n;i>0;--i)
            tmp[cnt[rank[i+l]]--]=i;
        
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;++i)
            ++cnt[rank[tmp[i]]];
        for (int i=1;i<=n;++i)
            cnt[i]+=cnt[i-1];
        for (int i=n;i>0;--i)
            sa[cnt[rank[tmp[i]]]--]=tmp[i];

        memcpy(tmp,rank,sizeof(tmp));
        int p=1;
        rank[sa[1]]=1;
        for (int i=2;i<=n;++i)
        {
            if (tmp[sa[i]]!=tmp[sa[i-1]] || tmp[sa[i]+l]!=tmp[sa[i-1]+l]) ++p;
            rank[sa[i]]=p;
        }
        if (p==n) break;
    }
    k=0;
    for (int i=1;i<=n;++i)
    {
        if (rank[i]==n)
        {
            k=0;
            h[n]=0;
            continue;
        }
        int j=sa[rank[i]+1];
        --k;
        if (k<0) k=0;
        while (i+k<=n && j+k<=n && list[i+k]==list[j+k]) ++k;
        h[rank[i]]=k;
    }
    
    int limit=0;
    for (int i=1;i<n;++i){
        id[i]=i;
        limit=max(limit,h[i]);
    }
    for (int i=1;i<=n;++i) up[i]=down[i]=i;
    sort(id+1,id+n,cmph);
    
    LL ans=0;
    for (int i=1;i<=n;++i){
        int limit=0;
        if (i<n) limit=max(limit,h[i]);
        if (i>1) limit=max(limit,h[i-1]);
        //printf("%d %d\n",i,limit);
        ans+=max((n-sa[i]+1)-limit,0);
    }
        
    sum=0;
    for (int i=1;i<n;++i){
        merge(id[i],id[i]+1);
        while (i+1<n && h[id[i+1]]==h[id[i]]){
            ++i;
            merge(id[i],id[i]+1);
        }
        int next;
        if (i+1==n) next=0;
        else next=h[id[i+1]];
        int num=h[id[i]]-next;
        //printf("%I64d %d %d\n",sum,h[id[i]],next);
        ans+=num*sum;
    }
    cout << ans << endl;
    
    return 0;
}
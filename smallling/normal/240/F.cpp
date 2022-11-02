#include<cstdio>

#define N 100010

using namespace std;

int n,m,cnt,l,r,nowx,nowl,sum[26];
int tree[N*4][26];
bool cover[N*4][26];
char s[N];

inline void up(int k)
{
    for(int i=0;i<26;i++)
        tree[k][i]=tree[k<<1][i]+tree[k<<1|1][i];
}

void build(int k,int l,int r)
{
    if(l==r)
    {
        tree[k][s[l]-'a']++;
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    up(k);
}

inline void down(int k,int l,int r)
{
    int mid=(l+r)>>1;
    for(int i=0;i<26;i++)
        if(cover[k][i])goto la;
    return;
    la:;
    for(int i=0;i<26;i++)
        if(cover[k][i])
        {
            cover[k<<1][i]=cover[k<<1|1][i]=1;
            tree[k<<1][i]=mid-l+1;
            tree[k<<1|1][i]=r-mid;
            cover[k][i]=0;
        }
        else tree[k<<1][i]=tree[k<<1|1][i]=cover[k<<1][i]=cover[k<<1|1][i]=0;
}

void ask(int k,int l,int r,int ll,int rr)
{
    if(ll<=l&&r<=rr)
    {
        for(int i=0;i<26;i++)
            sum[i]+=tree[k][i];
        return;
    }
    down(k,l,r);
    int mid=(l+r)>>1;
    if(mid>=ll)ask(k<<1,l,mid,ll,rr);
    if(mid<rr)ask(k<<1|1,mid+1,r,ll,rr);
}

void add(int k,int l,int r,int ll,int rr,int kind)
{
    if(ll<=l&&r<=rr)
    {
        for(int i=0;i<26;i++)
            tree[k][i]=cover[k][i]=0;
        tree[k][kind]=r-l+1;
        cover[k][kind]=1;
        return;
    }
    down(k,l,r);
    int mid=(l+r)>>1;
    if(mid>=ll)add(k<<1,l,mid,ll,rr,kind);
    if(mid<rr)add(k<<1|1,mid+1,r,ll,rr,kind);
    up(k);
}

void getans(int k,int l,int r)
{
    if(l==r)
    {
        for(int i=0;i<26;i++)
            if(tree[k][i])
            {
                putchar(i+'a');
                return;
            }
    }
    down(k,l,r);
    int mid=(l+r)>>1;
    getans(k<<1,l,mid);
    getans(k<<1|1,mid+1,r);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    build(1,1,n);
    while(m--)
    {
        cnt=0;
        nowx=-1;
        scanf("%d%d",&l,&r);
        for(int i=0;i<26;i++)sum[i]=0;
        ask(1,1,n,l,r);
        for(int i=0;i<26;i++)
        {
            cnt+=sum[i]&1;
            if(cnt==1&&nowx==-1)nowx=i;
        }
        if(cnt>1)continue;
        nowl=0;
        for(int i=0;i<26;i++)
            if(sum[i]/2)add(1,1,n,l+nowl,l+nowl+sum[i]/2-1,i),add(1,1,n,r-nowl-sum[i]/2+1,r-nowl,i),nowl+=sum[i]/2;
        if(cnt)add(1,1,n,l+nowl,l+nowl,nowx);
    }
    getans(1,1,n);
}
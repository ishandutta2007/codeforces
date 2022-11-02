#include<cstdio>
#include<cstring>

#define base 233
#define mo 1000000007
#define N 400010

using namespace std;

struct tree{
    int z,f;
}tree[N*4];

int n,d,Z,F,nowlen,now;
int Pow[N];
char Ch,s[N];

inline void up(int k,int l,int r)
{
    int mid=(l+r)>>1;
    tree[k].z=(1ll*tree[k<<1].z*Pow[r-(mid+1)+1]%mo+tree[k<<1|1].z)%mo;
    tree[k].f=(1ll*tree[k<<1|1].f*Pow[mid-l+1]%mo+tree[k<<1].f)%mo;
}

void build(int k,int l,int r)
{
    if(l==r)
    {
        tree[k].z=tree[k].f=s[l]-'a'+1;
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    up(k,l,r);
}

void add(int k,int l,int r,int ll,int o)
{
    if(l==r)
    {
        tree[k].z=tree[k].f=o;
        return;
    }
    int mid=(l+r)>>1;
    if(ll<=mid)add(k<<1,l,mid,ll,o);
    else add(k<<1|1,mid+1,r,ll,o);
    up(k,l,r);
}

void ask(int k,int l,int r,int ll,int rr)
{
    if(ll<=l&&r<=rr)
    {
        Z=(1ll*Z*Pow[r-l+1]%mo+tree[k].z)%mo;
        F=(1ll*tree[k].f*Pow[nowlen]%mo+F)%mo;
        nowlen+=r-l+1;
        return;
    }
    int mid=(l+r)>>1;
    if(ll<=mid)ask(k<<1,l,mid,ll,rr);
    if(mid<rr)ask(k<<1|1,mid+1,r,ll,rr);
}

int get(int k,int l,int r,int ll,int rr)
{
    if(ll<=0)return 0;
    Z=F=nowlen=0;
    ask(k,l,r,ll,rr);
    return Z==F;
}

int main()
{
    scanf("%d",&d);
    scanf("%s",s+1);
    Pow[0]=1;
    n=strlen(s+1);
    for(int i=1;i<=n;i++)Pow[i]=1ll*Pow[i-1]*base%mo;
    build(1,1,n);
    now=d;
    if(get(1,1,n,now-d+1,now))goto la;
    now++;
    while(now<=n)
    {
        if(get(1,1,n,now-d+1,now)||get(1,1,n,now-d-1+1,now))goto la;
        now++;
    }
    la:;
    if(now>n)now=n;
    while(now)
    {
        for(char ch=s[now]+1;ch<='z';ch++)
        {
            add(1,1,n,now,ch-'a'+1);
            if(!(get(1,1,n,now-d+1,now)||get(1,1,n,now-d-1+1,now)))
            {
                Ch=ch;
                break;
            }
        }
        if(Ch)
        {
            s[now]=Ch;
            break;
        }
        now--;
    }
    if(!now)return puts("Impossible"),0;
    now++;
    while(now<=n)
    {
        for(char ch='a';ch<='z';ch++)
        {
            add(1,1,n,now,ch-'a'+1);
            if(!(get(1,1,n,now-d+1,now)||get(1,1,n,now-d-1+1,now)))
            {
                s[now]=ch;
                break;
            }
        }
        now++;
    }
    puts(s+1);
}
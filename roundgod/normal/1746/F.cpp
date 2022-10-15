#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
int n,q,a[MAXN];
mt19937_64 wcy(time(NULL));
unordered_map<int,ull> umap;
int bit[60][2*MAXN+1];
int sum(int id,int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[id][i];
        i-=i&-i;
    }
    return s;
}
void add(int id,int i,int x)
{
    while(i<=n)
    {
        bit[id][i]+=x;
        i+=i&-i;
    }
}
void add_val(int pos)
{
    int x=a[pos];
    if(umap.find(x)==umap.end())
    {
        ll y=wcy();
        umap[x]=y;
    }
    ull y=umap[x];
    for(int i=0;i<60;i++)
        if((y>>i)&1)
            add(i,pos,1);
}
void dec_val(int pos)
{
    int x=a[pos];
    ull y=umap[x];
    for(int i=0;i<60;i++)
        if((y>>i)&1)
            add(i,pos,-1);
}
int query(int l,int r,int k)
{
    for(int i=0;i<60;i++)
        if((sum(i,r)-sum(i,l-1))%k) return 0;
    return 1;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        add_val(i);
    }
    for(int i=0;i<q;i++)
    {
        int type,pos,x,l,r,k;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d",&pos,&x);
            dec_val(pos); a[pos]=x; add_val(pos);
        }
        else
        {
            scanf("%d%d%d",&l,&r,&k);
            if(query(l,r,k)) puts("YES"); else puts("NO");
        }
    }
    return 0;
}
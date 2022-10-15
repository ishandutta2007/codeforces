#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k,a[MAXN],ans,w,st[MAXN];
int bas[MAXN],res[MAXN],pari[MAXN];
char str[MAXN];
vector<P> eq,neq,eeq,eneq;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int p[MAXN],r[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
        pari[i]=0;
    }
}
P find(int x)
{
    if(p[x]==x) return P(x,0);
    P tmp=find(p[x]);
    pari[x]^=tmp.S; p[x]=tmp.F;
    return P(p[x],pari[x]);
}
void unite(int u,int v,int b)
{
    p[v]=u; pari[v]=b;
}
bool _union(int u,int v,int b)
{
    int pp=find(u).S,qq=find(v).S;
    if(p[u]==p[v])
    {
        if(b^pp^qq) return 0; else return 1;
    }
    unite(p[u],p[v],b^pp^qq); w--;
    return 1;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int solve()
{
    w=n;
    init(n);
    for(auto p:eq) if(!_union(p.F,p.S,0)) return 0;
    for(auto p:eeq) if(!_union(p.F,p.S,0)) return 0;
    for(auto p:neq) if(!_union(p.F,p.S,1)) return 0;
    for(auto p:eneq) if(!_union(p.F,p.S,1)) return 0;
    return pow_mod(2,w-1);
}
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    if(str[n]=='1')
    {
        puts("0");
        return 0;
    }
    int l=1,r=n;
    int cnt=0;
    while(l<r)
    {
        if(str[l]=='?'&&str[r]=='?') cnt++;
        if(str[l]!='?'&&str[r]!='?')
        {
            if(str[l]==str[r])
            {
                eq.push_back(P(l,r));
            }   
            else
            {
                neq.push_back(P(l,r));
            }
        }
        l++; r--;
        if(l==r&&str[l]=='?') cnt++;
    }
    for(int i=n;i>=2;i--)
    {
        eeq.clear(); eneq.clear();
        memset(st,-1,sizeof(st));
        for(int j=2;j<i;j++) eeq.push_back(P(j-1,j));
        eneq.push_back(P(i-1,i));
        int l=i,r=n;
        while(r>l)
        {
            eeq.push_back(P(l,r));
            l++; r--;
        } 
        int x=solve();
        add(ans,x);
    }
    ans=1LL*ans*pow_mod(2,cnt)%MOD;
    printf("%d\n",ans);
    return 0;
}
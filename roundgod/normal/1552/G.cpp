#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,tot;
int st[MAXN];
bool f;
vector<int> q[MAXN];
ll m[MAXN][MAXN];
set<ll> masks;
void dfs(int now,ll mask,ll submask)
{
    if(now==k)
    {
        if(mask!=(1ll<<n)-1) f=false;
        else if(!masks.count(submask)) f=false;
        return;
    }
    int sz=(int)q[now].size();
    ll inter=m[now][sz]&(~mask);
    ll ones=m[now][sz]&(submask);
    int lb=__builtin_popcountll(ones),rb=lb+__builtin_popcountll(inter);
    for(int i=lb;i<=rb;i++)
        dfs(now+1,mask|inter,(submask&(~m[now][sz]))|m[now][i]);
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        m[i][0]=0;
        for(int j=0;j<x;j++)
        {
            int y;
            scanf("%d",&y);
            q[i].push_back(y);
            m[i][j+1]=m[i][j]|(1LL<<(y-1));
        }   
    }
    if(n==1)
    {
        puts("ACCEPTED");
        return 0;
    }
    ll mm=0; masks.insert(mm);
    for(int i=0;i<n;i++)
    {
        mm|=(1ll<<i);
        masks.insert(mm);
    }
    f=true;
    dfs(0,0,0);
    if(f) puts("ACCEPTED"); else puts("REJECTED");
    return 0;
}
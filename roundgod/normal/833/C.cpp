#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll L,R,ans;
vector<ll> res;
vector<int> l,r;
int cnt1[10],cnt2[10];
bool dfs2(int now,int rem,int lflag,int rflag)
{
    if((int)l.size()-now<rem) return false;
    if(lflag&&rflag) return true;
    if(now==(int)l.size()) return true;
    for(int i=(lflag?0:l[now]);i<=(rflag?9:r[now]);i++)
    {
        if(cnt2[i]==cnt1[i]) continue;
        cnt2[i]++;
        if(dfs2(now+1,rem-(i!=0),lflag|(i>l[now]),rflag|(i<r[now]))) return true;
        cnt2[i]--;
    }
    return false;
}

void dfs(int cur,int sum)
{
    if(cur==10)
    {
        memset(cnt2,0,sizeof(cnt2));
        if(sum) ans+=dfs2(0,sum,0,0);
        return;
    }
    for(int i=0;sum+i<=(int)l.size();i++)
    {
        cnt1[cur]=i;
        dfs(cur+1,sum+i);
        cnt1[cur]=0;
    }
}
int main()
{
    scanf("%lld%lld",&L,&R);
    ll tmpl=L;
    while(tmpl)
    {
        l.push_back(tmpl%10);
        tmpl/=10;
    }
    ll tmpr=R;
    while(tmpr)
    {
        r.push_back(tmpr%10);
        tmpr/=10;
    }
    while(l.size()<r.size()) l.push_back(0);
    reverse(l.begin(),l.end()); reverse(r.begin(),r.end());
    cnt1[0]=INF;
    ans=0;
    dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}
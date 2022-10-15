#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define y1 asxdkodas
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,k;
int a[MAXN];
int cnt[MAXN];
priority_queue<P,vector<P>,greater<P> >pque;
ll calc(int x,int pieces)
{
    int num=x/pieces;
    return 1LL*(num+1)*(num+1)*(x%pieces)+1LL*num*num*(pieces-x%pieces);
}
int main()
{
    scanf("%d%d",&n,&k);
    ll ans=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        ans+=1LL*a[i]*a[i];
        cnt[i]=1;
        if(a[i]>cnt[i]) pque.push(P(calc(a[i],cnt[i]+1)-calc(a[i],cnt[i]),i));
    }
    for(int i=0;i<k-n;i++)
    {
        P p=pque.top();
        pque.pop();
        ans+=p.F;
        int id=p.S;
        cnt[id]++;
        if(a[id]>cnt[id]) pque.push(P(calc(a[id],cnt[id]+1)-calc(a[id],cnt[id]),id));
    }
    printf("%lld\n",ans);

    return 0;
}
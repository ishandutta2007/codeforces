#include<bits/stdc++.h>
#define MAXN 200305
using namespace std;
typedef long long ll;
ll n;
ll ans,sum;
priority_queue<ll, vector<ll>, greater<ll> > que;
int main()
{
    scanf("%I64d",&n);
    if(n==1)
    {
        printf("0\n");
        return 0;
    }
    ans=0;
    for(ll i=0;i<n;i++)
    {
        ll x;
        scanf("%I64d",&x);
        que.push(x);
    }
    if(que.size()%2==0&&n>3)
    {
        ans+=que.top();
        que.pop();
        ans+=que.top();
        que.pop();
        que.push(ans);
    }
    while(que.size()>3)
    {
        ll x=0;
        x+=que.top();
        que.pop();
        x+=que.top();
        que.pop();
        x+=que.top();
        que.pop();
        ans+=x;
        que.push(x);
    }
    while(que.size())
    {
        ans+=que.top();
        que.pop();
    }
    printf("%I64d\n",ans);
    return 0;
}
/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-04 16:37:46
 ************************************************************************/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
set<ll> s;
ll n,x;
int main()
{
    scanf("%I64d",&n);
    for(ll i=0;i<n;i++)
    {
        scanf("%I64d",&x);
        s.insert(x);
    }
    ll ans=1,dd=0,x=0;
    bool f=true;
    for(ll d=1;d<=2000000000;d<<=1)
    {
        if(!f) break;
        for(auto it=s.begin();it!=s.end();it++)
        {
            ll num=*it;
            if(s.count(num+d)&&s.count(num-d))
            {
                dd=d;x=num;f=false;ans=3;break;
            }
            if(s.count(num+d))
            {
                dd=d;x=num;ans=2;
            }
        }
    }
    if(ans==1) printf("%I64d\n%I64d\n",ans,*(s.begin()));
    else if(ans==2) printf("%I64d\n%I64d %I64d\n",ans,x,x+dd);   
    else printf("%I64d\n%I64d %I64d %I64d\n",ans,x-dd,x,x+dd);
    return 0;
}
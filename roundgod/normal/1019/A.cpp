/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-11 21:36:48
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,p[MAXN],c[MAXN],cc[MAXN];
multiset<ll> s[MAXN];
multiset<ll> tot;
int main()
{
    scanf("%lld%lld",&n,&m);
    memset(cc,0,sizeof(cc));
    bool f=false;
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld%lld",&p[i],&c[i]);
        cc[p[i]]++;
        s[p[i]].insert(c[i]);
        if(p[i]!=1) tot.insert(c[i]);
    }
    for(ll i=2;i<=m;i++) if(cc[i]>=cc[1]) f=true;
    if(!f) {puts("0"); return 0;}
    ll ans=INF;
    ll res=0,cnt=cc[1];
    for(ll i=n/2+1;i>=max(cc[1],1LL);i--)
    {
        for(ll j=2;j<=m;j++)
        {
            while((ll)s[j].size()>=i) 
            {
                res+=*s[j].begin();
                tot.erase(tot.find(*s[j].begin()));
                s[j].erase(s[j].begin());
                cnt++;
            }
        }
        vector<ll> save;
        save.clear();
        while(cnt<i)
        {
            cnt++;
            res+=*tot.begin();
            save.push_back(*tot.begin());
            tot.erase(tot.begin());
        }
        ans=min(ans,res);
        for(ll j=0;j<(int)save.size();j++)
        {
            cnt--;
            tot.insert(save[j]);
            res-=save[j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
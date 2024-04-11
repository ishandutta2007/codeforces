/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-29 09:46:54
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
typedef pair<ll,ll> P;
ll n,q;
vector<ll> v;
vector<P> p[MAXN];
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
struct query
{
    ll type,x,y;
}a[MAXN];
map<P,ll> mp1,mp2;
int main()
{
    scanf("%lld",&q);
    for(ll i=0;i<q;i++) 
    {
        scanf("%lld%lld%lld",&a[i].type,&a[i].x,&a[i].y);
        if(a[i].type==3)
        {
            ll g=gcd(a[i].x,a[i].y);
            a[i].x/=g;a[i].y/=g;
        }
        v.push_back(a[i].x*a[i].x+a[i].y*a[i].y);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(ll i=0;i<q;i++)
    {
        if(a[i].type==3) 
        {
            printf("%lld\n",n-mp1[P(a[i].x,a[i].y)]-mp2[P(a[i].x,a[i].y)]*2);
        }
        else
        {
            ll sgn=(a[i].type==1)?1:0;
            ll cur=a[i].x*a[i].x+a[i].y*a[i].y;
            ll id=lower_bound(v.begin(),v.end(),cur)-v.begin();
            if(sgn)
            {
                ll curx=a[i].x,cury=a[i].y;
                ll g=gcd(curx,cury);curx/=g;cury/=g;mp1[P(curx,cury)]++;
                for(auto it:p[id])
                {
                    ll nx=it.F+a[i].x,ny=it.S+a[i].y;
                    ll g=gcd(nx,ny);nx/=g;ny/=g;
                    mp2[P(nx,ny)]++;
                }
                p[id].push_back(P(a[i].x,a[i].y));
                n++;
            }
            else
            {
                ll curx=a[i].x,cury=a[i].y;
                ll g=gcd(curx,cury);curx/=g;cury/=g;mp1[P(curx,cury)]--;
                for(auto it:p[id])
                {
                    if(it.F==a[i].x&&it.S==a[i].y) continue;
                    ll nx=it.F+a[i].x,ny=it.S+a[i].y;
                    ll g=gcd(nx,ny);nx/=g;ny/=g;
                    mp2[P(nx,ny)]--;
                }
                for(ll j=0;j<(int)p[id].size();j++)
                {
                    if(p[id][j].F==a[i].x&&p[id][j].S==a[i].y)
                    {
                        p[id].erase(p[id].begin()+j);
                        j--;
                    }
                }
                n--;
            }
        }
    }
    return 0;
}
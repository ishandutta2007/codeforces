/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-10 18:19:50
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str[MAXN];
ll n,lcnt[MAXN],rcnt[MAXN],cnt;
ll tot=0;
int main()
{
    scanf("%lld",&n);
    cnt=0;
    for(ll i=0;i<n;i++)
    {
        cin>>str[i];
        ll l=0,r=0;
        for(ll j=0;j<str[i].size();j++)
        {
            if(str[i][j]=='(') l++;
            else
            {
                r++;
                if(l)
                {
                    l--;r--;
                }
            }
        }
        if(l>0&&r>0) continue;
        if(l==0&&r==0) cnt++;
        else if(r==0) lcnt[l]++; else rcnt[r]++;
    }
    ll ans=cnt*cnt;
    for(ll i=1;i<=300000;i++)
        ans+=lcnt[i]*rcnt[i];
    printf("%lld\n",ans);
    return 0;
}
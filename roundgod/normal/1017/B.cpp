/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-08 22:09:45
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
string s,t;
ll cnt0,cnt1,cnt2,cnt3,ans;
int main()
{
    scanf("%lld",&n);
    cin>>s;cin>>t;
    cnt0=cnt1=cnt2=cnt3=ans=0;
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            if(t[i]=='0') {ans+=cnt1; cnt0++;}
            else {ans+=cnt1-cnt3; cnt0++; cnt2++;}
        }
        else
        {
            if(t[i]=='0') {ans+=cnt0; cnt1++;}
            else {ans+=cnt0-cnt2; cnt1++; cnt3++;}
        }
    }
    printf("%lld\n",ans);
    return 0;
}
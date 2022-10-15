/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-28 17:46:26
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
map<int,int> mp;
int main()
{
    scanf("%d",&n);
    int x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        mp[x]+=y;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        if(mp.find(x)==mp.end()) mp[x]=y; else mp[x]=max(mp[x],y);
    }
    ll ans=0;
    for(auto it=mp.begin();it!=mp.end();it++)
        ans+=it->S;
    printf("%I64d\n",ans);
    return 0;
}
/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-28 16:02:15
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
int n,k;
map<int,int> mp;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            int x;scanf("%d",&x);
            mp[x]++;
        }
        for(auto it:mp)
        {
            if(it.S==n) printf("%d ",it.F);
        }
    }
    return 0;
}
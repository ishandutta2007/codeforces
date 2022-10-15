/*************************************************************************
    > File Name: 2C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-31 01:59:58
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,s[MAXN],c[MAXN];
int main()
{
    int ans=INF;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<n-1;i++)
    {
        int res1=INF,res2=INF;
        for(int j=0;j<i;j++)
            if(s[j]<s[i]) res1=min(res1,c[j]);
        for(int j=i+1;j<n;j++)
            if(s[j]>s[i]) res2=min(res2,c[j]);
        ans=min(ans,res1+res2+c[i]);
    }
    if(ans==INF) puts("-1"); else printf("%d\n",ans);
    return 0;
}
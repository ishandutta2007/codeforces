/*************************************************************************
    > File Name: M.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-09 16:16:08
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
int n,k,a[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=1,cnt=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]) {cnt=1; continue;}
        cnt++; ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}
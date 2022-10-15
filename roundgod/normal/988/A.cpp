/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-04 16:12:30
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
P a[MAXN];
set<int> S;
vector<int> ans;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].F);
        a[i].S=i+1;
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(S.count(a[i].F)==0)
        {
            cnt++;
            S.insert(a[i].F);
            ans.push_back(a[i].S);
        }
    }
    if(cnt>=k)
    {
        puts("YES");
        for(int i=0;i<k;i++)
            printf("%d ",ans[i]);
    }
    else puts("NO");
    return 0;
}
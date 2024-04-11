/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-31 22:32:53
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
int n,m,l[MAXN],r[MAXN];
vector<int> ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d%d",&l[i],&r[i]);
    for(int i=1;i<=m;i++)
    {
        bool f=true;
        for(int j=0;j<n;j++)
        {
            if(i>=l[j]&&i<=r[j]){f=false; break;}
        }
        if(f) ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
    return 0;
}
/*************************************************************************
    > File Name: 2A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-17 17:18:58
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
int n,m,a[MAXN];
bool valid[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        valid[x]=true;
    }
    for(int i=0;i<n;i++)
    {
        if(valid[a[i]]) printf("%d ",a[i]);
    }
    return 0;
}
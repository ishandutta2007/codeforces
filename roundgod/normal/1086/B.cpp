/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-23 21:52:59
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
int n,a[MAXN],deg[MAXN];
vector<int> G[MAXN];
double s;
int main()
{
    scanf("%d%lf",&n,&s);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
        deg[u]++;deg[v]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(deg[i]==1) cnt++;
    printf("%.10lf\n",s*2.0/cnt);
    return 0;
}
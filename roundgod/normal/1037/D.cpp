/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 22:46:57
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
multiset<int> s;
vector<int> G[MAXN];
bool used[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(used,false,sizeof(used));
    bool f=true;
    if(a[1]!=1) f=false;
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        if(!f) break;
        cur++;
        if(i!=1&&!used[a[i]]) {f=false; break;}
        if(i!=1&&cnt[a[i]]!=*s.begin()) {f=false; break;}
        if(i==1) used[a[i]]=true;
        for(int j=0;j<(int)G[a[i]].size();j++)
        {
            int to=G[a[i]][j];
            if(used[to]) continue;
            used[to]=true;
            cnt[to]=cur;
            s.insert(cur);
        }
        if(i!=1) s.erase(s.find(cnt[a[i]]));
    }
    if(f) puts("Yes"); else puts("No");
    return 0;
}
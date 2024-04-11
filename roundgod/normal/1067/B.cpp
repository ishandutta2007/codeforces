/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-25 01:04:06
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
vector<int> G[MAXN];
int deg[MAXN];
vector<int> v;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
        deg[v]++;deg[u]++;
    }
    if(n==1) {puts("No"); return 0;}
    int c=0,id=-1;
    for(int i=1;i<=n;i++) 
    {
        if(deg[i]==2) {puts("No"); return 0;}
        if(deg[i]==3) {c++; id=i;}
    }
    if(c>=2) {puts("No"); return 0;}
    int cur=0,del=0;
    while(del<n)
    {
        v.clear();
        for(int i=1;i<=n;i++) if(deg[i]==1) v.push_back(i);
        if(del==n-1)
        {
            if(c==1)
            {
                if(v[0]!=id) {puts("No"); return 0;}
            }
        }
        set<int> s;
        for(auto it:v)
        {
            del++;
            for(auto id:G[it])
                if(deg[id]>1) {s.insert(id); deg[id]--;}
            deg[it]--;
        }
        for(auto it:s) if(deg[it]!=1) {puts("No"); return 0;}
        for(int i=1;i<=n;i++) if(deg[i]==2) {puts("No"); return 0;}
        cur++;
        if(del==n) 
        {
            if((int)v.size()!=1) {puts("No"); return 0;}
        }
    }
    if(cur==k+1) puts("Yes"); else puts("No");
    return 0;
}
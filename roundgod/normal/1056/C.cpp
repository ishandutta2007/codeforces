/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-28 16:14:16
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
int n,m,t,p[MAXN],fr[MAXN];
set<P> s;
set<int> pr;
int main()
{
    scanf("%d%d",&n,&m);
    memset(fr,-1,sizeof(fr));
    for(int i=1;i<=2*n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        fr[u]=v;fr[v]=u;
        if(p[u]>p[v]) pr.insert(u); else pr.insert(v);
    }
    for(int i=1;i<=2*n;i++)
    {
        if(fr[i]==-1) s.insert(P(p[i],i));
    }
    int cnt=0;
    scanf("%d",&t);
    if(t==1)
    {
        while(pr.size())
        {
            printf("%d\n",*pr.begin());
            pr.erase(pr.begin());
            fflush(stdout);
            int x;scanf("%d",&x);
            if(x==-1) return 0;
        }
        while(s.size())
        {
            auto it=s.end();it--;
            printf("%d\n",it->S);fflush(stdout);
            s.erase(it);
            int x;
            scanf("%d",&x);if(x==-1) return 0;
            s.erase(P(p[x],x));
        }
        return 0;
    }
    else
    {
        while(true)
        {
            int x;
            scanf("%d",&x);
            if(fr[x]==-1) {s.erase(P(p[x],x)); if(x==-1) return 0; break;}
            printf("%d\n",fr[x]);fflush(stdout);
            if(pr.count(x)) pr.erase(x); else pr.erase(fr[x]);
            cnt+=2;
            if(cnt==2*n) return 0;
        }
        while(pr.size())
        {
            printf("%d\n",*pr.begin());
            pr.erase(pr.begin());
            fflush(stdout);
            int x;scanf("%d",&x);if(x==-1) return 0;
        }
        while(s.size())
        {
            auto it=s.end();it--;
            printf("%d\n",it->S);fflush(stdout);
            s.erase(it);
            int x;
            scanf("%d",&x);if(x==-1) return 0;
            s.erase(P(p[x],x));
        }
    }
    return 0;
}
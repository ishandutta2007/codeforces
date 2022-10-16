/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-07 00:05:12
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
map<P,int> mp,mp2;
int add[5];
int cnt[5],deg[5],minval[5],degcnt[5];
int p[5];
void clear() {for(int i=1;i<=4;i++) p[i]=i;}
int find(int x) {if(p[x]==x) return x; else return p[x]=find(p[x]);}
void unite(int x,int y)
{
    x=find(x);y=find(y);
    if(x==y) return;
    p[x]=y;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=4;i++)
        for(int j=i+1;j<=4;j++)
            mp2[P(i,j)]=INF;
    clear();
    for(int i=1;i<=n;i++)
    {
        int x,y,val;
        scanf("%d%d%d",&x,&val,&y);if(x!=y){deg[x]++;deg[y]++;}
        unite(x,y);
        if(x>y) swap(x,y);
        if(x==y) add[x]+=val;
        else {mp[P(x,y)]+=val; mp2[P(x,y)]=min(mp2[P(x,y)],val);}
    }
    int ans=0;
    for(int i=1;i<=4;i++) ans=max(ans,add[i]);
    for(int i=1;i<=4;i++) minval[i]=INF;
    set<int> s; 
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        int q=find((it->F).F);
        cnt[q]+=it->S;
        if(deg[(it->F).F]!=1&&deg[(it->F).S]!=1) minval[q]=min(minval[q],mp2[it->F]);
        else if(deg[(it->F).F]==1) minval[q]=min(minval[q],mp2[it->F]+add[(it->F).F]);
        else if(deg[(it->F).S]==1) minval[q]=min(minval[q],mp2[it->F]+add[(it->F).S]);
        s.insert(q);
    }
    for(int i=1;i<=4;i++) if(deg[i]&1) degcnt[find(i)]++;
    for(int i=1;i<=4;i++) cnt[find(i)]+=add[i];
    for(auto it:s) 
    {
        if(degcnt[it]<=2) ans=max(ans,cnt[it]);
        else ans=max(ans,cnt[it]-minval[it]);
    }
    printf("%d\n",ans);
    return 0;
}
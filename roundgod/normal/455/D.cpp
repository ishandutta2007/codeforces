/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-14 15:58:24
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
int n,q,a[MAXN],num;
const int blocks=300;
int cnt[405][MAXN];
vector<int> arr[405];
void rebuild()
{
    int tot=0;
    for(int i=1;i<=num;i++)
        for(int j=0;j<(int)arr[i].size();j++)
        {
            cnt[i][arr[i][j]]--;
            a[++tot]=arr[i][j];
        }
    assert(tot==n);
    for(int i=1;i<=num;i++) arr[i].clear();
    for(int i=1;i<=num;i++)
    {
        for(int j=(i-1)*blocks+1;j<=min(i*blocks,n);j++)
        {
            arr[i].push_back(a[j]);
            cnt[i][a[j]]++;
        }
    }
}
int del(int pos)
{
    int v;
    for(int i=1;i<=num;i++)
    {
        if((int)arr[i].size()<pos)
        {
            pos-=(int)arr[i].size();
            continue;
        }
        v=arr[i][pos-1];
        cnt[i][v]--;
        arr[i].erase(arr[i].begin()+pos-1);
        break;
    }
    return v;
}
void insert(int pos,int v)
{
    for(int i=1;i<=num;i++)
    {
        if((int)arr[i].size()<pos)
        {
            pos-=(int)arr[i].size();
            continue;
        }
        cnt[i][v]++;
        arr[i].insert(arr[i].begin()+pos,v);
        break;
    }
}
int query(int l,int r,int k)
{
    int now=1,ans=0;
    for(int i=1;i<=num;i++)
    {
        if(now>r) break;
        if(now>=l&&now+(int)arr[i].size()-1<=r)
        {
            ans+=cnt[i][k];
            now+=(int)arr[i].size();
            continue;
        }
        if(now+(int)arr[i].size()-1<l) {now+=(int)arr[i].size(); continue;}
        for(int j=0;j<(int)arr[i].size();j++)
        {
            if(now>=l&&now<=r&&arr[i][j]==k) ans++;
            now++;
        }
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    num=(n-1)/blocks+1;
    for(int i=1;i<=num;i++)
    {
        for(int j=(i-1)*blocks+1;j<=min(i*blocks,n);j++)
        {
            arr[i].push_back(a[j]);
            cnt[i][a[j]]++;
        }
    }
    scanf("%d",&q);
    int t,l,r,k,lastans=0;
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d%d",&l,&r);
            l=(l+lastans-1)%n+1;r=(r+lastans-1)%n+1;
            if(l>r) swap(l,r);
            int v=del(r);
            insert(l-1,v);
        }
        else if(t==2)
        {
            scanf("%d%d%d",&l,&r,&k);
            l=(l+lastans-1)%n+1;r=(r+lastans-1)%n+1;k=(k+lastans-1)%n+1;
            if(l>r) swap(l,r);
            lastans=query(l,r,k);
            printf("%d\n",lastans);
        }
        if(i%blocks==0) rebuild();
    }
    return 0;
}
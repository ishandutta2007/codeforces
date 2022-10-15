#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
struct node
{
    int x,l,r;
};
bool cmp(node p,node q)
{
    return p.x<q.x;
}
bool cmp2(node p,node q)
{
    return p.r<q.r;
}
vector<node> row,col;
int bit[MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
vector<P> ed;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        a+=5001; b+=5001; c+=5001; d+=5001;
        if(a==c) col.push_back((node){a,min(b,d),max(b,d)});
        else row.push_back((node){b,min(a,c),max(a,c)});
    }
    sort(col.begin(),col.end(),cmp2);
    sort(row.begin(),row.end(),cmp);
    ll ans=0;
    for(int i=0;i<(int)row.size();i++)
    {
        int l=row[i].l,r=row[i].r,h=row[i].x;
        ed.clear();
        for(int j=0;j<(int)col.size();j++) 
        {
            if(col[j].l>h||col[j].r<h) continue;
            ed.push_back(P(col[j].r+1,col[j].x));
            add(col[j].x,1);
        }
        int now=0;
        for(int j=i+1;j<(int)row.size();j++)
        {
            if(row[j].x==h) continue;
            while(now<(int)ed.size()&&ed[now].F<=row[j].x) add(ed[now].S,-1),now++;
            int lb=max(l,row[j].l);
            int rb=min(r,row[j].r);
            if(lb>rb) continue;
            int x=sum(rb)-sum(lb-1);
            ans+=x*(x-1)/2;
        }
        while(now<(int)ed.size()) add(ed[now].S,-1),now++;
    }
    printf("%lld\n",ans);
    return 0;
}
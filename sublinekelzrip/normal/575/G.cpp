#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
struct a
{
    int len,root,n,hv;
};
int n,lch[10000010],rch[10000010],o=0;
long long tree[10000010];
int grea(int i,int j)
{
    if(tree[i]==tree[j])
        return 0;
    int l=1,r=n;
    while(l!=r)
    {
        int mid=(l+r)>>1;
        if(tree[lch[i]]!=tree[lch[j]])
        {
            i=lch[i];
            j=lch[j];
            r=mid;
        }
        else
        {
            i=rch[i];
            j=rch[j];
            l=1+mid;
        }
    }
    if(tree[i]>tree[j])
        return 1;
    else
        return -1;
}           
bool operator <(const a& x,const a& y)
{
    if(x.len>y.len)
        return 1;
    if(x.len<y.len)
        return 0;
    int now=grea(x.root,y.root);
    if(now==1)
        return 1;
    else        
        if(now==-1)
            return 0;
      else
          if(x.hv!=y.hv)
            return x.hv>y.hv;
        else
            return x.n<y.n;
}
int insert(int i,int l,int r,int j,int k)
{
    o++;
    int t=o;
    if(l==r)
    {
        tree[t]=k;
        return t;
    }
    lch[t]=lch[i];
    rch[t]=rch[i];
    int mid=(l+r)>>1;
    if(j>mid)
        rch[t]=insert(rch[t],mid+1,r,j,k);
    else
        lch[t]=insert(lch[t],l,mid,j,k);
    tree[t]=tree[lch[t]]*59+tree[rch[t]]*37+(tree[lch[t]]^tree[rch[t]]);
    return t;
}
priority_queue<a> q;
struct Bian
{
    int s,t,v,last;
}bian[400010];
int last[100010],maxbian=0;
void addbian(int s,int t,int v)
{
    maxbian++;
    bian[maxbian].s=s;
    bian[maxbian].t=t;
    bian[maxbian].v=v;
    bian[maxbian].last=last[s];
    last[s]=maxbian;
}
a d[100010],t4,t5;
int v[100010],pre[100010],dpre[100010];
stack<int> s;
int main()
{
    int m,t1,t2,t3,n1;
    cin>>n>>m;
    for(n1=1;n1<=m;n1++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        addbian(t1+1,t2+1,t3);
        addbian(t2+1,t1+1,t3);
    }
    for(n1=1;n1<n;n1++)
        d[n1].len=inf;
    for(n1=1;n1<=n;n1++)
        d[n1].n=n1;
    q.push(d[n]);
    while(!q.empty())
    {
        t4=q.top();
        q.pop();
        if(v[t4.n])
            continue;
        v[t4.n]=1;
        for(t2=last[t4.n];t2;t2=bian[t2].last)
        {
            if(bian[t2].v==0&&d[t4.n].len==0)
            {
                t5=d[t4.n];
                t5.hv++;
            }
            else
            {
                t5=d[t4.n];
                t5.hv++;
                t5.len++;
                t5.root=insert(t5.root,1,n,t5.len,bian[t2].v);
            }
            if(d[bian[t2].t]<t5&&v[bian[t2].t]==0)
            {
                d[bian[t2].t]=t5;
                d[bian[t2].t].n=bian[t2].t;
                pre[bian[t2].t]=t4.n;
                dpre[bian[t2].t]=bian[t2].v;
                q.push(d[bian[t2].t]);
            }
        }
    }
    int i=1;
    while(i!=n)
    {
        s.push(dpre[i]);
        i=pre[i];
    }
    int ans=s.size()+1;
    while(!s.empty()&&s.top()==0)
        s.pop();
    if(s.empty())
        s.push(0);
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    cout<<ans<<endl;
    cout<<0<<' ';
    i=1;
    while(i!=n)
    {
    //  s.insert(dpre[i]);
        i=pre[i];
        cout<<i-1<<' ';
    }   
}
#include <bits/stdc++.h>
using namespace std;
int mn[34][1000000];
int mx[34][1000000];
void upd(int id,int x,int l,int r,int v,int val)
{
    if (v>r || v<l)return;
    if (l==r)mn[id][x]=mx[id][x]=val;
    else
    {
        int mid = (l+r)/2;
        if (v<=mid)
            upd(id,x*2,l,mid,v,val);
        else
            upd(id,x*2+1,mid+1,r,v,val);
        mn[id][x]=min(mn[id][x*2],mn[id][x*2+1]);
        mx[id][x]=max(mx[id][x*2],mx[id][x*2+1]);
    }
}
int getMin(int id,int x,int l,int r,int s,int e)
{
    if (l>e || r<s)return 1e9;
    if (l>=s && r<=e)return mn[id][x];
    int mid = (l+r)/2;
    int ret = 1e9;
    if (s<=mid)
        ret=min(ret,getMin(id,x*2,l,mid,s,e));
    if (e>mid)
        ret=min(ret,getMin(id,x*2+1,mid+1,r,s,e));
    return ret;
}
int getMax(int id,int x,int l,int r,int s,int e)
{
    if (l>e || r<s)return -1e9;
    if (l>=s && r<=e)return mx[id][x];
    int mid = (l+r)/2;
    int ret = -1e9;
    if (s<=mid)
        ret=max(ret,getMax(id,x*2,l,mid,s,e));
    if (e>mid)
        ret=max(ret,getMax(id,x*2+1,mid+1,r,s,e));
    return ret;
}
vector<int> masks;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int m = (1<<k)-1;
    for (int i=0;i<=m;i++)
    {
        if (m-i<i)continue;
        masks.push_back(i);
    }
    for (int i=1;i<=n;i++)
    {
        int b[10];
        for (int j=0;j<k;j++)
        {
            scanf("%d",&b[j]);
        }
        for (int j=0;j<masks.size();j++)
        {
            int cur=0;
            for (int x=0;x<k;x++)
            {
                if (masks[j]&(1<<x))
                    cur+=b[x];
                else
                    cur-=b[x];
            }
            upd(j,1,1,n,i,cur);
        }
    }
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;i++)
    {
        int typ;
        scanf("%d",&typ);
        if (typ==1)
        {
            int id;
            scanf("%d",&id);
            int b[10];
            for (int j=0;j<k;j++)
            {
                scanf("%d",&b[j]);
                for (int j=0;j<masks.size();j++)
                {
                    int cur=0;
                    for (int x=0;x<k;x++)
                    {
                        if (masks[j]&(1<<x))
                            cur+=b[x];
                        else
                            cur-=b[x];
                    }
                    upd(j,1,1,n,id,cur);
                }
            }
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int ret=0;
            for (int j=0;j<masks.size();j++)
                ret=max(ret,getMax(j,1,1,n,l,r)-getMin(j,1,1,n,l,r));
            printf("%d\n",ret);
        }
    }
}
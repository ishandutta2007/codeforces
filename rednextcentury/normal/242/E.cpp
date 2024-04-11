# include <bits/stdc++.h>
using namespace std;
int tree[22][1000000];
bool lazy[22][1000000];
bool a[1000000][22];
void lzy(int i,int x,int l,int r)
{
    int len=r-l+1;
    if (lazy[i][x])
    {
        tree[i][x]=len-tree[i][x];
        lazy[i][x]=0;
        lazy[i][x*2]^=1;
        lazy[i][x*2+1]^=1;
    }
}
void build(int i,int x,int l,int r)
{
    if (l==r)
        tree[i][x]=a[l][i];
    else
    {
        build(i,x*2,l,(l+r)/2);
        build(i,x*2+1,(l+r)/2+1,r);
        tree[i][x]=tree[i][x*2]+tree[i][x*2+1];
    }
}
long long query(int i,int x,int l,int r,int s,int e)
{
    lzy(i,x,l,r);
    if (s>r || e<l)
        return 0;
    else if (l>=s && r<=e)
    {
        lzy(i,x,l,r);
        return tree[i][x];
    }
    else
        return query(i,x*2,l,(l+r)/2,s,e)+query(i,x*2+1,(l+r)/2+1,r,s,e);
}
void upd(int i,int x,int l,int r,int s,int e)
{
    lzy(i,x,l,r);
    if (s>r || e<l)
        return;
    else if (l>=s && r<=e)
    {
        lazy[i][x]^=1;
        lzy(i,x,l,r);
    }
    else
    {
        upd(i,x*2,l,(l+r)/2,s,e),upd(i,x*2+1,(l+r)/2+1,r,s,e);
        tree[i][x]=tree[i][x*2]+tree[i][x*2+1];
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        for (int j=21;j>=0;j--)
        {
            if (x>=(1<<j))
                x-=(1<<j),a[i][j]=1;
        }
    }
    for (int i=0;i<=21;i++) build(i,1,0,n-1);
    int m;
    cin>>m;
    while(m--)
    {
        int t,l,r,x;
        cin>>t>>l>>r;
        l--,r--;
        if (t==1)
        {
            long long ans=0;
            for (int i=0;i<=21;i++)
                ans+=(1LL<<i)*query(i,1,0,n-1,l,r);
            cout<<ans<<endl;
        }
        else
        {
            cin>>x;
            for (int j=21;j>=0;j--)
            {
                if (x>=(1<<j))
                    x-=(1<<j),upd(j,1,0,n-1,l,r);
            }
        }
    }
}
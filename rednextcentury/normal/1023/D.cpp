#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tree[2000000];
int a[1000000];
void build(int x,int l,int r)
{
    if (l==r)
    {
        tree[x]=l;
    }
    else
    {
        build(x*2,l,(l+r)/2);
        build(x*2+1,(l+r)/2+1,r);
        if (a[tree[x*2]]<a[tree[x*2+1]])
            tree[x]=tree[x*2];
        else
            tree[x]=tree[x*2+1];
    }
}
int query(int x,int l,int r,int s,int e)
{
    if (e<l || s>r)
        return 0;
    if (l>=s && r<=e)
        return tree[x];
    int p1 = query(x*2,l,(l+r)/2,s,e);
    int p2 = query(x*2+1,(l+r)/2+1,r,s,e);
    if (p1==0)return p2;
    if (p2==0)return p1;
    if (a[p1]<a[p2])return p1;
    return p2;
}
void upd(int x,int l,int r,int v)
{
    if (v>l || v>r)
        return;
    if (l==r)
    {
        tree[x]=l;
    }
    else
    {
        upd(x*2,l,(l+r)/2,v);
        upd(x*2+1,(l+r)/2+1,r,v);
        if (a[tree[x*2]]<a[tree[x*2+1]])
            tree[x]=tree[x*2];
        else
            tree[x]=tree[x*2+1];
    }
}
int mn[1000000];
int mx[1000000];
int num=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    for (int i=1;i<=n;i++)
    {
        if (a[i]==q)num++;
        if (mn[a[i]]==0)
            mn[a[i]]=i;
        mx[a[i]]=i;
    }
    for (int i=q;i>=1;i--)
    {
        if (mn[i]==0)continue;
        while(1)
        {
            int p = query(1,1,n,mn[i],mx[i]);
            if (a[p]==0)
            {
                if (num==0)
                    a[p]=q,num++;
                else
                    a[p]=i;
                upd(1,1,n,p);
            }
            else
            {
                if (a[p]<i)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
                break;
            }
        }

    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]==0 && num==0)
            a[i]=q,num++;
    }
    if (num==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;

    for (int i=2;i<=n;i++)
    {
        if (a[i]==0)
            a[i]=a[i-1];
    }
    for (int i=n-1;i>=1;i--)
    {
        if (a[i]==0)
            a[i]=a[i+1];
    }
    for (int i=n;i>=1;i--)
    {
        if (a[i]==0)
            a[i]=q;
    }
    for (int i=1;i<=n;i++)
    {

        cout<<a[i]<<' ';

    }
    cout<<endl;
}
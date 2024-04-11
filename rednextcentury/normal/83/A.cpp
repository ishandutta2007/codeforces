# include<iostream>
# include<set>
#include <ios>
# include <cstdio>
using namespace std;
#define mid (l+r)/2
int tree[1000000][2];
int a[1000000];
void build(int x,int l,int r)
{
    if (l==r)
        tree[x][0]=tree[x][1]=a[l];
    else
    {
        build(2*x,l,mid);
        build(2*x+1,mid+1,r);
        tree[x][0]=min(tree[2*x][0],tree[2*x+1][0]);
        tree[x][1]=max(tree[2*x][1],tree[2*x+1][1]);
    }
}
int getmin(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)
        return 1000000001;
    else if (l>=s && r<=e)
        return tree[x][0];
    else
    {
        return min(getmin(x*2,l,mid,s,e),getmin(x*2+1,mid+1,r,s,e));
    }
}
int getmax(int x,int l,int r,int s,int e)
{
    if (l>e || r<s)
        return -1000000001;
    else if (l>=s && r<=e)
        return tree[x][1];
    else
    {
        return max(getmax(x*2,l,mid,s,e),getmax(x*2+1,mid+1,r,s,e));
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    build(1,1,n);
    int i=1,j=1;
    long long ans=0;
    int mn=a[1],mx=a[1];
    while(i<=n)
    {
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
        if (mn==mx)
        {
            ans+=i-j+1;
        }
        else
        {
            while(mn!=mx)
            {
                j++;
                mn=getmin(1,1,n,j,i);
                mx=getmax(1,1,n,j,i);
            }
            ans++;
        }
        i++;
    }
    cout<<ans<<endl;
}
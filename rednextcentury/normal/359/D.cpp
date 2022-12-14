#include<stdio.h>
#include<algorithm>
# include <iostream>
# include <assert.h>
# include <vector>
using namespace std;
int gcd(int a,int b)
{
    if (a%b==0) return b;
    if (b%a==0) return a;
    return gcd(b%a,a);
}
pair<int,int> tree[4000000];
int a[1000000];
pair<int,int> Merge(pair<int,int> l,pair<int,int> r)
{
    return make_pair(gcd(l.first,r.first),min(l.second,r.second));
}
void build(int x,int l,int r)
{
    if (l==r)
        tree[x]=make_pair(a[l],a[l]);
    else
    {
        build(x*2,l,(l+r)/2);
        build(x*2+1,(l+r)/2+1,r);
        tree[x]=Merge(tree[x*2],tree[x*2+1]);
    }
}
pair<int,int> query(int x,int l,int r,int s,int e)
{
    if (l>e || s>r)
        return make_pair(-1,-1);
    if (l>=s && r<=e)
        return tree[x];
    pair<int,int> p1=query(x*2,l,(l+r)/2,s,e);
    pair<int,int> p2=query(x*2+1,(l+r)/2+1,r,s,e);
    if (p1.first==-1)
        return p2;
    else if (p2.first==-1)
        return p1;
    else
        return Merge(p1,p2);
}
int n;
vector<int> ret;
int num;
int mx;
bool check(int m)
{
    for (int l=0;l<n;l++)
    {
        int r=l+m-1;
        if (r>=n)
            break;
        pair<int,int> p=query(1,0,n-1,l,r);
        if (p.first==p.second)
        {
            if (mx!=m)
                mx=m,ret.clear(),num=0;
            ret.push_back(l+1);
            num++;
        }
    }
    if (mx==m)
        return 1;
    return 0;
}
void bs(int l,int r)
{
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
            l=mid+1;
        else
            r=mid-1;
    }
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    build(1,0,n-1);
    bs(1,n);
    cout<<num<<" "<<mx-1<<endl;
    for (int i=0;i<ret.size();i++)
        cout<<ret[i]<<" ";
    cout<<endl;
}
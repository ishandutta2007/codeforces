#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define mid (l+r)/2
using namespace std;
int a[100001];
int b[100001][32];
int tree[6*100000];
void build(int x,int l,int r)
{
    if (l==r)
    {
        tree[x]=a[l];
    }
    else
    {
        build(2*x,l,mid);
        build(2*x+1,mid+1,r);
        tree[x]=tree[x*2]&tree[x*2+1];
    }
}
int query(int x,int l,int r,int s,int e)
{
    if (s>r || e<l)
        return -1;
    if (l>=s && r<=e)
        return tree[x];
    else
    {
        int p1=query(x*2,l,mid,s,e);
        int p2=query(x*2+1,mid+1,r,s,e);
        if (p1==-1)
            return p2;
        if (p2==-1)
            return p1;
        return p1&p2;
    }
}
int pows[100];
void add(int l,int r,int q)
{
    int h=q;
    for (int i=30;i>=0;i--)
    {
        if (h>=pows[i])
        {
            h-=pows[i];
            b[l-1][i]++;
            b[r][i]--;
        }
    }
}
int l[1000000];
int r[1000000];
int q[1000000];
int main()
{
    pows[0]=1;
    for (int i=1;i<=30;i++)
        pows[i]=2*pows[i-1];
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        cin>>l[i]>>r[i]>>q[i];
        add(l[i],r[i],q[i]);
    }
    int now[40]={0};
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<=30;x++)
        {
            now[x]+=b[i][x];
            if (now[x]>0)
                a[i]+=pows[x];
        }
    }
    build(1,0,n-1);
    for (int i=0;i<m;i++)
    {
        if (query(1,0,n-1,l[i]-1,r[i]-1)!=q[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
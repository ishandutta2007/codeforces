#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
struct node
{
    int val;
    int idx;
};
map<int,int> m;
bool operator<(node a,node b)
{
    return a.val<b.val;
}
node a[10000],b[10000],c[10000];
int main()
{
    int n;
    cin>>n;
    int k=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].val;
        a[i].idx=i+1;
        m[a[i].val]++;
        if (m[a[i].val]>1)
            k++;
        b[i]=a[i];
        c[i]=b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    int i1,i2;
    if (k>=2)
    {

    for (int i=0;i<n-1;i++)
    {
        if (b[i].val==b[i+1].val)
        {
            i1=i;
            i2=i+1;
            swap(b[i],b[i+1]);
        }
    }
    for (int i=0;i<n-1;i++)
    {
        if (c[i].val==c[i+1].val && i!=i1)
        {
            swap(c[i],c[i+1]);
        }
    }
    cout<<"YES"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<a[i].idx<<" ";
    }
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<b[i].idx<<" ";
    }
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<c[i].idx<<" ";
    }
    cout<<endl;
        }
        else
            cout<<"NO"<<endl;
}
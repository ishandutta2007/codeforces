# include <iostream>
# include<algorithm>
#include <stdio.h>
# include <cstdlib>
using namespace std;
struct segment
{
    int s;
    int e;
};
bool comp(segment a,segment b)
{
    if (a.s==b.s)
        return a.e<b.e;
    return a.s<b.s;
}
segment a[100000];
int ret[1000000];
int tot=0;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].s>>a[i].e;
        if (a[i].s>a[i].e)
            swap(a[i].s,a[i].e);
    }
    sort(a,a+n,comp);
    int s=a[0].s;
    int e=a[0].e;
    int ans=1;
    for (int i=1;i<n;i++)
    {
        if (a[i].s>e || a[i].e<s)
        {
            ret[tot++]=e;
            s=a[i].s;
            e=a[i].e;
            ans++;
        }
        else
        {
            s=max(s,a[i].s);
            e=min(e,a[i].e);
        }
    }
    cout<<ans<<endl;
    if (tot<ans)
        ret[tot++]=e;
    for (int i=0;i<tot;i++)
        cout<<ret[i]<<" ";
    cout<<endl;
}
#include <iostream>
#include <map>
#include <string>
# include <stdio.h>
# include <map>
# include <queue>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
struct point
{
    int idx,x;
};
bool comp(point a,point b)
{
    return a.x<b.x;
}
point a[10000];
bool ans[10000];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x;
        a[i].idx=i;
    }
    sort(a,a+n,comp);
    for (int i=0;i<m;i++)
    {
        int u,e;
        cin>>u>>e;
    }
    int c=1;
    for (int i=0;i<n;i++)
    {
        ans[a[i].idx]=c;
        c=1-c;
    }
    for (int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
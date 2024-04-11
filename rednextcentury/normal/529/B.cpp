# include <iostream>
# include <vector>
# include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
struct people
{
    int w;
    int h;
};
bool operator<(people a,people b)
{
    return abs(a.w-a.h)>abs(b.w-b.h);
}
people a[100000];
bool vis[100000];
int main()
{
    int n;
    cin>>n;
    int k=n/2;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].w>>a[i].h;
    }
    sort(a,a+n);
    long long mn=1000000000;
    for (int i=1;i<=1000;i++)
    {
        int used=0;
        long long cur=0;
        for (int j=0;j<n;j++)
        {
            vis[j]=0;
        }
        for (int j=0;j<n;j++)
        {
            if (a[j].w>i && a[j].h>i)
                used=k+1,vis[j]=1;
            else if (a[j].h<=i && a[j].w>i)
            {
                vis[j]=1;
                cur+=a[j].w;
            }
            else if (a[j].h>i && a[j].w<=i)
            {
                vis[j]=1;
                used++;
                cur+=a[j].h;
            }
        }
        if (used>k)
            continue;
        for (int j=0;j<n;j++)
        {
            if (!vis[j])
            {
                if (a[j].w<=a[j].h)
                {
                    cur+=a[j].w;
                }
                else if (used<k)
                {
                    used++;
                    cur+=a[j].h;
                }
                else
                    cur+=a[j].w;
            }
        }
        mn=min(mn,cur*i);
    }
    cout<<mn<<endl;
}
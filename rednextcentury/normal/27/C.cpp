/*# include <iostream>
# include <vector>
using namespace std;
struct ok
{
    long long y,z;
};
struct lady
{
    long long x,y,z;
};
bool operator<(ok a,ok b)
{
    return a.y<b.y;
}
bool operator<(lady a,lady b)
{
    return a.x<b.x;
}

set<ok> a[500001];
long long main()
{
    long long n;
    cin>>n;
    for (long long i=0;i<n-1;i++)
    {
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1);
    cout<<ans<<endl;
}
*/


# include <iostream>
# include <iomanip>
# include <stdio.h>
# include <stack>
#define EPS 1e-9
using namespace std;
int a[1000001];
int mx1[1000001];
int mx2[1000001];
int mn1[1000001];
int mn2[1000001];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mx1[0]=0;
    mn1[0]=0;
    for (int i=1;i<n;i++)
    {
        if (a[i]>a[mx1[i-1]])
            mx1[i]=i;
        else
            mx1[i]=mx1[i-1];
        if (a[i]<a[mn1[i-1]])
            mn1[i]=i;
        else
            mn1[i]=mn1[i-1];
    }
    mn2[n-1]=n-1;
    mx2[n-1]=n-1;
    for (int i=n-2;i>=0;i--)
    {
        if (a[i]>a[mx2[i+1]])
            mx2[i]=i;
        else
            mx2[i]=mx2[i+1];
        if (a[i]<a[mn2[i+1]])
            mn2[i]=i;
        else
            mn2[i]=mn2[i+1];
    }
    for (int i=1;i<n-1;i++)
    {
        if (a[i]>a[mn1[i-1]] && a[i]>a[mn2[i+1]])
        {
            cout<<3<<endl;
            cout<<mn1[i-1]+1<<" "<<i+1<<" "<<mn2[i+1]+1<<endl;
            return 0;
        }
        if (a[i]<a[mx1[i-1]] && a[i]<a[mx2[i+1]])
        {
            cout<<3<<endl;
            cout<<mx1[i-1]+1<<" "<<i+1<<" "<<mx2[i+1]+1<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
}
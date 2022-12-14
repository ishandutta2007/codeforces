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
# include <algorithm>
#define EPS 1e-9
using namespace std;
int main()
{
    int n,m,v;
    cin>>n>>m>>v;
    int mx=(n-2)*(n-3)/2 + n-1;
    int mn=n-1;
    if (m<mn || m>mx)
    {
        cout<<-1<<endl;
        return 0;
    }
    int u=v+1;
    if (u>n)
        u=1;

    cout<<u<<" "<<v<<endl;
    m--;
    for (int i=1;i<=n;i++)
    {
        if (i==u || i==v)
            continue;
        cout<<v<<" "<<i<<endl;
        m--;
    }
    for (int i=1;i<=n;i++)
    {
        if (i==u || i==v)
            continue;
        if (m==0)
            break;
        for (int j=i+1;j<=n;j++)
        {
            if (m==0)
                break;
            if (j==u || j==v)
                continue;
            cout<<i<<" "<<j<<endl;
            m--;
        }
    }
}
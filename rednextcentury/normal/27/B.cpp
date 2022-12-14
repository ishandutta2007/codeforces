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
# include <map>
# include <stdio.h>
# include <algorithm>
using namespace std;
int win[1000000];
int lose[1000000];
bool vis[1000000];
int num[1000000];
int x,y;
int played[1000000];
int main()
{
    int n;
    cin>>n;
    int m=n*(n-1)/2 -1;
    for (int i=0;i<m;i++)
    {
        cin>>win[i]>>lose[i];
        num[win[i]]++;
        played[win[i]]++;
        played[lose[i]]++;
    }
    for (int i=1;i<=n;i++)
        vis[num[i]]=1;
    for (int i=1;i<=n;i++)
    {
        if (played[i]<n-1)
        {
            played[i]++;
            x=i;
            break;
        }
    }
    for (int i=1;i<=n;i++)
        if (played[i]<n-1) played[i]++,y=i;
    if (num[x]>num[y])
        swap(x,y);
    for (int i=0;i<=n;i++)
    {
        if (!vis[i])
        {
            if (num[x]==i-1)
            {
                cout<<x<<" "<<y<<endl;
                return 0;
            }
            else if (num[y]==i-1)
            {
                cout<<y<<" "<<x<<endl;
                return 0;
            }
        }
    }
}
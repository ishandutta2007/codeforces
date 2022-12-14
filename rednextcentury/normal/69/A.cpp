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
int main()
{
    int n;
    cin>>n;
    int a=0,b=0,c=0;
    for (int i=0;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a+=x,b+=y,c+=z;
    }
    if (a==0 && b==0 && c==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
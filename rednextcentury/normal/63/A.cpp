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
string a[100000];
string b[100000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for (int i=0;i<n;i++)
    {
        if (b[i]=="rat")
            cout<<a[i]<<endl;
    }
    for (int i=0;i<n;i++)
    {
        if (b[i]=="child" || b[i]=="woman")
            cout<<a[i]<<endl;
    }
    for (int i=0;i<n;i++)
    {
        if (b[i]=="man")
            cout<<a[i]<<endl;
    }
    for (int i=0;i<n;i++)
    {
        if (b[i]=="captain")
            cout<<a[i]<<endl;
    }
}
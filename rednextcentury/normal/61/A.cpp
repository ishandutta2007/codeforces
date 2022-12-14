/*# include <iostream>
# include <vector>
using namespace std;
struct ok
{
    int y,z;
};
struct lady
{
    int x,y,z;
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
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1);
    cout<<ans<<endl;
}
*/


# include <iostream>
# include <string>
# include <algorithm>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.length();
    for (int i=0;i<n;i++)
    {
        if (a[i]==b[i])
            cout<<0;
        else
            cout<<1;
    }
    cout<<endl;
}
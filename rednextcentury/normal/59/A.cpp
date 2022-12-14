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
    string s;
    cin>>s;
    int n=s.length();
    int l=0,u=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]==tolower(s[i])) l++;
        else u++;
    }
    if (u>l)
    {
        for (int i=0;i<n;i++)
            s[i]=toupper(s[i]);
    }
    else
    {
        for (int i=0;i<n;i++)
            s[i]=tolower(s[i]);
    }
    cout<<s<<endl;
}
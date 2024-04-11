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
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int i=s.length()-1;
    while((s[i]<'a' || s[i]>'z') && (s[i]<'A' || s[i]>'Z'))
        i--;
    if (toupper(s[i])=='A' || toupper(s[i])=='E' || toupper(s[i])=='O' || toupper(s[i])=='U' || toupper(s[i])=='I' || toupper(s[i])=='Y' )
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
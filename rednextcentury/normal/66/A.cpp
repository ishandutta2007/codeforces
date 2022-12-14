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
    string s;
    cin>>s;
    if (s.length()>19 || (s.length()==19 && s>"9223372036854775807"))
        cout<<"BigInteger"<<endl;
    else if (s.length()>10 || (s.length()==10 && s>"2147483647"))
        cout<<"long"<<endl;
    else if (s.length()>5 || (s.length()==5 && s>"32767"))
        cout<<"int"<<endl;
    else if (s.length()>3 || (s.length()==3 && s>"127"))
        cout<<"short"<<endl;
    else
        cout<<"byte"<<endl;
}
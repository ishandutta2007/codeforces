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
    string s;
    cin>>s;
    int n=s.length();
    int num=0;
    if (s[0]=='@' || s[n-1]=='@')
    {
        cout<<"No solution"<<endl;
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        if (s[i]=='@')
            num++;
        if (s[i]=='@' && i+2<n && s[i+2]=='@')
        {
            cout<<"No solution"<<endl;
            return 0;
        }
        if (s[i]=='@' && i+1<n && s[i+1]=='@')
        {
            cout<<"No solution"<<endl;
            return 0;
        }
    }
    if (num==0)
    {
        cout<<"No solution"<<endl;
        return 0;
    }
    int now=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='@' && now<num-1)
            cout<<s[i]<<s[i+1]<<",",i++,now++;
        else if (s[i]=='@' && now==num-1)
            cout<<s[i],now++;
        else
            cout<<s[i];
    }
    cout<<endl;
}
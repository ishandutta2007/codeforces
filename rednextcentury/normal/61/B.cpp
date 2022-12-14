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
    string a1,b1,c1;
    cin>>a1>>b1>>c1;
    string a="",b="",c="";
    int n1=a1.length(),n2=b1.length(),n3=c1.length();
    for (int i=0;i<n1;i++)
        if (a1[i]!=';' && a1[i]!='-' && a1[i]!='_')
            a+=tolower(a1[i]);
    for (int i=0;i<n2;i++)
        if (b1[i]!=';' && b1[i]!='-' && b1[i]!='_')
            b+=tolower(b1[i]);
    for (int i=0;i<n3;i++)
        if (c1[i]!=';' && c1[i]!='-' && c1[i]!='_')
            c+=tolower(c1[i]);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        int m=x.length();
        string y="";
        for (int i=0;i<m;i++)
            if (x[i]!=';' && x[i]!='-' && x[i]!='_')
                y+=tolower(x[i]);
        if (y==a+b+c || y==a+c+b || y==b+c+a || y==b+a+c || y==c+a+b || y==c+b+a)
            cout<<"ACC"<<endl;
        else
            cout<<"WA"<<endl;
    }
}
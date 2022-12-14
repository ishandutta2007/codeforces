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
bool vis[1000000];
int team[1000000][3];
int p[1000000];
int ret[1000000];
int main()
{
    int n;
    cin>>n;
    int h=0;
    for (int i=0;i<3*n;i++)
    {
        cin>>p[i];
    }
    for (int i=0;i<n;i++)
        cin>>team[i][0]>>team[i][1]>>team[i][2];
    int s=0;
    int k;
    cin>>k;
    int tot=0;
    for (int i=0;i<3*n;i++)
    {
        if (i+1!=k)
            ret[h++]=i+1;
    }
    for (int i=0;i<n;i++)
    {
        while(vis[p[s]])
            s++;
        for (int j=0;j<3;j++)
        {

            vis[team[i][j]]=1;
            if (team[i][j]==k)
            {

                if (p[s]==k)
                {
                    for (int x=0;x<=i;x++)
                    {
                        for (int g=0;g<3;g++)
                            if (team[x][g]!=k)
                                ret[tot++]=team[x][g];
                    }
                    int i1=j+1;
                    if (i1>2)
                        i1=0;
                    int i2=j-1;
                    if (i2<0)
                        i2=2;
                    sort(ret,ret+tot);
                    int l=max(team[i][i1],team[i][i2]);
                    for (int x=1;x<=3*n;x++)
                        if (!vis[x] && x!=team[i][2] && x!=team[i][0] && x!=team[i][1])
                            ret[tot++]=x;

                    for (int x=tot-1;x>=0;x--)
                    {
                        if (ret[x]==l)
                            sort(ret+x+1,ret+tot);
                    }
                    for (int x=0;x<3*n-1;x++)
                        cout<<ret[x]<<" ";
                    cout<<endl;
                    return 0;
                }
            }
        }
    }
    for (int i=0;i<3*n-1;i++)
        cout<<ret[i]<<" ";
    cout<<endl;
}
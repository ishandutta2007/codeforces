
# include <iostream>
# include <string>
# include <map>
#define EPS 1e-9
using namespace std;
bool adj[101][101];
int a[101];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u][v]=adj[v][u]=1;
    }
    int ans=100000000;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            for (int k=j+1;k<n;k++)
            {
                if (adj[i][j]==1 && adj[j][k]==1 && adj[i][k]==1)
                    ans=min(ans,a[i]+a[j]+a[k]);
            }
        }
    }
    if (ans==100000000)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}
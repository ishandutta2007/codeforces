#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
long long adj[501][501];
bool add[1000000];
long long a[501];
long long ret[1000];
int main()
{
    long long n;
    cin>>n;
    for (long long i=0;i<n;i++)
    {
        for (long long j=0;j<n;j++)
        {
            cin>>adj[i][j];

        }
    }
    for (long long i=n-1;i>=0;i--)
        cin>>a[i];
    for (long long i=0;i<n;i++)
    {
        long long v=a[i]-1;
        add[v]=1;
        for (long long u=0;u<n;u++)
        {
            for (long long k=0;k<n;k++)
            {
                adj[u][k]=min(adj[u][v]+adj[v][k],adj[u][k]);
            }
        }
        long long ans=0;
        for (long long j=0;j<n;j++)
            for (long long k=0;k<n;k++)
                if (add[j] && add[k])
                    ans+=adj[j][k];
        ret[i]=ans;
    }
    for (long long i=n-1;i>=0;i--)
        cout<<ret[i]<<" ";
    cout<<endl;
}